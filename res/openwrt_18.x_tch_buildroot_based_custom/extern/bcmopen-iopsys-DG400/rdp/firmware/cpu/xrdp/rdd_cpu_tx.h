/*
   Copyright (c) 2015 Broadcom Corporation
   All Rights Reserved

    <:label-BRCM:2015:DUAL/GPL:standard
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation (the "GPL").
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    
    A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
    writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
    
:>
*/

#ifndef _RDD_CPU_TX_H_
#define _RDD_CPU_TX_H_

typedef struct
{
    void *sysb;             /**< Buffer pointer */
    void *data;             /**< Buffer pointer */
    uint32_t fpm_bn;        /**< Buffer number */
    uint16_t offset;        /**< Buffer offset */
    uint16_t length;        /**< Buffer length */
    uint8_t abs_flag;       /**< ABS/FPM */
    uint8_t sbpm_copy;      /**< copy to SBPM/FPM */
    uint8_t fpm_fallback;   /**< if no SBPM copy to FPM */
} pbuf_t;


typedef union
{
    uint32_t bn1_or_abs2_or_1588         :18  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    uint32_t data_1588                   :18  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
#ifndef FIRMWARE_LITTLE_ENDIAN
    struct
    {
        uint32_t ssid                    :4  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
        uint32_t fpm_fallback            :1  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
        uint32_t sbpm_copy               :1  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
        uint32_t bn1_or_abs2             :12 __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    };
#else
    struct
    {
        uint32_t bn1_or_abs2             :12 __PACKING_ATTRIBUTE_FIELD_LEVEL__;
        uint32_t sbpm_copy               :1  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
        uint32_t fpm_fallback            :1  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
        uint32_t ssid                    :4  __PACKING_ATTRIBUTE_FIELD_LEVEL__;
    };
#endif
} cpu_tx_bn1_or_abs2_or_1588;



static inline void rdd_cpu_tx_set_packet_descriptor(const rdpa_cpu_tx_info_t *info, pbuf_t *pbuf, RDD_CPU_TX_DESCRIPTOR_DTS *cpu_tx_descriptor)
{
    uintptr_t data_phys_addr = RDD_RSV_VIRT_TO_PHYS(pbuf->data);
    uintptr_t sysb_phys_addr = RDD_RSV_VIRT_TO_PHYS(pbuf->sysb);
    cpu_tx_bn1_or_abs2_or_1588 bn1_or_abs2_or_1588;
    bn1_or_abs2_or_1588.bn1_or_abs2_or_1588 = cpu_tx_descriptor->bn1_or_abs2_or_1588;
    
    cpu_tx_descriptor->abs = pbuf->abs_flag;
    bn1_or_abs2_or_1588.fpm_fallback = pbuf->fpm_fallback;
    bn1_or_abs2_or_1588.sbpm_copy = pbuf->sbpm_copy;
    cpu_tx_descriptor->packet_length = pbuf->length;
    cpu_tx_descriptor->valid = 1;
    cpu_tx_descriptor->agg_pd = 0;
    cpu_tx_descriptor->target_mem_0 = 0;
    if (!cpu_tx_descriptor->abs)
    {
        cpu_tx_descriptor->payload_offset_or_abs_1 = pbuf->offset;
        cpu_tx_descriptor->buffer_number_0_or_abs_0 = pbuf->fpm_bn;
        if (unlikely(info->ptp_info))
        {
            cpu_tx_descriptor->flag_1588 = 1;
            bn1_or_abs2_or_1588.data_1588 = info->ptp_info; /*only 18 bits will be copied */
        }
    }
    else
    {
        cpu_tx_descriptor->abs_data0 = (data_phys_addr) & 0x3FFFF;
        cpu_tx_descriptor->abs_data1 = ((data_phys_addr) >> 18) & 0x3FFFFF;
        cpu_tx_descriptor->buffer_number_0_or_abs_0 = (sysb_phys_addr) & 0x3FFFF;
        cpu_tx_descriptor->payload_offset_or_abs_1 = ((sysb_phys_addr) >> 18) & 0x7FF; 
        bn1_or_abs2_or_1588.bn1_or_abs2 = ((sysb_phys_addr) >> 29) & 0xFFF;
    }

    cpu_tx_descriptor->bn1_or_abs2_or_1588 = bn1_or_abs2_or_1588.bn1_or_abs2_or_1588;
}
#endif /* _RDD_CPU_TX_H_ */
