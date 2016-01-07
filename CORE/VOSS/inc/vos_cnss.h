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
#include <linux/device.h>
#include <linux/pm_wakeup.h>
#include <linux/jiffies.h>
#include <linux/workqueue.h>
#include <linux/sched.h>

static inline void vos_pm_wake_lock_init(struct wakeup_source *ws,
					const char *name)
{
	wakeup_source_init(ws, name);
}

static inline void vos_pm_wake_lock(struct wakeup_source *ws)
{
	__pm_stay_awake(ws);
}

static inline void vos_pm_wake_lock_timeout(struct wakeup_source *ws,
					ulong msec)
{
	 __pm_wakeup_event(ws, msec);
}

static inline void vos_pm_wake_lock_release(struct wakeup_source *ws)
{
	__pm_relax(ws);
}

static inline void vos_pm_wake_lock_destroy(struct wakeup_source *ws)
{
	wakeup_source_trash(ws);
}

#ifdef CONFIG_CNSS_SDIO
#include <net/cnss.h>

static inline bool vos_oob_enabled(void)
{
	bool enabled = true;

	if (-ENOSYS == cnss_wlan_query_oob_status())
		enabled = false;

	return enabled;
}

static inline int vos_register_oob_irq_handler(oob_irq_handler_t handler,
		void *pm_oob)
{
	return cnss_wlan_register_oob_irq_handler(handler, pm_oob);
}

static inline int vos_unregister_oob_irq_handler(void *pm_oob)
{
	return cnss_wlan_unregister_oob_irq_handler(pm_oob);
}

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
typedef int (*oob_irq_handler_t) (void *dev_para);
static inline bool vos_oob_enabled(void)
{
	return false;
}

static inline int vos_register_oob_irq_handler(oob_irq_handler_t handler,
		void *pm_oob)
{
	return -ENOSYS;
}

static inline int vos_unregister_oob_irq_handler(void *pm_oob)
{
	return -ENOSYS;
}

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
