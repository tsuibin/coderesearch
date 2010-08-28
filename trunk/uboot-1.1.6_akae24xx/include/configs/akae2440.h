/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <gj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the akae2440 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#if 0
/* If we want to start u-boot from usb bootloader in NOR flash */
#define	CONFIG_SKIP_RELOCATE_UBOOT	1
#define	CONFIG_SKIP_LOWLEVEL_INIT	1
#else
/* If we want to start u-boot directly from within NAND flash */
#define	CONFIG_S3C2410_NAND_BOOT	1
#define	CONFIG_S3C2410_NAND_SKIP_BAD	1
#endif

#define CFG_UBOOT_SIZE		0x40000 /* 512KB size of u-boot, for NAND loading */

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T		1	/* This is an ARM920T Core	*/
#define	CONFIG_S3C2440		1	/* in a SAMSUNG S3C2440 SoC     */
#define CONFIG_AKAE2440		1	/* on a AKAE2440 Board  */

/* input clock of PLL */
//#define CONFIG_SYS_CLK_FREQ	16934400/* SMDK2440 has 16.9344MHz input clock */
#define CONFIG_SYS_CLK_FREQ	12000000/* AKAE2440 has 12.0000MHz input clock */

#define USE_920T_MMU		1
//#define CONFIG_USE_IRQ		1
#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */

/*
 * Size of malloc() pool
 */
#define CFG_MALLOC_LEN		(CFG_ENV_SIZE + 2*1024*1024)
#define CFG_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_CS8900	1	/* we have a CS8900 on-board */
#define CS8900_BASE		0x18000300
#define CS8900_BUS16		1 /* the Linux driver does accesses as shorts */

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on AKAE2440 */
#define CONFIG_HWFLOW		1

/************************************************************
 * RTC
 ************************************************************/
#define	CONFIG_RTC_S3C24X0	1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/***********************************************************
 * Command definition
 ***********************************************************/
#if 0
#define CONFIG_COMMANDS (\
			CFG_CMD_LOADS	 | \
			CFG_CMD_LOADB	 | \
			CFG_CMD_IMI	 | \
			CFG_CMD_CACHE	 | \
			CFG_CMD_MEMORY	 | \
			CFG_CMD_ENV	 | \
			/* CFG_CMD_IRQ	 | */ \
			CFG_CMD_BOOTD	 | \
			CFG_CMD_CONSOLE	 | \
			/*CFG_CMD_BMP	 | */\
			CFG_CMD_ASKENV	 | \
			CFG_CMD_RUN	 | \
			CFG_CMD_ECHO 	 | \
			CFG_CMD_I2C 	 | \
			CFG_CMD_REGINFO	 | \
			CFG_CMD_IMMAP	 | \
			CFG_CMD_DATE	 | \
			CFG_CMD_AUTOSCRIPT | \
			CFG_CMD_BSP	 | \
			CFG_CMD_ELF	 | \
			CFG_CMD_MISC	 | \
			CFG_CMD_USB	 | \
			CFG_CMD_JFFS2	 | \
			CFG_CMD_DIAG	 | \
			CFG_CMD_HWFLOW	 | \
			CFG_CMD_SAVES	 | \
			CFG_CMD_NAND	 | \
			CFG_CMD_PORTIO	 | \
			CFG_CMD_MMC	 | \
			CFG_CMD_FAT	 | \
			CFG_CMD_EXT2	 | \
			CFG_CMD_NET	 | \
			CFG_CMD_NFS  | \
			CFG_CMD_DHCP	 | \
			CFG_CMD_PING	 | \
			0)
#endif

#define CONFIG_COMMANDS (\
			CFG_CMD_ENV	 | \
			/*CFG_CMD_BMP	 | */\
			CFG_CMD_DATE	 | \
			CFG_CMD_LOADS	 | \
			CFG_CMD_LOADB	 | \
			CFG_CMD_BSP		 | \
			CFG_CMD_MISC	 | \
			CFG_CMD_JFFS2	 | \
			CFG_CMD_SAVES	 | \
			CFG_CMD_NAND	 | \
			CFG_CMD_NET	 | \
			CFG_CMD_NFS  | \
			CFG_CMD_PING	 | \
			0)

/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h> 

#define CONFIG_BOOTMODE		"ramdisk"	
#define CONFIG_RDSIZE		0x800000	
#define CONFIG_INIT			"/linuxrc"	
#define CONFIG_BOOTDELAY	4
#define CONFIG_BOOTARGS    	"console=ttySAC0,115200"
#define CONFIG_ETHADDR		00:0c:20:02:0a:5b 
#define CONFIG_NETMASK          255.255.255.0
#define CONFIG_IPADDR		192.168.1.100
#define CONFIG_SERVERIP		192.168.1.21
/*#define CONFIG_BOOTFILE	"elinos-lart" */
#define CONFIG_BOOTCOMMAND	"nand read 0x30008000 kernel 0x00200000\;nand read 0x30800000 ext2 0x1000000\;  myboot 0x30008000"

#define CONFIG_DOS_PARTITION	1
			
#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200		/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX	1		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define	CFG_LONGHELP				/* undef to save memory		*/
#define	CFG_PROMPT		"AKAE2440 # "	/* Monitor Command Prompt	*/
#define	CFG_CBSIZE		256		/* Console I/O Buffer Size	*/
#define	CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */
#define	CFG_MAXARGS		64		/* max number of command args	*/
#define CFG_BARGSIZE		CFG_CBSIZE	/* Boot Argument Buffer Size	*/

#define CFG_MEMTEST_START	0x30000000	/* memtest works on	*/
#define CFG_MEMTEST_END		0x33F00000	/* 63 MB in DRAM	*/

#undef  CFG_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define	CFG_LOAD_ADDR		0x32000000	/* default load address	*/

/* the PWM TImer 4 uses a counter of 15625 for 10 ms, so we need */
/* it to wrap 100 times (total 1562500) to get 1 sec. */
#define	CFG_HZ			1562500

/* valid baudrates */
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(512*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(8*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif

#define CONFIG_USB_OHCI		1

#define CONFIG_USB_DEVICE	1
#define CONFIG_USB_TTY		1
#define CFG_CONSOLE_IS_IN_ENV	1
#define CONFIG_USBD_VENDORID		0x1457     /* Linux/NetChip */
#define CONFIG_USBD_PRODUCTID_GSERIAL	0x5120    /* gserial */
#define CONFIG_USBD_PRODUCTID_CDCACM	0x511d    /* CDC ACM */
#define CONFIG_USBD_MANUFACTURER	"akaedu"
#define CONFIG_USBD_PRODUCT_NAME	"AKAEDU Bootloader " U_BOOT_VERSION
#define CONFIG_EXTRA_ENV_SETTINGS	"usbtty=cdc_acm\0"
#define CONFIG_USBD_DFU			1
#define CONFIG_USBD_DFU_XFER_SIZE	0x4000

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1	   /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	0x04000000 /* 64 MB */

#define PHYS_FLASH_1		0x00000000 /* Flash Bank #1 */

#define CFG_FLASH_BASE		PHYS_FLASH_1

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

#define CONFIG_AMD_LV400	1	/* uncomment this if you have a LV400 flash */

#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#ifdef CONFIG_AMD_LV800
#define PHYS_FLASH_SIZE		0x00100000 /* 1MB */
#define CFG_MAX_FLASH_SECT	(19)	/* max number of sectors on one chip */
#define CFG_ENV_ADDR		(CFG_FLASH_BASE + 0x0F0000) /* addr of environment */
#endif
#ifdef CONFIG_AMD_LV400
#define PHYS_FLASH_SIZE		0x00080000 /* 512KB */
#define CFG_MAX_FLASH_SECT	(11)	/* max number of sectors on one chip */
#define CFG_ENV_ADDR		(CFG_FLASH_BASE + 0x070000) /* addr of environment */
#endif

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(5*CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(5*CFG_HZ) /* Timeout for Flash Write */

//#define CFG_NO_FLASH		1
#define	CFG_ENV_IS_IN_NAND	1
#define NAND_BASE_ADDR		0x0
#define CFG_ENV_SIZE		0x20000		/* 128k Total Size of Environment Sector */
#define CFG_ENV_OFFSET		(NAND_BASE_ADDR + CFG_UBOOT_SIZE)
#define CFG_ENV_OFFSET_REDUND	(CFG_ENV_OFFSET + 0x4000)
//#define CONFIG_NAND_U_BOOT	1
//#define CFG_ENV_OFFSET_OOB	1

#define NAND_MAX_CHIPS		1
#define CFG_NAND_BASE		0x4e000000
#define CFG_MAX_NAND_DEVICE	1

#define CONFIG_MMC		1
#define CFG_MMC_BASE		0xff000000

#define CONFIG_EXT2		1

/* FAT driver in u-boot is broken currently */
#define CONFIG_FAT		1
#define CONFIG_SUPPORT_VFAT

#if 1
/* JFFS2 driver */
#define CONFIG_JFFS2_CMDLINE	1
#define CONFIG_JFFS2_NAND	1
#define CONFIG_JFFS2_NAND_DEV	0
//#define CONFIG_JFFS2_NAND_OFF		0x634000
//#define CONFIG_JFFS2_NAND_SIZE	0x39cc000
#endif

/* ATAG configuration */
#define CONFIG_INITRD_TAG		1
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_CMDLINE_TAG		1

#define CONFIG_DRIVER_S3C24X0_I2C	1
#define CONFIG_HARD_I2C			1
#define CFG_I2C_SPEED			400000  /* 400kHz according to PCF50606 data sheet */
#define CFG_I2C_SLAVE			0x7f

#if 0
#define CONFIG_VIDEO
#define CONFIG_VIDEO_S3C2410
#define CONFIG_CFB_CONSOLE
#define CONFIG_VIDEO_LOGO
#define CONFIG_SPLASH_SCREEN
#define CFG_VIDEO_LOGO_MAX_SIZE		(320*240+1024+100) /* 100 = slack */
#define CONFIG_VIDEO_BMP_GZIP
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_UNZIP
#endif

#define VIDEO_KBD_INIT_FCT	0
#define VIDEO_TSTC_FCT		serial_tstc
#define VIDEO_GETC_FCT		serial_getc

#define LCD_VIDEO_ADDR		0x33d00000


//#define CONFIG_S3C2410_NAND_BBT		1
//#define CONFIG_S3C2410_NAND_HWECC	1

#define CFG_NAND_YAFFS_WRITE
#define CFG_NAND_YAFFS1_NEW_OOB_LAYOUT

#define MTDIDS_DEFAULT		"nand0=akae2440-nand"
#define MTDPARTS_DEFAULT	"mtdparts=akae2440-nand:0x00100000(u-boot),0x00200000(kernel),0x01000000(ext2),-(temp)"
#define CFG_NAND_DYNPART_MTD_KERNEL_NAME "akae2440-nand"
#define CONFIG_NAND_DYNPART

#endif	/* __CONFIG_H */

