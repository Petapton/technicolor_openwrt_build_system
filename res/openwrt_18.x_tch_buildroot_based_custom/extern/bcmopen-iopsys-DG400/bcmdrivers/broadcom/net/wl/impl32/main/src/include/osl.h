/*
    Copyright (c) 2019 Broadcom
    All Rights Reserved

    <:label-BRCM:2019:DUAL/GPL:standard
    
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

#ifndef _osl_h_
#define _osl_h_

#include <osl_decl.h>

#ifdef MACOSX
#define OSL_PKTTAG_SZ	56
#else
#define OSL_PKTTAG_SZ	32 /* Size of PktTag */
#endif // endif

/* Drivers use PKTFREESETCB to register a callback function when a packet is freed by OSL */
typedef void (*pktfree_cb_fn_t)(void *ctx, void *pkt, unsigned int status);

/* Drivers use REGOPSSET() to register register read/write funcitons */
typedef unsigned int (*osl_rreg_fn_t)(void *ctx, volatile void *reg, unsigned int size);
typedef void  (*osl_wreg_fn_t)(void *ctx, volatile void *reg, unsigned int val, unsigned int size);

#ifdef MACOSX
extern void setCurMap(osl_t *osh, void *curmap);
extern unsigned int read_bpt_reg(osl_t *osh, volatile void *r, unsigned int size);
#endif // endif

#ifdef __mips__
#define PREF_LOAD		0
#define PREF_STORE		1
#define PREF_LOAD_STREAMED	4
#define PREF_STORE_STREAMED	5
#define PREF_LOAD_RETAINED	6
#define PREF_STORE_RETAINED	7
#define PREF_WBACK_INV		25
#define PREF_PREPARE4STORE	30

#define MAKE_PREFETCH_FN(hint) \
static inline void prefetch_##hint(const void *addr) \
{ \
	__asm__ __volatile__(\
	"       .set    mips4           \n" \
	"       pref    %0, (%1)        \n" \
	"       .set    mips0           \n" \
	: \
	: "i" (hint), "r" (addr)); \
}

#define MAKE_PREFETCH_RANGE_FN(hint) \
static inline void prefetch_range_##hint(const void *addr, int len) \
{ \
	int size = len; \
	while (size > 0) { \
		prefetch_##hint(addr); \
		size -= 32; \
	} \
}

MAKE_PREFETCH_FN(PREF_LOAD)
MAKE_PREFETCH_RANGE_FN(PREF_LOAD)
MAKE_PREFETCH_FN(PREF_STORE)
MAKE_PREFETCH_RANGE_FN(PREF_STORE)
MAKE_PREFETCH_FN(PREF_LOAD_STREAMED)
MAKE_PREFETCH_RANGE_FN(PREF_LOAD_STREAMED)
MAKE_PREFETCH_FN(PREF_STORE_STREAMED)
MAKE_PREFETCH_RANGE_FN(PREF_STORE_STREAMED)
MAKE_PREFETCH_FN(PREF_LOAD_RETAINED)
MAKE_PREFETCH_RANGE_FN(PREF_LOAD_RETAINED)
MAKE_PREFETCH_FN(PREF_STORE_RETAINED)
MAKE_PREFETCH_RANGE_FN(PREF_STORE_RETAINED)
#endif /* __mips__ */

#if defined(__ECOS)
#include <ecos_osl.h>
#elif  defined(DOS)
#include <dos_osl.h>
#elif defined(PCBIOS)
#include <pcbios_osl.h>
#elif defined(linux)
#include <linux_osl.h>
#elif defined(NDIS)
#include <ndis_osl.h>
#elif defined(_CFE_)
#include <cfe_osl.h>
#elif defined(_MINOSL_)
#include <min_osl.h>
#elif defined(MACOSX)
#include <macosx_osl.h>
#elif defined(__NetBSD__)
#include <bsd_osl.h>
#elif defined(__FreeBSD__)
#include <fbsd_osl.h>
#elif defined(EFI)
#include <efi_osl.h>
#elif defined(TARGETOS_nucleus)
#include <nucleus_osl.h>
#elif defined(TARGETOS_symbian)
#include <symbian_osl.h>
#else
#error "Unsupported OSL requested"
#endif // endif

#ifndef PKTDBG_TRACE
#define PKTDBG_TRACE(osh, pkt, bit)	BCM_REFERENCE(osh)
#endif // endif

#ifndef PKTCTFMAP
#define PKTCTFMAP(osh, p)		BCM_REFERENCE(osh)
#endif /* PKTCTFMAP */

/* --------------------------------------------------------------------------
** Register manipulation macros.
*/

#define	SET_REG(osh, r, mask, val)	W_REG((osh), (r), ((R_REG((osh), r) & ~(mask)) | (val)))

#ifndef AND_REG
#define AND_REG(osh, r, v)		W_REG(osh, (r), R_REG(osh, r) & (v))
#endif   /* !AND_REG */

#ifndef OR_REG
#define OR_REG(osh, r, v)		W_REG(osh, (r), R_REG(osh, r) | (v))
#endif   /* !OR_REG */

#if !defined(OSL_SYSUPTIME)
#define OSL_SYSUPTIME() (0)
#define OSL_SYSUPTIME_SUPPORT FALSE
#else
#define OSL_SYSUPTIME_SUPPORT TRUE
#endif /* OSL_SYSUPTIME */

#if !(defined(linux) && defined(PKTC)) && !defined(PKTC_DONGLE) && \
	!(defined(__NetBSD__) && defined(PKTC))
#define	PKTCGETATTR(skb)	(0)
#define	PKTCSETATTR(skb, f, p, b) BCM_REFERENCE(skb)
#define	PKTCCLRATTR(skb)	BCM_REFERENCE(skb)
#define	PKTCCNT(skb)		(1)
#define	PKTCLEN(skb)		PKTLEN(NULL, skb)
#define	PKTCGETFLAGS(skb)	(0)
#define	PKTCSETFLAGS(skb, f)	BCM_REFERENCE(skb)
#define	PKTCCLRFLAGS(skb)	BCM_REFERENCE(skb)
#define	PKTCFLAGS(skb)		(0)
#define	PKTCSETCNT(skb, c)	BCM_REFERENCE(skb)
#define	PKTCINCRCNT(skb)	BCM_REFERENCE(skb)
#define	PKTCADDCNT(skb, c)	BCM_REFERENCE(skb)
#define	PKTCSETLEN(skb, l)	BCM_REFERENCE(skb)
#define	PKTCADDLEN(skb, l)	BCM_REFERENCE(skb)
#define	PKTCSETFLAG(skb, fb)	BCM_REFERENCE(skb)
#define	PKTCCLRFLAG(skb, fb)	BCM_REFERENCE(skb)
#define	PKTCLINK(skb)		NULL
#define	PKTSETCLINK(skb, x)	BCM_REFERENCE(skb)
#define FOREACH_CHAINED_PKT(skb, nskb) \
	for ((nskb) = NULL; (skb) != NULL; (skb) = (nskb))
#define	PKTCFREE		PKTFREE
#define PKTCENQTAIL(h, t, p) \
do { \
	if ((t) == NULL) { \
		(h) = (t) = (p); \
	} \
} while (0)
#endif /* !linux || !PKTC */

#if !defined(HNDCTF) && !defined(PKTC_TX_DONGLE) && !(defined(__NetBSD__) && \
	defined(PKTC)) && !(defined(linux) && (defined(PKTC) || defined(PKTC_TBL)))
#define PKTSETCHAINED(osh, skb)		BCM_REFERENCE(osh)
#define PKTCLRCHAINED(osh, skb)		BCM_REFERENCE(osh)
#define PKTISCHAINED(skb)		FALSE
#endif // endif

/* Lbuf with fraglist */
#define PKTFRAGPKTID(osh, lb)		(0)
#define PKTSETFRAGPKTID(osh, lb, id)	BCM_REFERENCE(osh)
#define PKTFRAGTOTNUM(osh, lb)		(0)
#define PKTSETFRAGTOTNUM(osh, lb, tot)	BCM_REFERENCE(osh)
#define PKTFRAGTOTLEN(osh, lb)		(0)
#define PKTSETFRAGTOTLEN(osh, lb, len)	BCM_REFERENCE(osh)
#define PKTIFINDEX(osh, lb)		(0)
#define PKTSETIFINDEX(osh, lb, idx)	BCM_REFERENCE(osh)

/* in rx path, reuse totlen as used len */
#define PKTFRAGUSEDLEN(osh, lb)			(0)
#define PKTSETFRAGUSEDLEN(osh, lb, len)		BCM_REFERENCE(osh)

#define PKTFRAGLEN(osh, lb, ix)			(0)
#define PKTSETFRAGLEN(osh, lb, ix, len)		BCM_REFERENCE(osh)
#define PKTFRAGDATA_LO(osh, lb, ix)		(0)
#define PKTSETFRAGDATA_LO(osh, lb, ix, addr)	BCM_REFERENCE(osh)
#define PKTFRAGDATA_HI(osh, lb, ix)		(0)
#define PKTSETFRAGDATA_HI(osh, lb, ix, addr)	BCM_REFERENCE(osh)

/* RX FRAG */
#define PKTISRXFRAG(osh, lb)    	(0)
#define PKTSETRXFRAG(osh, lb)		BCM_REFERENCE(osh)
#define PKTRESETRXFRAG(osh, lb)		BCM_REFERENCE(osh)

/* TX FRAG */
#define PKTISTXFRAG(osh, lb)       	(0)
#define PKTSETTXFRAG(osh, lb)		BCM_REFERENCE(osh)

/* Need Rx completion used for AMPDU reordering */
#define PKTNEEDRXCPL(osh, lb)           (TRUE)
#define PKTSETNORXCPL(osh, lb)          BCM_REFERENCE(osh)
#define PKTRESETNORXCPL(osh, lb)        BCM_REFERENCE(osh)

#define PKTISFRAG(osh, lb)		(0)
#define PKTFRAGISCHAINED(osh, i)	(0)
/* TRIM Tail bytes from lfrag */
#define PKTFRAG_TRIM_TAILBYTES(osh, p, len)	PKTSETLEN(osh, p, PKTLEN(osh, p) - len)

#endif	/* _osl_h_ */
