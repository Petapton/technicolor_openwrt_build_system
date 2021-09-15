/*
<:copyright-BRCM:2015:GPL/GPL:standard

	 Copyright (c) 2015 Broadcom
	 All Rights Reserved

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation (the "GPL").

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
GNU General Public License for more details.


A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.

:>
*/

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cpuidle.h>
#include <linux/export.h>
#include <linux/sysfs.h>
#include <linux/cpu.h>
#include <linux/device.h>
#include <bcm_map_part.h>
#include "board.h"

// available cpu idle state indices
// (see bcm_arm_idle_driver[] below)
enum bcm_cpuidle_states {
	bcs_nop,
	bcs_wfi,
	bcs_last
};

#if defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)
static ktime_t time_start, time_end;
static s64 time_in, time_out;
static unsigned int freq_max_index = 0;	 // the index of the max freq allowed by all limiters in this system
static unsigned int freq_oper_index = 0;	// the index of the freq that will be used while active (not sleeping)
static unsigned int freq_admin_index = 0; // the index of the max freq configured by the user

#ifdef CONFIG_BCM96858
static unsigned int bcm_arm_freq_table_mhz[] = {1500, 750, 375, 188};
#else
static unsigned int bcm_arm_freq_table_mhz[] = {1800, 900, 450, 225};
#endif

/* frequency to clock control pattern mapping */
static const unsigned int bcm_arm_freq_pattern[] = {
	0xffffffff, // 100.00% [32/32]
	0x55555555, //	50.00% [16/32]
	0x11111111, //	25.00%	[8/32]
	0x01010101, //	12.50%	[4/32]
};
#define NUM_PATTERN_INDEX (sizeof(bcm_arm_freq_pattern)/sizeof(unsigned))
#define LAST_PATTERN_INDEX (NUM_PATTERN_INDEX-1)
#endif

// Enabling WFI by default gives the same behaviour as when cpuidle is compiled out
static unsigned int wfi_enabled = 1;

void set_cpu_arm_wait(int enable)
{
	wfi_enabled = enable;
	cpu_idle_poll_ctrl(!wfi_enabled);

	printk("Wait Instruction is %sabled\n", enable ? "en" : "dis");
}
EXPORT_SYMBOL(set_cpu_arm_wait);

int get_cpu_arm_wait(void)
{
	return (wfi_enabled);
}
EXPORT_SYMBOL(get_cpu_arm_wait);

#if defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)
static unsigned int auto_clock_divide_enabled = 0;

static void bcm_arm_cpuidle_update_freq( void )
{
	freq_oper_index = (freq_max_index > freq_admin_index) ? freq_max_index : freq_admin_index;
	BIUCTRL->cluster_clk_pattern[0] = bcm_arm_freq_pattern[freq_oper_index];
}

void bcm_arm_cpuidle_set_auto_clk_divide(unsigned int enabled)
{
	auto_clock_divide_enabled = enabled ? 1 : 0;
	time_in = time_out = 0;
	printk("Cpuidle Host Clock divider is %sabled\n", (auto_clock_divide_enabled)?"en":"dis");
}
EXPORT_SYMBOL(bcm_arm_cpuidle_set_auto_clk_divide);

int bcm_arm_cpuidle_get_auto_clk_divide ( void )
{
	return auto_clock_divide_enabled;
}
EXPORT_SYMBOL(bcm_arm_cpuidle_get_auto_clk_divide);

#define bcm_arm_cpuidle_index_to_divider(index) (1 << index)

static int bcm_arm_cpuidle_divider_to_index (unsigned div)
{
	switch (div)
	{
		case 1: return 0;
		case 2: return 1;
		case 4: return 2;
		case 8: return 3;
		default: return -1;
	} 
}

void bcm_arm_cpuidle_set_clk_divider(unsigned int maxdiv)
{
	int index = bcm_arm_cpuidle_divider_to_index(maxdiv);
	if (index != -1)
	{
		freq_admin_index = index;
		bcm_arm_cpuidle_update_freq(); 
	}
}
EXPORT_SYMBOL(bcm_arm_cpuidle_set_clk_divider);

int bcm_arm_cpuidle_get_clk_divider ( void )
{
	return bcm_arm_cpuidle_index_to_divider(freq_admin_index);
}
EXPORT_SYMBOL(bcm_arm_cpuidle_get_clk_divider);

// set maximum frequency for governor
void cpufreq_set_freq_max(unsigned maxdiv)
{
	int index = bcm_arm_cpuidle_divider_to_index(maxdiv);
	if (index != -1)
	{
		freq_max_index = index;
		bcm_arm_cpuidle_update_freq(); 
	}
}
EXPORT_SYMBOL(cpufreq_set_freq_max);
#endif

#if defined(CONFIG_BCM_DDR_SELF_REFRESH_PWRSAVE)
static unsigned int self_refresh_enabled = 0;
static PWRMNGT_DDR_SR_CTRL ddrSrCtrl = {.word = 0};
static volatile PWRMNGT_DDR_SR_CTRL *pDdrSrCtrl = &ddrSrCtrl;

void BcmPwrMngtSetDRAMSelfRefresh(unsigned int enable)
{
	self_refresh_enabled = enable;
	printk("DDR Self Refresh is %sabled\n", self_refresh_enabled ? "en" : "dis");
}
EXPORT_SYMBOL(BcmPwrMngtSetDRAMSelfRefresh);

int BcmPwrMngtGetDRAMSelfRefresh(void)
{
	return (self_refresh_enabled);
}
EXPORT_SYMBOL(BcmPwrMngtGetDRAMSelfRefresh);

void BcmPwrMngtRegisterLmemAddr(PWRMNGT_DDR_SR_CTRL *pDdrSr)
{
	int cpu;

	// Initialize to busy status
	if (NULL != pDdrSr) {
		pDdrSrCtrl = pDdrSr;
	}
	else {
		pDdrSrCtrl = &ddrSrCtrl;
	}

	pDdrSrCtrl->word = 0;
	for_each_possible_cpu(cpu) {
		pDdrSrCtrl->host |= 1<<cpu;
	}
}
EXPORT_SYMBOL(BcmPwrMngtRegisterLmemAddr);
#endif

static int bcm_arm_cpuidle_wfi_enter(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
#if defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)
	const int do_clk_div = auto_clock_divide_enabled;
	static s64 diff;
	unsigned int online_mask = cpumask_bits(cpu_online_mask)[0];
#endif
#if defined(CONFIG_BCM_DDR_SELF_REFRESH_PWRSAVE) || defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)
	// Assume cpu does not change through this function
	const int cpu_mask = 1 << raw_smp_processor_id();
#endif

#if defined(CONFIG_BCM_DDR_SELF_REFRESH_PWRSAVE)
	const int do_ddr_sr	= self_refresh_enabled;

	if (do_ddr_sr) {
		// On 63138, it was found that accessing the memory assigned by the DSL
		// driver to pDdrSrCtrl is very slow. A local shadow copy ddrSrCtrl is
		// first updated and used before deciding to access pDdrSrCtrl.
		// On non-DSL chips, the shadow and the pointer are referring to the same memory
		ddrSrCtrl.host &= ~cpu_mask;
		if (!ddrSrCtrl.host) {
			// Let the PHY MIPS know that all cores on the host will be executing wfi
			pDdrSrCtrl->host = 0;
			// Ensure the PHY MIPS is not active so we can enter SR
			if (!pDdrSrCtrl->phy) {
				uint32 dram_cfg = MEMC->CHN_TIM_DRAM_CFG | DRAM_CFG_DRAMSLEEP;
				MEMC->CHN_TIM_DRAM_CFG = dram_cfg;
			}
		}
	}
#endif

#if defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)

	time_end = ktime_get();
	if (!ktime_to_ns(time_start)) {
		time_start = time_end;
	}
	diff = ktime_to_us(ktime_sub(time_end, time_start));
	time_start = time_end;
	if (diff > S64_MAX)
		diff = S64_MAX;
	time_out += diff;

	if (do_clk_div) {
		// Check if this is the last cpu entering wfi
		// in which case we can reduce the core frequency.
		// The frequency will be raised back immediately after wfi
		// since the code below is running with local interrupts disabled
		unsigned int wfx_mask = BIUCTRL->wfx_state & ((1 << 4) - 1);

		if ((((wfx_mask & online_mask) | cpu_mask) ^ online_mask) == 0) {
			BIUCTRL->cluster_clk_pattern[0] = bcm_arm_freq_pattern[LAST_PATTERN_INDEX];
		}

		dsb(ish);
		wfi();

		if (BIUCTRL->cluster_clk_pattern[0] != bcm_arm_freq_pattern[freq_oper_index]) {
			BIUCTRL->cluster_clk_pattern[0] = bcm_arm_freq_pattern[freq_oper_index];
			time_end = ktime_get();
			diff = ktime_to_us(ktime_sub(time_end, time_start));
			time_start = time_end;
			if (diff > S64_MAX)
				diff = S64_MAX;
			time_in += diff;
		}
	} else
#endif
	{
		dsb(ish);
		wfi();
	}

#if defined(CONFIG_BCM_DDR_SELF_REFRESH_PWRSAVE)
	if (do_ddr_sr) {
		ddrSrCtrl.host |= cpu_mask;
	}
#endif

	return index;
}

static int bcm_arm_cpuidle_nop_enter(struct cpuidle_device *dev,
		struct cpuidle_driver *drv, int index)
{
	return index;
}

static struct cpuidle_driver bcm_arm_idle_driver = {
	.name			= "bcm_wfi",
	.owner			= THIS_MODULE,
	.states[bcs_nop]	= {
		.enter		= bcm_arm_cpuidle_nop_enter,
		.desc		= "nop",
		.name		= "nop",
		.power_usage	= 900,
	},
	.states[bcs_wfi]		= {
		.enter			= bcm_arm_cpuidle_wfi_enter,
		.name			= "wfi",
		.desc			= "Wait For Interrupt",
		.power_usage		= 500,
	},

	.state_count = bcs_last,
};

#if defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)
static ssize_t show_enable_auto_clkdiv(struct device *dev,
																	struct device_attribute *attr,
																	char *buf)
{
	return sprintf(buf, "%d\n", auto_clock_divide_enabled);
}

static ssize_t store_enable_auto_clkdiv(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t size)
{
	unsigned long long value;
	int err = kstrtoull(buf, 0, &value);

	if (err)
		return err;

	auto_clock_divide_enabled = value?1:0;
	time_in = time_out = 0;

	return size;
}

static ssize_t show_time_inside_clkdiv(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	return sprintf(buf, "%lld\n", time_in);
}

static ssize_t show_time_outside_clkdiv(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	return sprintf(buf, "%lld\n", time_out);
}

static ssize_t show_valid_freq_list (struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	int i = 0;
	buf[0] = 0;
	for ( ; i < NUM_PATTERN_INDEX; i++) {
		char buf2[16];
		snprintf(buf2, sizeof(buf2), "%d\n", bcm_arm_freq_table_mhz[i]);
		strcat(buf, buf2);
	}
	return strlen(buf);
}

static ssize_t show_oper_max_freq (struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	return sprintf(buf, "%d\n", bcm_arm_freq_table_mhz[freq_oper_index]);
}

static ssize_t show_admin_max_freq (struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	return sprintf(buf, "%d\n", bcm_arm_freq_table_mhz[freq_admin_index]);
}

static ssize_t store_admin_max_freq(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t size)
{
	unsigned long long value;
	int index = 0;
	int err = kstrtoull(buf, 0, &value);

	if (err)
		return err;

	// If we can't fit in above the second lowest value, assume the lowest value
	freq_admin_index = NUM_PATTERN_INDEX - 1;

	// Search for a valid index matching the input
	for ( ; index < NUM_PATTERN_INDEX -1 ; index++ ) {
		if (value >= bcm_arm_freq_table_mhz[index]) {
			freq_admin_index = index;
			break;
		}
	}

	bcm_arm_cpuidle_update_freq(); 

	return size;
}

static ssize_t show_percent_inside_clkdiv(struct device *dev,
				struct device_attribute *attr,
				char *buf)
{
	s64 per100 = 100*time_in/(time_in+time_out);
	s64 remainder = 100000*time_in/(time_in+time_out) - 1000*per100;

	return sprintf(buf, "%lld.%03lld\n", per100, remainder);
}

static ssize_t store_time_inside_clkdiv(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t size)
{
	time_in = time_out = 0;
	return size;
}
	
static DEVICE_ATTR(enable_auto_clkdiv, 0644, show_enable_auto_clkdiv, store_enable_auto_clkdiv);
static DEVICE_ATTR(time_inside_clkdiv, 0644, show_time_inside_clkdiv, store_time_inside_clkdiv);
static DEVICE_ATTR(time_outside_clkdiv, 0644, show_time_outside_clkdiv, store_time_inside_clkdiv);
static DEVICE_ATTR(percent_inside_clkdiv, 0644, show_percent_inside_clkdiv, store_time_inside_clkdiv);
static DEVICE_ATTR(valid_freq_list, 0444, show_valid_freq_list, NULL);
static DEVICE_ATTR(oper_max_freq, 0444, show_oper_max_freq, NULL);
static DEVICE_ATTR(admin_max_freq, 0644, show_admin_max_freq, store_admin_max_freq);

static struct attribute *bcm_arm_cpuidle_attrs[] = {
	&dev_attr_enable_auto_clkdiv.attr,
	&dev_attr_time_inside_clkdiv.attr,
	&dev_attr_time_outside_clkdiv.attr,
	&dev_attr_percent_inside_clkdiv.attr,
	&dev_attr_valid_freq_list.attr,
	&dev_attr_oper_max_freq.attr,
	&dev_attr_admin_max_freq.attr,
	NULL
};

static struct attribute_group bcm_arm_cpuidle_attr_group = {
	.attrs = bcm_arm_cpuidle_attrs,
	.name = "bcm_arm_cpuidle",
};
#endif

static int __init bcm_arm_cpuidle_init(void)
{
#if defined(CONFIG_BCM_CPUIDLE_CLK_DIVIDER)
	sysfs_create_group(&cpu_subsys.dev_root->kobj, &bcm_arm_cpuidle_attr_group);

	if ((BIUCTRL->cluster_clk_ctrl[0] & 1 << 4) == 0) {
		BIUCTRL->cluster_clk_pattern[0] = ~0;	// full-speed user clock-pattern
		BIUCTRL->cluster_clk_ctrl[0] = 1 << 4;	// enable user clock-patterns
	}
#endif
#if defined(CONFIG_BCM_DDR_SELF_REFRESH_PWRSAVE)
	MEMC->PhyControl.IDLE_PAD_CONTROL = 0xe;
	MEMC->PhyControl.IDLE_PAD_EN0 = 0x2df;
	MEMC->PhyControl.IDLE_PAD_EN1 = 0x3fffff;
	MEMC->PhyByteLane0Control.IDLE_PAD_CTRL = 0xfffe;
	MEMC->PhyByteLane1Control.IDLE_PAD_CTRL = 0xfffe;
#if defined(CONFIG_BCM96858) || defined(CONFIG_BCM94908) || defined(CONFIG_BCM968360)
	MEMC->PhyByteLane2Control.IDLE_PAD_CTRL = 0xfffe;
	MEMC->PhyByteLane3Control.IDLE_PAD_CTRL = 0xfffe;
#endif
#endif
	return cpuidle_register(&bcm_arm_idle_driver, NULL);
}
late_initcall(bcm_arm_cpuidle_init);
