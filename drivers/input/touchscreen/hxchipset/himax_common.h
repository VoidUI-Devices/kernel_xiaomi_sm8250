/* SPDX-License-Identifier: GPL-2.0 */
/*  Himax Android Driver Sample Code for common functions
 *
 *  Copyright (C) 2019 Himax Corporation.
 *
 *  This software is licensed under the terms of the GNU General Public
 *  License version 2,  as published by the Free Software Foundation,  and
 *  may be copied,  distributed,  and modified under those terms.
 *
 *  This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#ifndef HIMAX_COMMON_H
#define HIMAX_COMMON_H

#include <linux/uaccess.h>
#include <linux/atomic.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/async.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/input/mt.h>
#include <linux/firmware.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/buffer_head.h>
#include <linux/pm_wakeup.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
#include "himax_platform.h"
#include <linux/kallsyms.h>
#include <linux/version.h>
#include <linux/power_supply.h>

#if defined(CONFIG_OF)
#include <linux/of_gpio.h>
#endif

#ifdef CONFIG_TOUCHSCREEN_XIAOMI_TOUCHFEATURE
#include "../xiaomi/xiaomi_touch.h"
#endif

#define HIMAX_DRIVER_VER "2.1.0.2_Xiaomi_L81_01"

#define FLASH_DUMP_FILE "/sdcard/HX_Flash_Dump.bin"

#if defined(CONFIG_TOUCHSCREEN_HIMAX_DEBUG)
#define HX_TP_PROC_2T2R
#endif
/*===========Himax Option function=============*/
#define HX_RST_PIN_FUNC
#define HX_EXCP_RECOVERY

#define HX_BOOT_UPGRADE
#define HX_SMART_WAKEUP
#define HX_RESUME_SEND_CMD
#define HX_USB_DETECT_GLOBAL

#define HX_PEN_DETECT_GLOBAL
#define HX_PROTOCOL_B_3PA

#define XM_GAME_MODE
#define HX_PEN_SWITCH
#define HX_PEN_CONNECT_STRATEGY

#if defined(HX_CONFIG_DRM_PANEL)
#undef HX_CONFIG_FB
#include <drm/drm_panel.h>
extern struct drm_panel gNotifier_dummy_panel;
#elif defined(HX_CONFIG_FB)
#include <linux/notifier.h>
#include <linux/fb.h>
#elif defined(HX_CONFIG_DRM)
#include <drm/drm_notifier_mi.h>
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
#define KERNEL_VER_ABOVE_4_19
#endif

#if defined(HX_ZERO_FLASH)
#define DSRAM_SIZE HX_32K_SZ
#define HX_RESUME_SET_FW
#define HX_CODE_OVERLAY
#else
#define HX_TP_PROC_GUEST_INFO
#endif

#if defined(HX_EXCP_RECOVERY) && defined(HX_ZERO_FLASH)
#endif

#if defined(HX_BOOT_UPGRADE) || defined(HX_ZERO_FLASH)
extern char *g_fw_boot_upgrade_name;
#define BOOT_UPGRADE_FWNAME "Himax_firmware.bin"
#if defined(HX_ZERO_FLASH)
extern char *g_fw_mp_upgrade_name;
#define MPAP_FWNAME "Himax_mpfw.bin"
#endif
#endif

#if defined(HX_PARSE_FROM_DT)
extern uint32_t g_proj_id;
#endif

#if defined(HX_SMART_WAKEUP)
#endif

#if defined(HX_SMART_WAKEUP) && defined(HX_RESUME_SET_FW)
#define HX_SWU_RESUME_SET_FW
#endif

#if defined(HX_CONTAINER_SPEED_UP)
#define DELAY_TIME 40
#endif

#if defined(HX_RST_PIN_FUNC)
#define RST_LOW_PERIOD_S 5000
#define RST_LOW_PERIOD_E 5100
#if defined(HX_ZERO_FLASH)
#define RST_HIGH_PERIOD_S 5000
#define RST_HIGH_PERIOD_E 5100
#else
#define RST_HIGH_PERIOD_S 50000
#define RST_HIGH_PERIOD_E 50100
#endif
#endif

#if defined(HX_CONFIG_FB)
int fb_notifier_callback(struct notifier_block *self, unsigned long event,
			 void *data);
#elif defined(HX_CONFIG_DRM)
int drm_notifier_callback(struct notifier_block *self, unsigned long event,
			  void *data);
#endif

#define HX_85XX_J_SERIES_PWON "HX85xxJ"
#define HX_83102D_SERIES_PWON "HX83102D"
#define HX_83102E_SERIES_PWON "HX83102E"
#define HX_83102J_SERIES_PWON "HX83102J"
#define HX_83108A_SERIES_PWON "HX83108A"
#define HX_83112A_SERIES_PWON "HX83112A"
#define HX_83112F_SERIES_PWON "HX83112F"
#define HX_83121A_SERIES_PWON "HX83121A"

#define HX_TP_BIN_CHECKSUM_SW 1
#define HX_TP_BIN_CHECKSUM_HW 2
#define HX_TP_BIN_CHECKSUM_CRC 3

#define SHIFTBITS 5

#define FW_SIZE_32k 32768
#define FW_SIZE_60k 61440
#define FW_SIZE_64k 65536
#define FW_SIZE_124k 126976
#define FW_SIZE_128k 131072
#define FW_SIZE_255k 261120

#define NO_ERR 0
#define READY_TO_SERVE 1
#define WORK_OUT 2
#define HX_EMBEDDED_FW 3
#define BUS_FAIL -1
#define HX_INIT_FAIL -1
#define MEM_ALLOC_FAIL -2
#define CHECKSUM_FAIL -3
#define GESTURE_DETECT_FAIL -4
#define INPUT_REGISTER_FAIL -5
#define FW_NOT_READY -6
#define LENGTH_FAIL -7
#define OPEN_FILE_FAIL -8
#define PROBE_FAIL -9
#define ERR_WORK_OUT -10
#define ERR_STS_WRONG -11
#define ERR_TEST_FAIL -12
#define HW_CRC_FAIL 1

#define HX_FINGER_ON 1
#define HX_FINGER_LEAVE 2

#define STYLUS_INFO_SZ 12

#if defined(__EMBEDDED_FW__)
extern const uint8_t _binary___Himax_firmware_bin_start[];
extern const uint8_t _binary___Himax_firmware_bin_end[];
extern struct firmware g_embedded_fw;
#endif

#define HIMAX_LOCKDOWN_SIZE 8

enum HX_TS_PATH {
	HX_REPORT_COORD = 1,
	HX_REPORT_SMWP_EVENT,
	HX_REPORT_COORD_RAWDATA,
};

enum HX_TS_STATUS {
	HX_TS_GET_DATA_FAIL = -4,
	HX_EXCP_EVENT,
	HX_CHKSUM_FAIL,
	HX_PATH_FAIL,
	HX_TS_NORMAL_END = 0,
	HX_EXCP_REC_OK,
	HX_READY_SERVE,
	HX_REPORT_DATA,
	HX_EXCP_WARNING,
	HX_IC_RUNNING,
	HX_ZERO_EVENT_COUNT,
	HX_RST_OK,
};

enum cell_type { CHIP_IS_ON_CELL, CHIP_IS_IN_CELL };

#if defined(HX_SMART_WAKEUP)
#define HX_KEY_DOUBLE_CLICK KEY_WAKEUP
#define HX_KEY_UP KEY_UP
#define HX_KEY_DOWN KEY_DOWN
#define HX_KEY_LEFT KEY_LEFT
#define HX_KEY_RIGHT KEY_RIGHT
#define HX_KEY_C KEY_C
#define HX_KEY_Z KEY_Z
#define HX_KEY_M KEY_M
#define HX_KEY_O KEY_O
#define HX_KEY_S KEY_S
#define HX_KEY_V KEY_V
#define HX_KEY_W KEY_W
#define HX_KEY_E KEY_E
#define HX_KEY_LC_M 263
#define HX_KEY_AT 264
#define HX_KEY_RESERVE 265
#define HX_KEY_FINGER_GEST 266
#define HX_KEY_V_DOWN 267
#define HX_KEY_V_LEFT 268
#define HX_KEY_V_RIGHT 269
#define HX_KEY_F_RIGHT 270
#define HX_KEY_F_LEFT 271
#define HX_KEY_DF_UP 272
#define HX_KEY_DF_DOWN 273
#define HX_KEY_DF_LEFT 274
#define HX_KEY_DF_RIGHT 275
#endif

enum fix_touch_info {
	FIX_HX_RX_NUM = 60,
	FIX_HX_TX_NUM = 40,
	FIX_HX_BT_NUM = 0,
	FIX_HX_MAX_PT = 10,
	FIX_HX_INT_IS_EDGE = false,
	FIX_HX_STYLUS_FUNC = 1,
	FIX_HX_STYLUS_ID_V2 = 1,
	FIX_HX_STYLUS_RATIO = 8,
	FIX_HX_TOUCHSCREEN_RATIO = 8,
#if defined(HX_TP_PROC_2T2R)
	FIX_HX_RX_NUM_2 = 64,
	FIX_HX_TX_NUM_2 = 40,
#endif
};

#if defined(HX_ZERO_FLASH)
#define HX_SPI_OPERATION
#define HX_0F_DEBUG
#endif
struct himax_ic_data {
	int vendor_fw_ver;
	int vendor_config_ver;
	int vendor_touch_cfg_ver;
	int vendor_display_cfg_ver;
	int vendor_cid_maj_ver;
	int vendor_cid_min_ver;
	int vendor_panel_ver;
	int vendor_sensor_id;
	int ic_adc_num;
	uint8_t vendor_cus_info[12];
	uint8_t vendor_proj_info[12];
	uint32_t flash_size;
	uint32_t HX_RX_NUM;
	uint32_t HX_TX_NUM;
	uint32_t HX_BT_NUM;
	uint32_t HX_X_RES;
	uint32_t HX_Y_RES;
	uint32_t HX_MAX_PT;
	uint8_t HX_INT_IS_EDGE;
	uint8_t HX_TOUCHSCREEN_RATIO;
	uint8_t HX_STYLUS_FUNC;
	uint8_t HX_STYLUS_ID_V2;
	uint8_t HX_STYLUS_RATIO;
#if defined(HX_TP_PROC_2T2R)
	int HX_RX_NUM_2;
	int HX_TX_NUM_2;
#endif
};

struct himax_virtual_key {
	int index;
	int keycode;
	int x_range_min;
	int x_range_max;
	int y_range_min;
	int y_range_max;
};

struct himax_target_point_data {
	int x;
	int y;
	int w;
	int id;
};

struct himax_target_stylus_data {
	int32_t x;
	int32_t y;
	int32_t w;
	uint32_t hover;
	int32_t tilt_x;
	uint32_t btn;
	uint32_t btn2;
	int32_t tilt_y;
	uint32_t on;
	int pre_btn;
	int pre_btn2;
	uint8_t battery_info;
	uint64_t id;
};

struct himax_target_report_data {
	struct himax_target_point_data *p;

	int finger_on;
	int finger_num;

#if defined(HX_SMART_WAKEUP)
	int SMWP_event_chk;
#endif

	struct himax_target_stylus_data *s;

	int ig_count;
};

struct himax_report_data {
	int touch_all_size;
	int raw_cnt_max;
	int raw_cnt_rmd;
	int touch_info_size;
	uint8_t finger_num;
	uint8_t finger_on;
	uint8_t *hx_coord_buf;
	uint8_t hx_state_info[2];
#if defined(HX_SMART_WAKEUP)
	int event_size;
	uint8_t *hx_event_buf;
#endif

	int rawdata_size;
	uint8_t diag_cmd;
	uint8_t *hx_rawdata_buf;
	uint8_t rawdata_frame_size;
};

struct himax_ts_data {
	bool initialized;
	bool suspended;
	int notouch_frame;
	int ic_notouch_frame;
	atomic_t suspend_mode;
	uint8_t x_channel;
	uint8_t y_channel;
	uint8_t useScreenRes;
	uint8_t diag_cmd;
	char chip_name[30];
	uint8_t chip_cell_type;

	uint8_t protocol_type;
	uint8_t first_pressed;
	uint8_t coord_data_size;
	uint8_t area_data_size;
	uint8_t coordInfoSize;
	uint8_t raw_data_frame_size;
	uint8_t raw_data_nframes;
	uint8_t nFinger_support;
	uint8_t irq_enabled;
	uint8_t diag_self[50];

	uint16_t finger_pressed;
	uint16_t last_slot;
	uint16_t pre_finger_mask;
	uint16_t old_finger;
	int hx_point_num;
	uint8_t hx_stylus_num;

	uint32_t debug_log_level;
	uint32_t widthFactor;
	uint32_t heightFactor;
	uint32_t tw_x_min;
	uint32_t tw_x_max;
	uint32_t tw_y_min;
	uint32_t tw_y_max;
	uint32_t pl_x_min;
	uint32_t pl_x_max;
	uint32_t pl_y_min;
	uint32_t pl_y_max;

	int rst_gpio;
	int use_irq;
	int (*power)(int on);
	int pre_finger_data[10][2];

	struct device *dev;
	struct workqueue_struct *himax_wq;
	struct work_struct work;
	struct input_dev *input_dev;

	struct input_dev *stylus_dev;

	struct hrtimer timer;
	struct i2c_client *client;
	struct himax_platform_data *pdata;
	struct himax_virtual_key *button;
	struct mutex reg_lock;
	struct mutex rw_lock;
	atomic_t irq_state;
	spinlock_t irq_lock;

	/******* SPI-start *******/
	struct spi_device *spi;
	int hx_irq;
	uint8_t *xfer_buff;
	/******* SPI-end *******/

	int in_self_test;
	int suspend_resume_done;
	int bus_speed;
	uint8_t lockdown_info[HIMAX_LOCKDOWN_SIZE];

#if defined(HX_CONFIG_FB) || defined(HX_CONFIG_DRM)
	struct notifier_block fb_notif;
	struct notifier_block drm_notif;
	struct workqueue_struct *himax_att_wq;
	struct delayed_work work_att;
#endif
	struct work_struct himax_lockdown_work;
	struct workqueue_struct *himax_lockdown_wq;
	struct work_struct himax_supply_work;
	struct work_struct resume_work;
	struct workqueue_struct *event_wq;
	struct workqueue_struct *dump_wq;
	struct work_struct dump_work;
	struct workqueue_struct *himax_boot_upgrade_wq;
	struct delayed_work work_boot_upgrade;

#if defined(HX_CONTAINER_SPEED_UP)
	struct workqueue_struct *ts_int_workqueue;
	struct delayed_work ts_int_work;
#endif
	struct workqueue_struct *himax_diag_wq;
	struct delayed_work himax_diag_delay_work;

	int gesture_command_delayed;
	int db_wakeup;
	uint8_t SMWP_enable;
	uint8_t gesture_cust_en[26];
	struct wakeup_source *ts_SMWP_wake_lock;
#if defined(HX_ULTRA_LOW_POWER)
	bool psensor_flag;
#endif

#if defined(HX_HIGH_SENSE)
	uint8_t HSEN_enable;
#endif

#if defined(HX_USB_DETECT_GLOBAL)
	uint8_t usb_connected;
	uint8_t *cable_config;
	int usb_exist;
	struct mutex power_supply_lock;
	struct notifier_block power_supply_notifier;
#endif

#if defined(HX_PEN_DETECT_GLOBAL)
	int pen_is_charge;
	int pen_exist;
	struct mutex pen_supply_lock;
	struct notifier_block pen_supply_notifier;
	struct work_struct pen_supply_change_work;
#endif

#if defined(HX_TP_PROC_GUEST_INFO)
	struct workqueue_struct *guest_info_wq;
	struct work_struct guest_info_work;
#endif

#ifdef CONFIG_TOUCHSCREEN_XIAOMI_TOUCHFEATURE
	uint32_t gamemode_config[3][5];
	struct workqueue_struct *set_touchfeature_wq;
	struct work_struct set_touchfeature_work;
#endif
};

struct himax_debug {
	bool flash_dump_going;
	bool is_checking_irq;
	bool is_call_help;
	void (*fp_ts_dbg_func)(struct himax_ts_data *ts, int start);
	int (*fp_set_diag_cmd)(struct himax_ic_data *ic_data,
			       struct himax_report_data *hx_touch_data);
};

enum input_protocol_type {
	PROTOCOL_TYPE_A = 0x00,
	PROTOCOL_TYPE_B = 0x01,
};

#if defined(HX_HIGH_SENSE)
void himax_set_HSEN_func(uint8_t HSEN_enable);
#endif

#if defined(HX_SMART_WAKEUP)
void himax_set_SMWP_func(uint8_t SMWP_enable);

#define GEST_PTLG_ID_LEN (4)
#define GEST_PTLG_HDR_LEN (4)
#define GEST_PTLG_HDR_ID1 (0xCC)
#define GEST_PTLG_HDR_ID2 (0x44)
#define GEST_PT_MAX_NUM (128)

extern uint8_t *wake_event_buffer;
#endif

extern int g_mmi_refcnt;
extern int *g_inspt_crtra_flag;
extern uint32_t g_hx_chip_inited;
/*void himax_HW_reset(uint8_t loadconfig,uint8_t int_off);*/

int himax_chip_common_suspend(struct himax_ts_data *ts);
int himax_chip_common_resume(struct himax_ts_data *ts);

extern struct filename *(*kp_getname_kernel)(const char *filename);
extern void (*kp_putname_kernel)(struct filename *name);
extern struct file *(*kp_file_open_name)(struct filename *name, int flags,
					 umode_t mode);

struct himax_core_fp;
extern struct himax_core_fp g_core_fp;
extern struct himax_ts_data *private_ts;
extern struct himax_ic_data *ic_data;
extern struct device *g_device;

#if defined(CONFIG_TOUCHSCREEN_HIMAX_DEBUG)
int himax_debug_init(void);
int himax_debug_remove(void);
#endif

#if defined(CONFIG_TOUCHSCREEN_HIMAX_INSPECT)
extern char *g_rslt_data;
extern void (*fp_himax_self_test_init)(void);
#endif

#if defined(HX_CONFIG_DRM)
#if defined(HX_CONFIG_DRM_PANEL)
extern struct drm_panel *active_panel;
#endif
#endif
extern int HX_TOUCH_INFO_POINT_CNT;

extern bool ic_boot_done;

int himax_parse_dt(struct himax_ts_data *ts, struct himax_platform_data *pdata);

extern void himax_parse_dt_ic_info(struct himax_ts_data *ts,
				   struct himax_platform_data *pdata);

int himax_report_data(struct himax_ts_data *ts, int ts_path, int ts_status);

int himax_report_data_init(void);

int himax_dev_set(struct himax_ts_data *ts);
int himax_input_register_device(struct input_dev *input_dev);

#endif

extern void dsi_panel_doubleclick_enable(bool on);