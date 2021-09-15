/****************************************************************************
 *
 * <:copyright-BRCM:2015:DUAL/GPL:standard
 * 
 *    Copyright (c) 2015 Broadcom 
 *    All Rights Reserved
 * 
 * Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed
 * to you under the terms of the GNU General Public License version 2
 * (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
 * with the following added to such license:
 * 
 *    As a special exception, the copyright holders of this software give
 *    you permission to link this software with independent modules, and
 *    to copy and distribute the resulting executable under terms of your
 *    choice, provided that you also meet, for each linked independent
 *    module, the terms and conditions of the license of that module.
 *    An independent module is a module which is not derived from this
 *    software.  The special exception does not apply to any modifications
 *    of the software.
 * 
 * Not withstanding the above, under no circumstances may you combine
 * this software in any way with any other Broadcom software provided
 * under a license other than the GPL, without Broadcom's express prior
 * written consent.
 * 
 * :>
 *
 ***************************************************************************/

#include <dsphal.h>
#ifndef _CFE_
#include <linux/kernel.h>
#endif
#include <dsphal_pcm.h>

#define PCM_MAX_TS      128

/****************************************************************************
* Variables
****************************************************************************/
const int pcm_ts_impl = 2;
static int pcm_chan_count = 0;


/****************************************************************************
* Function implementation
****************************************************************************/

/*****************************************************************************
*  FUNCTION:   pcm_ts_alloc
*
*  PURPOSE:    Allocate an 8-bit PCM timeslot for a PCM audio channel
*
*  PARAMETERS: dma        - pointer to PCM dma config
*              ts         - 8-bit timeslot id
*              pcm_chan   - PCM channel id
*
*  RETURNS:    nothing
*
*****************************************************************************/
void pcm_ts_alloc(struct dhchancfg *chan, const struct pcm_dma *dma, int ts,
                  int pcm_chan)
{
   struct pcm_chan_priv *priv = (struct pcm_chan_priv *) chan->priv;
   int ts16, ts_reg, ts_loc;

   /* The PCM deals with 16-bit timeslots, so we need to divide our input
    * channels by 2 */
   ts16 = ts >> 1;
   if(ts16 >= PCM_MAX_TS)
   {
      DHLOG_ERR("%s: ts %d outside possible range [0, %d].\n", __func__,
                ts16, PCM_MAX_TS - 1);
      return;
   }

   /* Find the register offset, where time slot bit can be set.
    * Each register can set 32 time slots */
   ts_reg = ts16 >> 5;
   /* Find the time slot position within the register */
   ts_loc = ts16 & 0x1F;

   /* Set the new PCM register setting */
   if(!(PCM->pcm_slot_alloc_tbl[ts_reg] & (1 << ts_loc)))
   {
      pcm_chan_count++;
      PCM->pcm_slot_alloc_tbl[ts_reg] |= (1 << ts_loc);
   }
   priv->ts_offset = (pcm_chan_count - 1);

   /* Cache the pcm channel control - this register can only be written to once
    * the PCM control is enabled */
   pcm_chan_ctrl |= (1 << ts_loc);

   DHLOG_INFO("%s: DMA timeslot [8-bit %d, 16-bit %d] assigned to "
              "PCM channel %d, offset %d\n", __func__, ts, ts16, pcm_chan,
              priv->ts_offset);
}


/*****************************************************************************
*  FUNCTION:   pcm_ts_dealloc
*
*  PURPOSE:    Deallocate an 8-bit RX and TX PCM timeslots
*
*  PARAMETERS: dma  - pointer to PCM dma config
*              ts   - 8-bit timeslot id
*
*  RETURNS:    nothing
*
*****************************************************************************/
void pcm_ts_dealloc(const struct pcm_dma *dma, int ts)
{
   int ts_reg, ts16;

   int ts_loc = 0; 

   /* The PCM deals with 16-bit timeslots, so we need to divide our input
    * channels by 2 */
   ts16 = ts >> 1;
   if(ts16 >= PCM_MAX_TS)
   {
      DHLOG_ERR("%s: ts %d outside possible range [0, %d].\n", __func__,
                ts16, PCM_MAX_TS - 1);
      return;
   }

   /* Find the register offset, where time slot bit can be set.
    * Each register can set 32 time slots */
   ts_reg = ts16 >> 5;
   /* Find the time slot position within the register */
   ts_loc = ts16 & 0x1F;

   /* Set the new PCM register setting */
   if(PCM->pcm_slot_alloc_tbl[ts_reg] & (1 << ts_loc))
   {
      pcm_chan_count--;
      PCM->pcm_slot_alloc_tbl[ts_reg] &= ~(1 << ts_loc);
      pcm_chan_ctrl                   &= ~(1 << ts_loc);
   }

   DHLOG_INFO("%s: DMA timeslot [8-bit %d, 16-bit %d] unassigned\n",
              __func__, ts, ts16);
}


/*****************************************************************************
*  FUNCTION:   pcm_ts_clear
*
*  PURPOSE:    Clear the timeslot allocation tables
*
*  PARAMETERS: none
*
*  RETURNS:    nothing
*
*****************************************************************************/
void pcm_ts_clear()
{
   int i, j;
   for(i = 0; i < PCM_MAX_TIMESLOT_REGS; i++)
   {
      for(j = 0; j < 8 * sizeof(PCM->pcm_slot_alloc_tbl[0]); j++)
      {
         /* PCM block slot alloc register can only change by 1 bit at a time...
          * so make it happy */
         PCM->pcm_slot_alloc_tbl[i] &= ~(1 << j);
      }
   }

   /* Reset the channel control and the cached value */
   pcm_chan_ctrl = 0;
   pcm_chan_count = 0;
}


/*****************************************************************************
*  FUNCTION:   pcm_deinterleave_chan
*
*  PURPOSE:    Deinterleaves and copies audio data for a particular channel
*              from the PCM DMA buffer to the channel's ingress buffer.
*
*  PARAMETERS: chan_cfg   - audio channel config struct
*              in_buf     - ingress audio buffer
*              max_size   - max size of ingress buffer
*              dma_buf    - the dma buffer
*
*  RETURNS:    size of data copied into egress buffer
*
*****************************************************************************/
int pcm_deinterleave_chan(struct dhchancfg *chan_cfg, char *in_buf,
                          size_t max_size, char *dma_buf)
{
   struct pcm_chan_priv *priv = (struct pcm_chan_priv *) chan_cfg->priv;
   unsigned int frame_size, sample_offset, frame_length;
   unsigned int j, buf_idx;

   /* get the frame size in bytes */
   frame_size = pcm_frame_size();

   /* Convert frame_size in terms of bytes or short integers  */
   frame_length = frame_size >> ((PCM_BYTES_PER_SAMPLE == 1) ? 0 : 1);

   buf_idx = 0;

   /* For each frame 'j', place the sample in the ingress buffer */
   for(j = 0; j < PCM_FRAMES_PER_TICK; j++)
   {
      /* Find the offset, where sample will be placed for chan_cfg->ts_offset */
      sample_offset = (j * frame_length) + priv->ts_offset;

      /* Copy the sample */
      if (PCM_BYTES_PER_SAMPLE == 1)
         in_buf[buf_idx] = dma_buf[sample_offset];
      else {
         ((uint16_t*)in_buf)[buf_idx] = ((uint16_t*)dma_buf)[sample_offset];
      }
      buf_idx++;
   }

   return (buf_idx * PCM_BYTES_PER_SAMPLE);
}


/*****************************************************************************
*  FUNCTION:   pcm_interleave_chan
*
*  PURPOSE:    Interleaves and copies audio data for a particular channel into
*              the PCM DMA buffer.
*
*  PARAMETERS: chan_cfg   - audio channel config struct
*              eg_buf     - egress audio buffer
*              size       - size of data to copy from egress buffer
*              dma_buf    - the dma buffer
*              frame_size - size of a PCM frame, in bytes
*
*  RETURNS:    none
*
*****************************************************************************/
void pcm_interleave_chan(struct dhchancfg *chan_cfg, char *eg_buf, size_t size,
                         char *dma_buf)
{
   struct pcm_chan_priv *priv = (struct pcm_chan_priv *) chan_cfg->priv;
   unsigned int frame_size, sample_offset, frame_length;
   unsigned int j, buf_idx;

   /* get the frame size in bytes */
   frame_size = pcm_frame_size();

   /* Convert frame_size in terms of bytes or short integers  */
   frame_length = frame_size >> ((PCM_BYTES_PER_SAMPLE == 1) ? 0 : 1);

   /* For each sample in the buffer */
   buf_idx = 0;

   /* For each frame 'j', copy the sample from the egress buffer */
   for(j = 0; j < PCM_FRAMES_PER_TICK; j++)
   {
      /* Find the offset, where sample will be placed for chan_cfg->ts_offset */
      sample_offset = (j * frame_length) + priv->ts_offset;

      if (PCM_BYTES_PER_SAMPLE == 1)
        dma_buf[sample_offset] = eg_buf[buf_idx];
      else
        ((uint16_t*)dma_buf)[sample_offset] = ((uint16_t*)eg_buf)[buf_idx];
      buf_idx++;
   }
}

/*****************************************************************************
*  FUNCTION:   pcm_frame_size
*
*  PURPOSE:    Calculate the size of a single frame in the PCM DMA buffer.
*
*  PARAMETERS: none
*
*  RETURNS:    size, in bytes, of the pcm frame
*
*****************************************************************************/
size_t pcm_frame_size(void)
{
   size_t frame_size;

   /* Frame size must always be a multiple of 64-bits */
   frame_size = PCM_FRAME_BUF_SIZE(pcm_chan_count * PCM_BYTES_PER_SAMPLE);
   frame_size = (frame_size + 7) & ~0x7;
   return frame_size;
}
