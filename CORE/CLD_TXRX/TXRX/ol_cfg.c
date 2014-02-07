/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
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
#include <ol_cfg.h>
#include <ol_if_athvar.h>

unsigned int vow_config = 0;
module_param(vow_config, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(vow_config, "Do VoW Configuration");
EXPORT_SYMBOL(vow_config);

/* FIX THIS - 
 * For now, all these configuration parameters are hardcoded.
 * Many of these should actually be determined dynamically instead.
 */

ol_pdev_handle ol_pdev_cfg_attach(adf_os_device_t osdev)
{
	struct txrx_pdev_cfg_t *cfg_ctx;

	cfg_ctx = adf_os_mem_alloc(osdev, sizeof(*cfg_ctx));
	if (!cfg_ctx) {
		printk(KERN_ERR "cfg ctx allocation failed\n");
		return NULL;
	}

#ifdef CONFIG_HL_SUPPORT
	cfg_ctx->is_high_latency = 1;
	/* 802.1Q and SNAP / LLC headers are accounted for elsewhere */
	cfg_ctx->tx_download_size = 1500;
#else
	/*
	 * Need to change HTT_LL_TX_HDR_SIZE_IP accordingly.
	 * Include payload, up to the end of UDP header for IPv4 case
	 */
	cfg_ctx->tx_download_size = 16;
#endif
#ifndef QCA_WIFI_ISOC
	/* temporarily diabled PN check for Riva/Pronto */
	cfg_ctx->rx_pn_check = 1;
#endif
#if CFG_TGT_DEFAULT_RX_SKIP_DEFRAG_TIMEOUT_DUP_DETECTION_CHECK
	cfg_ctx->defrag_timeout_check = 1;
#endif
	cfg_ctx->max_peer_id = 511;
	cfg_ctx->max_vdev = CFG_TGT_NUM_VDEV;
	cfg_ctx->pn_rx_fwd_check = 1;
	cfg_ctx->frame_type = wlan_frm_fmt_802_3;
	cfg_ctx->max_thruput_mbps = 800;
	cfg_ctx->max_nbuf_frags = 1;
	cfg_ctx->vow_config = vow_config;
	cfg_ctx->target_tx_credit = CFG_TGT_NUM_MSDU_DESC;
	cfg_ctx->throttle_period_ms = 40;
	return (ol_pdev_handle) cfg_ctx;
}

int ol_cfg_is_high_latency(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->is_high_latency;
}

int ol_cfg_max_peer_id(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	/*
	 * TBDXXX - this value must match the peer table
	 * size allocated in FW
	 */
	return cfg->max_peer_id;
}

int ol_cfg_max_vdevs(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->max_vdev;
}

int ol_cfg_rx_pn_check(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->rx_pn_check;
}

int ol_cfg_rx_fwd_check(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->pn_rx_fwd_check;
}

int ol_cfg_rx_fwd_inter_bss(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->rx_fwd_inter_bss;
}

enum wlan_frm_fmt ol_cfg_frame_type(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->frame_type;
}

int ol_cfg_max_thruput_mbps(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->max_thruput_mbps;
}

int ol_cfg_netbuf_frags_max(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->max_nbuf_frags;
}

int ol_cfg_tx_free_at_download(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->tx_free_at_download;
}

u_int16_t ol_cfg_target_tx_credit(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
#ifndef CONFIG_HL_SUPPORT
	u_int16_t vow_max_sta =  (cfg->vow_config & 0xffff0000) >> 16;
	u_int16_t vow_max_desc_persta = cfg->vow_config & 0x0000ffff;

	return (cfg->target_tx_credit +
		(vow_max_sta * vow_max_desc_persta));
#else
	return cfg->target_tx_credit;
#endif
}

int ol_cfg_tx_download_size(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->tx_download_size;
}

int ol_cfg_rx_host_defrag_timeout_duplicate_check(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->defrag_timeout_check;
}

int ol_cfg_throttle_period_ms(ol_pdev_handle pdev)
{
	struct txrx_pdev_cfg_t *cfg = (struct txrx_pdev_cfg_t *)pdev;
	return cfg->throttle_period_ms;
}
