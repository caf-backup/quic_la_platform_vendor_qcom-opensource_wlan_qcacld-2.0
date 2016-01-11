/*
 * Copyright (c) 2015-2016 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

#ifndef _VOS_CNSS_H
#define _VOS_CNSS_H

#include "vos_status.h"

#ifdef CONFIG_CNSS_SDIO
#include <net/cnss.h>

#ifdef WLAN_SCPC_FEATURE
static inline int vos_update_boarddata(unsigned char *buf, unsigned int len)
{
	return cnss_update_boarddata(buf, len);
}

static inline int vos_cache_boarddata(unsigned int offset,
	unsigned int len, unsigned char *buf)
{
	return cnss_cache_boarddata(buf, len, offset);
}
#else
static inline int vos_update_boarddata(unsigned char *buf, unsigned int len)
{
	return 0;
}

static inline int vos_cache_boarddata(unsigned int offset,
	unsigned int len, unsigned char *buf)
{
	return 0;
}
#endif

#else
static inline int vos_update_boarddata(unsigned char *buf, unsigned int len)
{
	return 0;
}

static inline int vos_cache_boarddata(unsigned int offset,
	unsigned int len, unsigned char *buf)
{
	return 0;
}
#endif
#endif/* _VOS_CNSS_H */
