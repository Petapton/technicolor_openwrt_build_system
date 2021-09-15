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
#ifndef _DSPHAL_DECT_H
#define _DSPHAL_DECT_H

#include <dsphal.h>

#include <linux/dma-mapping.h>

#include <bcm_map_part.h>

#include <dsphal_chip.h>
#include "dect_regs.h"

/****************************************************************************
* Typedefs and Constants
****************************************************************************/
#define DECT_NUM_CHAN            4
#define DECT_NUM_BUF_PER_CHAN    2
#define DECT_DMA_RATE_MS         5

#define DECT_SAMPLE_RATE         16000
#define DECT_BYTES_PER_SAMPLE    sizeof(uint16_t)
#define DECT_SAMPLES_PER_MS      (DECT_SAMPLE_RATE/1000)
#define DECT_DMA_CHAN_SIZE       (DECT_DMA_RATE_MS * DECT_SAMPLES_PER_MS * \
                                  DECT_BYTES_PER_SAMPLE)
#define DECT_DMA_BUF_SIZE        DECT_DMA_CHAN_SIZE * DECT_NUM_BUF_PER_CHAN

#define DECT_BUF_ALIGN_BYTES     64

#define DECT_ZCROSS_TRIG_POINT   0xA


struct dect_dma
{
   /* DMA channel ID */
   unsigned int    chan_id;
   /* DMA channel enabled status */
   unsigned int    enabled;
   /* Direction of DMA */
   enum dma_data_direction direction;
   /* Buffer allocated for this DMA channel */
   struct dma_addr buffer;
   unsigned int    buffer_size;

   /* For some channels, we do not want to generate an interrupt (for example,
    * the TX portion of a duplex DMA may run at the same rate as the RX, so we
    * can do the TX and RX operations in the RX's interrupt). The value in this
    * field specifies which channel's interrupt will call the data callback. If
    * this is the same as our channel id, this channel will handle its own
    * interrupt. */
   int             interrupt_ch;

   /* The time in msec at which this channel interrupt generates an DECT tick.
    * If 0, the channel does not generate a tick */
   int             tick;

   /* Bits to enable this channel as an interrupt source for the DECT DSP
    * interrupt */
   unsigned int    irq_en_bits;
   /* Array of bits that correspond to channel enable bits for the DECT control
    * register */
   unsigned int    ch_en_bits[DECT_NUM_CHAN];

   /* Pointers to DMA initialization registers */
   volatile unsigned int *shm_saddr_reg[DECT_NUM_CHAN];
   volatile unsigned int *ahb_saddr_reg[DECT_NUM_CHAN/2];
   unsigned int           ahb_saddr[DECT_NUM_CHAN];
   volatile unsigned int *xfer_size;
   volatile unsigned int *xfer_counter;
   volatile unsigned int *dma_buf_size;
   volatile unsigned int *dma_offsets[DECT_NUM_CHAN/2];
   unsigned int           dma_trig_bits;
};

enum dect_dma_state
{
   DDS_STOPPED,
   DDS_ALIGNING_DMA,
   DDS_RUNNING,
};


/****************************************************************************
* Function Definitions
****************************************************************************/
int dect_power_up(void);
int dect_power_down(void);
int dect_clk_init(void);
int dect_clk_deinit(void);

void dect_block_reset(void);
void dect_set_stack_status(int started);

#endif /* _DSPHAL_DECT_H */
