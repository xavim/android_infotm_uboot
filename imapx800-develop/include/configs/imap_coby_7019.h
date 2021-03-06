/***************************************************************************** 
** include/configs/imap_dev.h 
** 
** Copyright (c) 2009~2014 ShangHai Infotm Ltd all rights reserved. 
** 
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** Description: iMAPx200 develop board configuration.
**
** Author:
**     warits	<warits.wang@infotmic.com.cn>
**      
** Revision History: 
** ----------------- 
** 1.1  05/31/2010 
*****************************************************************************/

#ifndef __IMAPCFG_DEV_H__
#define __IMAPCFG_DEV_H__

/*
 * High Level Configuration Options
 * (easy to change)
 */

//#define CONFIG_BOOT_AUTO_ADJUST
#define CONFIG_SYS_SDRAM 256 

#define SOURCE_CHANNEL 1
#define iNAND_CHANNEL 2
#define CONFIG_NDISK_FTL



/* This option enable android recovery */
/* Android recovery needs the following gpio keys */
#ifdef CONFIG_ANDROID_RECOVERY
#define CONFIG_MENU_KEY_GPIO GPEDAT
#define CONFIG_MENU_KEY_GPIO_NUM 14
#endif
/* (home) */
#define CONFIG_RECOVERY_KEY1_GPIO GPADAT
#define CONFIG_RECOVERY_KEY1_GPIO_NUM 5

/* (back) */
#define CONFIG_RECOVERY_KEY2_GPIO GPGDAT
#define CONFIG_RECOVERY_KEY2_GPIO_NUM 5

#define CONFIG_MINUS_KEY_GPIO GPADAT
#define CONFIG_MINUS_KEY_GPIO_NUM 7
#define CONFIG_PLUS_KEY_GPIO GPEDAT
#define CONFIG_PLUS_KEY_GPIO_NUM 2

#define CONFIG_MOTOR_GPIO		GPADAT
#define CONFIG_MOTOR_GPIO_NUM	1

/* This option enable wince features, such as bootup, and bootw */
//#define CONFIG_WINCE_FEATURE	

/* Boot image */
//#define CONFIG_WINCE_COMMON
#define CONFIG_LINUX_COMMON
//#define CONFIG_LOGO_COBY

#define CONFIG_LOGO_GZIP
#define CONFIG_LOGO_GZIP_W  800
#define CONFIG_LOGO_GZIP_H  480
#define CONFIG_GZIP_LOGO_FILE   <BOBY.bin.gz.h>

/* Memory configuration */
#if (CONFIG_SYS_SDRAM==512)
#define CONFIG_DENALI_CS 0x00000300
#define CONFIG_SYS_DENALI_FILE	"asm/arch/denali_data/denali_sam_2x128_coby7019.h"
#elif(CONFIG_SYS_SDRAM==256)
#define CONFIG_SYS_DENALI_FILE  "asm/arch/denali_data/denali_sam_2x128_coby7019.h"
#else
#error System sdram space not defined.  
#endif 

#define PHYS_SDRAM_1_SIZE		0x10000000		/* 256 MB in Bank #1 */
#ifdef 	CONFIG_TEST_VERSION
#define CONFIG_SYS_SDRAM_END    0x48000000
#else
#define CONFIG_SYS_SDRAM_END	0x50000000		/* 256 MB total */
#endif
//#define CONFIG_DENALI_RFRATE	0x06420612
#define CONFIG_IMAPX200_INSP	0x46

/* Board string */

/* Boot Env */
#define CONFIG_LINUX_DEFAULT_BOOTARGS "console=ttySAC3,115200 androidboot.mode=normal mem=256M"
#define CONFIG_LINUX_RECOVER_BOOTARGS "console=ttySAC3,115200 androidboot.mode=recovery mem=256M"
#define CONFIG_EXTRA_ENV_SETTINGS "stdin=serial\0"  \
                                  "stdout=serial\0"  \
                                  "stderr=serial\0"  \
                                   "bootcmd=bootl x\0"

//#define CONFIG_CLK_1056_266
#define CONFIG_CLK_800_266
/*
#define CONFIG_CLK_1200_300
#define CONFIG_CLK_1128_282
#define CONFIG_CLK_1104_276
#define CONFIG_CLK_828_276
#define CONFIG_CLK_800_266
#define CONFIG_CLK_533_133_66
#define CONFIG_CLK_400_100_50
#define CONFIG_CLK_400_133_66
#define CONFIG_CLK_800_200
#define CONFIG_CLK_800_133
#define CONFIG_CLK_840_210
#define CONFIG_CLK_MANUAL_MODE
#define CONFIG_CLK_600_200
#define CONFIG_CLK_450_150
#define CONFIG_CLK_936_234
#define CONFIG_CLK_1008_252
#define CONFIG_SYNC_MODE
*/

/* Drivers */
/* UART */
#define CONFIG_SERIAL4          1	/* we use uart0(SERIAL1) on iMAPx200 FPGA	*/

/* keybd */
//#define CONFIG_KEYBOARD	1

/* Gmac */
#define CONFIG_DRIVER_GMAC		1	/* we have a gmac on imapx200 */

/* MMC */
#define CONFIG_MMC			1
#define CONFIG_IMAP_MMC			1
#define CONFIG_GENERIC_MMC		1

/* LCD */
#define CONFIG_LCD
#define CONFIG_LCD_IMAPX200
#define IMAPFB_HFP		250		/* front porch */
#define IMAPFB_HSW		1		/* hsync width */
#define IMAPFB_HBP		5		/* back porch */
#define IMAPFB_VFP		40		/* front porch */
#define IMAPFB_VSW		1		/* vsync width */
#define IMAPFB_VBP		5		/* back porch */
#define IMAPFB_HRES		800		/* horizon pixel x resolition */
#define IMAPFB_VRES		480		/* line cnt y resolution */
#define CONFIG_LCD_PANEL_GPIO		GPADAT		/*GPODAT*/	
#define CONFIG_LCD_PANEL_GPIO_Bit	6		/*12*/
#define CONFIG_LCD_BL_GPIO			GPFDAT	/*GPADAT*/
#define CONFIG_LCD_BL_GPIO_Bit		6		/*6*/
#define CONFIG_LCD_TOUT_PIN			2
#define CONFIG_LCDCON5				0x24000308
#define CONFIG_DIV_CFG4_VAL			0x1212
//#define CONFIG_LCD_ENBLCTRL

/* SPI */
//#define CONFIG_IMAPX200_SPI
//#define CONFIG_LOW_BATTERY_VAL		550
//#define CONFIG_LOGO_BATTERY_VAL		510

#define CONFIG_POWER_GPIO       GPBDAT
#define CONFIG_POWER_GPIO_NUM   0x2

/* USB */
//#define CONFIG_OTG_EX_GPIO	GPEDAT
//#define CONFIG_OTG_EX_GPIO_NUM	14

 /* NOR */
#define CONFIG_NOR
#define CONFIG_SYS_BOOT_NOR
#define CONFIG_SYS_NOR_RC 0xa

#if 1
/* Init GPIO values */
#define CONFIG_SYS_INIT_GPIO0 GPACON
#define CONFIG_SYS_INIT_GPIO0_VAL 0x10
#define CONFIG_SYS_INIT_GPIO1 GPADAT
#define CONFIG_SYS_INIT_GPIO1_VAL 0x4
#define CONFIG_SYS_INIT_GPIO2 GPOCON
#define CONFIG_SYS_INIT_GPIO2_VAL 0x4000000
#define CONFIG_SYS_INIT_GPIO3 GPODAT
#define CONFIG_SYS_INIT_GPIO3_VAL 0x2000
#define CONFIG_SYS_INIT_GPIO4 GPOCON
#define CONFIG_SYS_INIT_GPIO4_VAL 0x1000000
#define CONFIG_SYS_INIT_GPIO5 GPODAT
#define CONFIG_SYS_INIT_GPIO5_VAL 0x1000

#endif

/* GPIO KEYS */

/* Disable settings */

#define CONFIG_SYS_NAND_8K_PAGE
#undef CONFIG_SYS_NAND_2K_PAGE
#define CONFIG_SYS_NAND_MLC	/* 4bit ECC, 9bytes per 512 */
#undef CONFIG_SYS_NAND_SLC	/* 1bit ECC, 4bytes per 2048 */

/* Include the common config file */
#include <configs/imapx.h>
#define CONFIG_BOARD_MAGIC	0


#endif
