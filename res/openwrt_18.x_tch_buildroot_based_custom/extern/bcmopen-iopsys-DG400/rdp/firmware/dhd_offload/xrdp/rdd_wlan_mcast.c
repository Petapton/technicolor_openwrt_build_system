/*
  Copyright (c) 2014 Broadcom Corporation
  All Rights Reserved

  <:label-BRCM:2014:DUAL/GPL:standard
  
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

#ifdef CONFIG_DHD_RUNNER

#include "rdd.h"
#include "rdd_wlan_mcast_common.h"
#include "rdd_dhd_helper.h"
#include "rdd_ag_dhd_tx_post.h"

/* SSID Macs for proxy mode */

static int _rdd_wlan_mcast_ssid_mac_address_get(uint32_t ssid_mac_idx, RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS *entry,
    int ref_count_only)
{
    if (ssid_mac_idx >= RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_SIZE)
        return BDMF_ERR_RANGE;

    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_REFERENCE_COUNT_READ_G(entry->reference_count,
        RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS_ARR, ssid_mac_idx);
    if (!entry->reference_count)
        return BDMF_ERR_NOENT;

    if (!ref_count_only)
    {
        RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_HIGH_READ_G(entry->mac_address_high,
            RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS_ARR, ssid_mac_idx);

        RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_LOW_READ_G(entry->mac_address_low,
            RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS_ARR, ssid_mac_idx);
    }

    return 0;
}

static void _rdd_wlan_mcast_ssid_mac_address_set(uint32_t ssid_mac_idx,
    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS *entry)
{
    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_REFERENCE_COUNT_WRITE_G(entry->reference_count,
        RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS_ARR, ssid_mac_idx);

    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_HIGH_WRITE_G(entry->mac_address_high,
        RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS_ARR, ssid_mac_idx);

    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_MAC_ADDRESS_LOW_WRITE_G(entry->mac_address_low,
        RDD_WLAN_MCAST_SSID_MAC_ADDRESS_TABLE_ADDRESS_ARR, ssid_mac_idx);
}

int rdd_wlan_mcast_ssid_mac_address_add(uint32_t radio_index, uint32_t ssid,
    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS *entry, uint32_t *ssid_mac_idx)
{
    RDD_BTRACE("radio_index = %d, ssid = %d, entry = %p, ssid_mac_idx = %p\n",
        radio_index, ssid, entry, ssid_mac_idx);

    *ssid_mac_idx = RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_INDEX(radio_index, ssid);
    if (_rdd_wlan_mcast_ssid_mac_address_get(*ssid_mac_idx, entry, 1) == BDMF_ERR_RANGE)
        return BDMF_ERR_RANGE;

    entry->reference_count++;
    _rdd_wlan_mcast_ssid_mac_address_set(*ssid_mac_idx, entry);

    return 0;
}

int rdd_wlan_mcast_ssid_mac_address_delete(uint32_t ssid_mac_idx)
{
    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS entry;
    int rc;

    RDD_BTRACE("ssid_mac_idx = %d\n", ssid_mac_idx);

    rc = _rdd_wlan_mcast_ssid_mac_address_get(ssid_mac_idx, &entry, 0);
    if (rc)
        return rc;

    if (!--entry.reference_count)
    {
        entry.mac_address_low = 0;
        entry.mac_address_high = 0;
    }
    _rdd_wlan_mcast_ssid_mac_address_set(ssid_mac_idx, &entry);
    return 0;
}

int rdd_wlan_mcast_ssid_mac_address_read(uint32_t ssid_mac_idx,
    RDD_WLAN_MCAST_SSID_MAC_ADDRESS_ENTRY_DTS *entry)
{
    RDD_BTRACE("ssid_mac_idx = %d, entry = %p\n", ssid_mac_idx, entry);

    return _rdd_wlan_mcast_ssid_mac_address_get(ssid_mac_idx, entry, 0);
}

int rdd_wlan_mcast_init(wlan_mcast_dhd_list_table_t *table)
{
    int rc;

    RDD_BTRACE("DFT PTR: Virt = %p, Phys = %llx\n", table ? table->virt_p : NULL,
        table ? (long long)table->phys_addr : 0);
    rc = rdd_wlan_mcast_init_common(table);
    if (rc)
        return rc;

    rdd_wlan_mcast_dft_init(table->phys_addr);
    return 0;
}

void rdd_wlan_mcast_dft_init(bdmf_phys_addr_t dft_phys_addr)
{
    uint32_t addr_hi, addr_lo;
    int i;

    GET_ADDR_HIGH_LOW(addr_hi, addr_lo, dft_phys_addr);
    rdd_ag_dhd_tx_post_wlan_mcast_dft_addr_set(addr_lo, addr_hi);

    for (i = 0; i < RDD_WLAN_MCAST_DFT_LIST_SIZE_SIZE; i++)
        rdd_ag_dhd_tx_post_wlan_mcast_dft_list_size_set(i, 0);
}

#endif

