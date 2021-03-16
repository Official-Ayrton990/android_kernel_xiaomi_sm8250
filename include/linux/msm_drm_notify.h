/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2019, The Linux Foundation. All rights reserved.
 */
#ifndef _MSM_DRM_NOTIFY_H_
#define _MSM_DRM_NOTIFY_H_

#include <linux/notifier.h>

/* A hardware display blank change occurred */
#define MSM_DRM_EVENT_BLANK			0x01
/* A hardware display blank early change occurred */
#define MSM_DRM_EARLY_EVENT_BLANK		0x02

enum {
	/* panel: power on */
	MSM_DRM_BLANK_UNBLANK,
	/* panel: LP1 */
	MSM_DRM_BLANK_LP1,
	/* panel: LP2 */
	MSM_DRM_BLANK_LP2,
	/* panel: standby */
	MSM_DRM_BLANK_STANDBY,
	/* panel: suspend */
	MSM_DRM_BLANK_SUSPEND,
	/* panel: power off */
	MSM_DRM_BLANK_POWERDOWN,
	/* panel power on for tp */
	MSM_DRM_BLANK_UNBLANK_CUST,
	/* panel:lcd doze mode */
	MSM_DRM_BLANK_NORMAL,
	/* panel power off */
	MSM_DRM_BLANK_POWERDOWN_CUST,
	/*panel 60HZ */
	MSM_DRM_DYNAMICFPS_60 = 60,
	/*panel 90HZ */
	MSM_DRM_DYNAMICFPS_90 = 90,
};

enum msm_drm_display_id {
	/* primary display */
	MSM_DRM_PRIMARY_DISPLAY,
	/* external display */
	MSM_DRM_EXTERNAL_DISPLAY,
	MSM_DRM_DISPLAY_MAX
};

struct msm_drm_notifier {
	enum msm_drm_display_id id;
	void *data;
};

int dsi_panel_backlight_get(void);

#ifdef CONFIG_DRM_MSM
int msm_drm_register_client(struct notifier_block *nb);
int msm_drm_unregister_client(struct notifier_block *nb);
int msm_drm_notifier_call_chain(unsigned long val, void *v);
#else
static inline int msm_drm_register_client(struct notifier_block *nb)
{
	return 0;
}

static inline int msm_drm_unregister_client(struct notifier_block *nb)
{
	return 0;
}

static inline int msm_drm_notifier_call_chain(unsigned long val, void *v)
{
	return 0;
}
#endif
#endif

