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
#include <linux/atomic.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/semaphore.h>
#endif

#include <iudma.h>

/****************************************************************************
* Typedefs and Macros
****************************************************************************/
#define validate_chan(chan)        \
   if(chan > IUDMA_NUM_CHANNELS)   \
      return -EINVAL;

struct iudma_chan_config
{
   int             enabled;
   /* Channel interrupt callback function pointer */
   void            (*data_cb)(unsigned int chan, char *bufp, size_t size,
                              dma_addr_t bufp_dma);
   enum dma_data_direction   direction; /* dma direction */
   int             count;      /* count of items to DMA */

   /* For some channels, we do not want to generate an interrupt (for example,
    * the TX portion of a duplex DMA may run at the same rate as the RX, so we
    * can do the TX and RX operations in the RX's interrupt). The value in this
    * field specifies which channel's interrupt will call the data callback. If
    * this is the same as our channel id, this channel will handle its own
    * interrupt. */
   int             interrupt_ch;

   /* The time in msec at which this channel interrupt generates an IUDMA tick.
    * If 0, the channel does not generate a tick */
   int             tick;

   /* Addresses & sizes for descriptors and buffers */
   struct dma_addr desc_addr;
   size_t          desc_size;
   struct dma_addr buf_addr;
   size_t          buf_size; /* size for 1 buffer. Total size is size * count */
   int             cur_buf_idx;
};


/****************************************************************************
* Local Function Definitions
****************************************************************************/
static int         iudma_reset_chan(unsigned int chan);
static void        iudma_prep_bufs(unsigned int chan);
static irqreturn_t iudma_isr(int irq, void *dev_id);
static void        iudma_channel_interrupt(unsigned int chan);
static void        iudma_handle_dma_owned(unsigned int chan, int item_idx);
static void        iudma_clear(void);


/****************************************************************************
* Variables
****************************************************************************/
struct iudma_chan_config  cfg[IUDMA_NUM_CHANNELS] = {{ 0 }};
atomic_t                  start_reqs = ATOMIC_INIT(0);
static unsigned int       iudma_idle_status = 0, gbl_int_mask_cache = 0;
DEFINE_SPINLOCK(iudma_lock);

struct isr_hdlrs iudma_isr_table = {
   .idle    = iudma_idle,
};


/****************************************************************************
* Functions
****************************************************************************/

/*****************************************************************************
*  FUNCTION:   iudma_request_chan
*
*  PURPOSE:    Request & initialize an IUDMA channel
*
*  PARAMETERS: chan  - DMA channel id
*              count - number of items to copy
*              size  - size of each item
*              bufp  - dma buffer to use
*
*  RETURNS:    0 on success, error otherwise
*
*  NOTES:      the buffer passed must be properly allocated DMA memory and must
*              be large enough to support (count * size) amount of data.
*
*****************************************************************************/
int iudma_request_chan(unsigned int chan, int count, size_t size,
                       struct dma_addr *bufp)
{
   unsigned long flags = 0;
   validate_chan(chan);

   spin_lock_irqsave(&iudma_lock, flags);

   if(cfg[chan].desc_addr.cpu)
   {
      DHLOG_ERR("%s: iudma channel %u already configured\n", __func__, chan);
      spin_unlock_irqrestore(&iudma_lock, flags);
      return -EINVAL;
   }
   /* Allocate descriptor ring */
   memset(&cfg[chan], 0, sizeof(cfg[0]));
   cfg[chan].desc_size     = count * sizeof(struct iudma_descr);
   cfg[chan].desc_addr.cpu = dma_zalloc_coherent(dhdev.device,
         cfg[chan].desc_size, &cfg[chan].desc_addr.dma, GFP_ATOMIC | GFP_DMA);
   if(!cfg[chan].desc_addr.cpu)
   {
      spin_unlock_irqrestore(&iudma_lock, flags);
      return -ENOMEM;
   }

   DHLOG_DEBUG("%s: iudma channel %u desc area 0x%p [0x%p], stram 0x%p\n",
               __func__, chan, cfg[chan].desc_addr.cpu,
               (void*)cfg[chan].desc_addr.dma, &IUDMA->stram[chan]);
   cfg[chan].count        = count;
   cfg[chan].buf_addr.cpu = bufp->cpu;
   cfg[chan].buf_addr.dma = bufp->dma;
   cfg[chan].buf_size     = size;

   spin_unlock_irqrestore(&iudma_lock, flags);

   /* Register the new channel memory in debugs */
#if 0
   dh_debug_reg_mem(cfg[chan].desc_addr.cpu, cfg[chan].desc_size, 4,
                    "iudma-desc%d", chan);
#endif
   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_release_chan
*
*  PURPOSE:    Release an IUDMA channel
*
*  PARAMETERS: chan  - DMA channel id
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int iudma_release_chan(unsigned int chan)
{
   struct dma_addr desc;
   size_t          desc_size;
   unsigned long   flags = 0;

   validate_chan(chan);

   /* Set the burstHalt bit while clearing endma bit */
   do
   {
      writel(IUDMA_CONFIG_BURSTHALT, &IUDMA->ctrl[chan].config);
   } while(readl(&IUDMA->ctrl[chan].config) & IUDMA_CONFIG_ENDMA);

   /* Disable the iudma channel */
   iudma_disable_chan(chan);

   spin_lock_irqsave(&iudma_lock, flags);

   /* Disable interrupt, and reset interrupt state and mask */
   gbl_int_mask_cache &= ~(1 << chan);
   writel(gbl_int_mask_cache, &IUDMA->regs.gbl_int_mask);
   writel(readl(&IUDMA->ctrl[chan].int_status), &IUDMA->ctrl[chan].int_status);
   writel(0, &IUDMA->ctrl[chan].int_mask);

   /* Cleanup the channel config - note that we have to do the
    * dma_free_coherent with irqs enabled since the CPU needs to send IPI to
    * invalidate TLBs. */
   desc      = cfg[chan].desc_addr;
   desc_size = cfg[chan].desc_size;
   memset(&cfg[chan], 0, sizeof(cfg[0]));

   spin_unlock_irqrestore(&iudma_lock, flags);

#if 0
   dh_debug_unreg_mem(desc.cpu);
#endif
   dma_free_coherent(dhdev.device, desc_size, desc.cpu, desc.dma);

   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_config_chan
*
*  PURPOSE:    Configure an IUDMA channel
*
*  PARAMETERS: chan         - DMA channel id
*              burst_size   - DMA burst size in 32-bit words
*              direction    - direction of DMA channel
*              data_cb      - callback function to call when ISR is received
*              interrupt_ch - the id of the channel who's interrupt will call
*                             the data callback for this channel. If we are
*                             triggering our own interrupt, this will be the
*                             same as the passed channel id.
*              tick         - whether or not this channel's interrupt should
*                             generate an IUDMA tick event
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int iudma_config_chan(unsigned int chan, int burst_size,
      enum dma_data_direction direction,
      void (*data_cb)(unsigned int chan, char *bufp, size_t size,
                      dma_addr_t bufp_dma),
      int interrupt_ch, int tick)
{
   unsigned long flags = 0;
   validate_chan(chan);

   spin_lock_irqsave(&iudma_lock, flags);

   cfg[chan].direction    = direction;
   cfg[chan].data_cb      = data_cb;
   cfg[chan].interrupt_ch = interrupt_ch;
   cfg[chan].tick         = tick;

   /* Configure the channel */
   if(burst_size <= 0 || burst_size > IUDMA_MAXBURST_SIZE)
   {
      DHLOG_WARNING("%s: burst_size (%d) outside limits [0, %d] for iudma "
                    "channel %u\n", __func__, burst_size, IUDMA_MAXBURST_SIZE,
                    chan);
      burst_size = 1;
   }
   writel(burst_size, &IUDMA->ctrl[chan].max_burst);

   spin_unlock_irqrestore(&iudma_lock, flags);
   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_enable_chan
*
*  PURPOSE:    Enable an IUDMA channel
*
*  PARAMETERS: chan - DMA channel id
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int iudma_enable_chan(unsigned int chan)
{
   int ret = 0;
   unsigned long flags = 0;
   validate_chan(chan);

   spin_lock_irqsave(&iudma_lock, flags);
   if(cfg[chan].enabled)
      goto out;

   DHLOG_DEBUG("%s: enabling iudma channel %u\n", __func__, chan);
   cfg[chan].enabled = 1;

   spin_unlock_irqrestore(&iudma_lock, flags);
   /* Make sure the iudma is started */
   return ret;

out:
   spin_unlock_irqrestore(&iudma_lock, flags);
   return ret;
}

/*****************************************************************************
*  FUNCTION:   iudma_disable_chan
*
*  PURPOSE:    Disable an IUDMA channel
*
*  PARAMETERS: chan - DMA channel id
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int iudma_disable_chan(unsigned int chan)
{
   unsigned long flags = 0;
   validate_chan(chan);

   spin_lock_irqsave(&iudma_lock, flags);
   if(!cfg[chan].enabled)
      goto out;

   DHLOG_DEBUG("%s: halting iudma channel %u\n", __func__, chan);
   cfg[chan].enabled = 0;

   /* Explicitly reset the channel and stop the IUDMA */
   iudma_reset_chan(chan);

   spin_unlock_irqrestore(&iudma_lock, flags);

   return 0;

out:
   spin_unlock_irqrestore(&iudma_lock, flags);
   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_get_next_buf
*
*  PURPOSE:    Return the pointer to and size of the next DMA buffer.
*
*  PARAMETERS: chan - DMA channel id
*
*  RETURNS:    0 on success, error otherwise
*
*****************************************************************************/
int iudma_get_next_buf(unsigned int chan, char **buf, size_t *size)
{
   int item_idx;
   unsigned long flags = 0;
   validate_chan(chan);

   spin_lock_irqsave(&iudma_lock, flags);

   if(!cfg[chan].enabled)
      goto out;

   /* Get the index of the buffer item to process */
   item_idx = cfg[chan].cur_buf_idx;

   *buf  = cfg[chan].buf_addr.cpu + (item_idx * cfg[chan].buf_size);
   *size = cfg[chan].buf_size;

out:
   spin_unlock_irqrestore(&iudma_lock, flags);
   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_idle
*
*  PURPOSE:    Sets the IUDMA idle status
*
*  PARAMETERS: none
*
*  RETURNS:    none
*
*****************************************************************************/
void iudma_idle(int idle)
{
   unsigned long flags;

   spin_lock_irqsave(&iudma_lock, flags);

   if(iudma_idle_status == idle)
      goto out;
   iudma_idle_status = idle;
   DHLOG_INFO("%s: iudma set to %s\n", __func__, idle ? "idle" : "active");

out:
   spin_unlock_irqrestore(&iudma_lock, flags);
}

/*****************************************************************************
*  FUNCTION:   iudma_configure
*
*  PURPOSE:    Configures the IUDMA
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*  NOTES:      This function assumes we hold the iudma_lock
*
*****************************************************************************/
int iudma_configure(void)
{
   int i, ret = 0;

   /* Ensure the IUDMA is fully disabled before starting */
   iudma_clear();

   /* Register the ISR */
#ifdef CONFIG_MMPBX_API_PATCH
#if defined(CONFIG_BCM963168) || defined(CONFIG_BCM96848) || defined(CONFIG_BCM963381) || defined(CONFIG_BCM963268)
      ret = BcmHalMapInterruptEx( (FN_HANDLER)iudma_isr,
                                      &cfg,
                                      iudma_get_irq_num(),
                                      "voip:iudma",
                                      INTR_REARM_YES,
                                      INTR_AFFINITY_TP1_ONLY);
#else
       ret = request_irq(iudma_get_irq_num(), iudma_isr, 0, "voip:iudma", cfg);
#endif
#else
       ret = request_irq(iudma_get_irq_num(), iudma_isr, 0, "voip:iudma", cfg);
#endif
   if(ret)
   {
      DHLOG_ERR("%s: unable to install interrupt %d (%d)\n", __func__,
                iudma_get_irq_num(), ret);
      goto out;
   }

   DHLOG_INFO("%s: installed irq handler for interrupt %d\n",
               __func__, iudma_get_irq_num());

   for(i = 0; i < ARRAY_SIZE(cfg); i++)
   {
      if(!cfg[i].count)
         continue;

      /* Reset the channel and prepare the buffers */
      iudma_reset_chan(i);
      iudma_prep_bufs(i);

      writel(readl(&IUDMA->ctrl[i].int_status), &IUDMA->ctrl[i].int_status);
      writel(IUDMA_INTMASK_BDONE | IUDMA_INTMASK_NOTVLD,
             &IUDMA->ctrl[i].int_mask);

      if(cfg[i].interrupt_ch == i)
         gbl_int_mask_cache |= (1 << i);

      /* Register IUDMA as a tick source, if required */
      if(cfg[i].tick)
         dh_reg_tick_source(DH_TICK_SOURCE_IUDMA, cfg[i].tick);
   }

   /* Enable the DMA */
   writel(gbl_int_mask_cache, &IUDMA->regs.gbl_int_mask);

out:
   return ret;
}


/*****************************************************************************
*  FUNCTION:   iudma_start
*
*  PURPOSE:    Starts the IUDMA
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*  NOTES:      This function assumes we hold the iudma_lock
*
*****************************************************************************/
int iudma_start(void)
{
   int i, ret = 0;

   if(atomic_inc_return(&start_reqs) != 1)
      return 0;

   iudma_configure();

   /* Enable DMA channels */
   for(i = 0; i < ARRAY_SIZE(cfg); i++)
   {
      if(!cfg[i].count)
         continue;
      writel(IUDMA_CONFIG_ENDMA, &IUDMA->ctrl[i].config);
   }

   /* Enable DMA controller */
   writel(IUDMA_REGS_CTRLCONFIG_MASTER_EN, &IUDMA->regs.ctrl_config);
   return ret;
}

/*****************************************************************************
*  FUNCTION:   iudma_stop
*
*  PURPOSE:    Stop the IUDMA
*
*  PARAMETERS: none
*
*  RETURNS:    0 on success, error otherwise
*
*  NOTES:      This function assumes we hold the iudma_lock
*
*****************************************************************************/
int iudma_stop(void)
{
   if(atomic_dec_return(&start_reqs) == 0)
   {
      /* Free the ISR and stop the DMA */
      iudma_clear();

      free_irq(iudma_get_irq_num(), cfg);

      /* Unreg IUDMA as a tick source */
      dh_unreg_tick_source(DH_TICK_SOURCE_IUDMA);

      DHLOG_DEBUG("%s: freed irq handler for interrupt %d\n",
                  __func__, iudma_get_irq_num());
   }
   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_clear
*
*  PURPOSE:    Clear the IUDMA config
*
*  PARAMETERS: none
*
*  RETURNS:    nothing
*
*  NOTES:      This function assumes the iudma lock is held
*
*****************************************************************************/
static void iudma_clear(void)
{
   int i;

   writel(0, &IUDMA->regs.ctrl_config);
   writel(0, &IUDMA->regs.gbl_int_mask);

   for(i = 0; i < ARRAY_SIZE(IUDMA->ctrl); i++)
   {
      writel(0,  &IUDMA->ctrl[i].config);
      writel(~0, &IUDMA->ctrl[i].int_status);
      writel(0,  &IUDMA->ctrl[i].int_mask);
      writel(1,  &IUDMA->ctrl[i].max_burst);
      writel(0,  &IUDMA->stram[i].base_desc_pointer);
      writel(0,  &IUDMA->stram[i].state_bytes_done_ring_offset);
      writel(0,  &IUDMA->stram[i].flags_length_status);
      writel(0,  &IUDMA->stram[i].current_buffer_pointer);
      writel((1 << i), &IUDMA->regs.channel_reset);
   }
}

/*****************************************************************************
*  FUNCTION:   iudma_reset_chan
*
*  PURPOSE:    Reset an IUDMA channel config
*
*  PARAMETERS: chan - DMA channel id
*
*  RETURNS:    0 on success, error otherwise
*
*  NOTES:      This function assumes the iudma lock is held
*
*****************************************************************************/
static int iudma_reset_chan(unsigned int chan)
{
   writel(0, &IUDMA->ctrl[chan].config);
   /* The burst halt on the channels may not properly reset the DMA logic.
    * Setting this ensures the state of the DMA is actually properly reset
    * and won't break when initialized the next time around */
   writel((1 << chan), &IUDMA->regs.channel_reset);
   return 0;
}

/*****************************************************************************
*  FUNCTION:   iudma_prep_bufs
*
*  PURPOSE:    Prepare a channel's DMA buffers
*
*  PARAMETERS: chan - DMA channel id
*
*  RETURNS:    0 on success, error otherwise
*
*  NOTES:      This function assumes the iudma lock is held
*
*****************************************************************************/
static void iudma_prep_bufs(unsigned int chan)
{
   unsigned int i;

   cfg[chan].cur_buf_idx = 0;
   for(i = 0; i < cfg[chan].count; i++)
   {
      unsigned int flags = 0;
      struct iudma_descr *desc =
         &(((struct iudma_descr*)cfg[chan].desc_addr.cpu)[i]);

      /* Set the descriptor copy size */
      flags |= cfg[chan].buf_size << IUDMA_FLAGS_LENGTH_SHIFT;

      /* Set the ownership bits for all the buffers */
      flags |= IUDMA_STATUS_OWN << IUDMA_FLAGS_STATUS_SHIFT;

      /* If this is the last descriptor, set the wrap bit */
      if(i + 1 == cfg[chan].count)
         flags |= IUDMA_STATUS_WRAP << IUDMA_FLAGS_STATUS_SHIFT;

      /* Set the flags and buffer address for the descriptor */
      desc->flags &= ~IUDMA_FLAGS_STATUS_MASK | ~IUDMA_FLAGS_LENGTH_MASK;
      desc->flags |= flags;
      desc->addr   = cfg[chan].buf_addr.dma + (i * cfg[chan].buf_size);
      wmb();
   }

   /* Ensure the state ram is not in a bad state */
   writel(cfg[chan].desc_addr.dma, &IUDMA->stram[chan].base_desc_pointer);
   writel(0, &IUDMA->stram[chan].state_bytes_done_ring_offset);
}

/*****************************************************************************
*  FUNCTION:   iudma_isr
*
*  PURPOSE:    Interrupt Service Routine handler - calls the handlers for each
*              channel that has the interrupt bit set and handler enabled.
*
*  PARAMETERS: irq    - interrupt number
*              dev_id - ISR cookie passed in request_irq
*
*  RETURNS:    irq return value
*
*****************************************************************************/
static irqreturn_t iudma_isr(int irq, void *dev_id)
{
   int i, tick = 0;
   unsigned long flags = 0, status;
   (void)irq;
   (void)dev_id;

   dh_debug_isr(DH_TICK_SOURCE_IUDMA);

   spin_lock_irqsave(&iudma_lock, flags);

   status = readl(&IUDMA->regs.gbl_int_stat);

   /* Iterate through each channel and calls the interrupt handler for all
    * valid channels that have their interrupt bits set */
   for(i = 0; i < ARRAY_SIZE(cfg); i++)
   {
      if(!cfg[i].count || cfg[i].interrupt_ch != i)
         continue;
      if(status & (1 << i))
      {
         iudma_channel_interrupt(i);
         if(cfg[i].tick)
            tick = 1;
      }
   }

   spin_unlock_irqrestore(&iudma_lock, flags);

   /* Signal that the DSP is ready to tick */
   if(tick && !iudma_idle_status)
      dh_tick(DH_TICK_SOURCE_IUDMA);

   return IRQ_HANDLED;
}

/*****************************************************************************
*  FUNCTION:   iudma_channel_interrupt
*
*  PURPOSE:    Handles the interrupt for a specific channel
*
*  PARAMETERS: chan - DMA channel id
*
*  RETURNS:    nothing
*
*  NOTES:      This function assumes we are holding the iudma lock
*
*****************************************************************************/
static void iudma_channel_interrupt(unsigned int chan)
{
   int i;
   int item_idx;
   struct iudma_descr *desc;

   /* If DMA is not configured, skip processing this channel */
   if(!cfg[chan].count)
      return;

   /* Get the index of the buffer item to process */
   item_idx = cfg[chan].cur_buf_idx;

   /* Verify the buffer is valid for us to use. If it's not, there may be a
    * mismatch between us and the DMA. Try another buffer. If the second buffer
    * is also not working, reset the DMA.*/
   desc = &(((struct iudma_descr*)cfg[chan].desc_addr.cpu)[item_idx]);
   if(desc->flags & IUDMA_STATUS_OWN)
   {
      item_idx = (item_idx + 1) % cfg[chan].count;
      desc = &(((struct iudma_descr*)cfg[chan].desc_addr.cpu)[item_idx]);
      if(desc->flags & IUDMA_STATUS_OWN)
      {
         iudma_handle_dma_owned(chan, item_idx);
         goto ack_channel;
      }
   }

   /* Call the data callback if it is configured */
   if(cfg[chan].enabled && cfg[chan].data_cb)
   {
      cfg[chan].data_cb(chan,
            cfg[chan].buf_addr.cpu + (item_idx * cfg[chan].buf_size),
            cfg[chan].buf_size,
            cfg[chan].buf_addr.dma + (item_idx * cfg[chan].buf_size));
   }

   /* Move our current buffer index forward */
   cfg[chan].cur_buf_idx++;
   if(cfg[chan].cur_buf_idx >= cfg[chan].count)
      cfg[chan].cur_buf_idx = 0;

   /* Set the ownership bits on the buffers */
   desc->flags |= IUDMA_STATUS_OWN;
   wmb();

ack_channel:
   /* Ack the interrupt (if required) and re-enable the DMA */
   writel(readl(&IUDMA->ctrl[chan].int_status), &IUDMA->ctrl[chan].int_status);
   writel(IUDMA_CONFIG_ENDMA, &IUDMA->ctrl[chan].config);

   /* If we are responding to a real interrupt, we need to go through the list
    * of all configured channels and find any that have attached to our
    * interrupt and invoke the channel_interrupt handler for those channels
    * as well. */
   if(cfg[chan].interrupt_ch != chan)
      return;
   for(i = 0; i < ARRAY_SIZE(cfg); i++)
   {
      if(i == chan || cfg[i].interrupt_ch != chan)
         continue;
      iudma_channel_interrupt(i);
   }
}

static void iudma_handle_dma_owned(unsigned int chan, int item_idx)
{
   debug_stats.dma_realigns[DH_TICK_SOURCE_IUDMA]++;

   /* If this DMA channel has the "not valid" bit set, just restart the DMA */
   if(readl(&IUDMA->ctrl[chan].int_status) & IUDMA_INTSTAT_NOTVLD)
   {
      debug_stats.dma_restarts[DH_TICK_SOURCE_IUDMA]++;

      iudma_reset_chan(chan);
      iudma_prep_bufs(chan);
   }
}
