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
#ifndef _DSPHAL_PCM_H
#define _DSPHAL_PCM_H

#include <dsphal.h>

#ifndef _CFE_
#include <linux/dma-mapping.h>
#endif

#include <bcm_map_part.h>

#include <dsphal_chip.h>
#include <pcm_regs.h>
#include <iudma.h>

/****************************************************************************
* Typedefs and Constants
****************************************************************************/
#define PCM_MS_PER_TICK            5
#define PCM_FRAMESYNC_RATE         8000
#define NUM_BUF_PER_CHAN           2 /* double-buffer scheme */

#define PCM_BYTES_PER_SAMPLE       sizeof(uint16_t)
#define PCM_BYTES_PER_SAMPLE_WB    sizeof(uint32_t)
#define PCM_TS_SAMPLES_PER_MS      (PCM_FRAMESYNC_RATE/1000)
#define PCM_FRAMES_PER_TICK        (PCM_TS_SAMPLES_PER_MS * PCM_MS_PER_TICK)
#define PCM_FRAME_BUF_SIZE(size)   ((size + 7) & (~7)) /* must be multiple of 8 bytes */

#define NUM_PCM_DMA_CHAN           2

/* Structure that defines the DMA configuration */
struct pcm_dma
{
   /* DMA channel ID */
   unsigned int chan_id;

   /* Pointer to data callback to call when interrupt fires */
   void         (*data_cb)(unsigned int chan, char *bufp, size_t size,
                           dma_addr_t bufp_dma);
   /* Direction of DMA */
   enum dma_data_direction direction;
   /* Burst size */
   int          burst_size;
   /* The id of the channel's interrupt that calls this channel's data
    * callback. Note that if this is the same as the channel id, the interrupt
    * will be automatically enabled for this channel, otherwise it will be
    * disabled. */
   int          interrupt_chan;
   /* The time in msec at which this channel interrupt generates an tick.
    * If 0, the channel does not generate a tick */
   int          tick;
   /* Buffer allocated for DMA for this channel */
   struct dma_addr buffer;
   /* Size of individual buffer */
   size_t       buffer_size;
   /* Number of buffers for a given channel */
   size_t       buffer_count;
};

/* Private data saved in each configured channel's config */
struct pcm_chan_priv
{
   const struct pcm_dma *rx_dma;
   const struct pcm_dma *tx_dma;
   unsigned int          ts_offset;
};


/****************************************************************************
* Function Definitions
****************************************************************************/
int  pcm_power_up(void);
int  pcm_power_down(void);
int  pcm_clk_init(void);
void pcm_pinmux(void);
void pcm_pinunmux(void);
void pcm_cfg_dpll_div(void);

/* Implemented by timeslot implementation file */
void pcm_ts_init(void);
void pcm_ts_alloc(struct dhchancfg *chan, const struct pcm_dma *dma, int ts,
                  int pcm_chan);
void pcm_ts_dealloc(const struct pcm_dma *dma, int ts);
void pcm_ts_clear(void);
void pcm_interleave_chan(struct dhchancfg *chan_cfg, char *eg_buf, size_t size,
                         char *dma_buf);
int  pcm_deinterleave_chan(struct dhchancfg *chan_cfg, char *in_buf,
                           size_t max_size, char *dma_buf);
size_t pcm_frame_size(void);

/* Implemented by chip file (if applicable) */
int  pcm_quirk_open(struct dhchancfg *cfg, int count);
int  pcm_quirk_release(struct dhchancfg *cfg, int count);

extern volatile unsigned int pcm_chan_ctrl;
extern const int             pcm_ts_impl;
#endif /* _DSPHAL_PCM_H */
