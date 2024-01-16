/*
 * dual_fuel_gauge_class.h
 *
 *  Created on: March,25 2021
 *      Author: lvxiaofeng@xiaomi.com
 */

#ifndef _LINUX_DUAL_FUEL_GAUGE_CLASS_H_
#define _LINUX_DUAL_FUEL_GAUGE_CLASS_H_

#include <linux/power_supply.h>

#define BQ_REPORT_FULL_SOC 9800
#define BQ_CHARGE_FULL_SOC 9780
#ifdef CONFIG_DUAL_FUEL_GAUGE_BQ27Z561_DAGU
#define BQ_RECHARGE_SOC 9820
#else
#define BQ_RECHARGE_SOC 9900
#endif

#define BQ_RESET_BATT_CTRL_SOC 9000

struct dual_fg_info {
	int fcc_master;
	int fcc_slave;
	bool fg1_batt_ctl_enabled;
	bool fg2_batt_ctl_enabled;
	int fg_master_disable_gpio;
	int fg_slave_disable_gpio;
	struct power_supply *gl_fg_master_psy;
	struct power_supply *gl_fg_slave_psy;
};

#ifndef CONFIG_DUAL_FUEL_GAUGE_BQ27Z561_DAGU
int Dual_Fg_Check_Chg_Fg_Status_And_Disable_Chg_Path(void);
#endif

int Dual_Fg_Reset_Batt_Ctrl_gpio_default(void);
int Dual_Fuel_Gauge_Batt_Ctrl_Init(void);

#endif
