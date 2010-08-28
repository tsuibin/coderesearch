/*
 * (C) 2009 by AKAEDU(www.akaedu.org). 
 * Author: weiqin <qinwei1998@hotmail.com>
 * 
 * based on existing S3C2410 startup code in u-boot and patch from OpenMoko
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, <d.mueller@elsoft.ch>
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

#include <common.h>
#include <video_fb.h>
#include <s3c2440.h>

DECLARE_GLOBAL_DATA_PTR;

/* AKAE2440 board has 12.0000MHz input clock */
/* 304.00 MHz for MPLL*/
#define M_MDIV	0x44
#define M_PDIV	0x1
#define M_SDIV	0x1

/*  48.00 MHz for UPLL*/
#define U_M_MDIV	0x38
#define U_M_PDIV	0x4
#define U_M_SDIV	0x2

static inline void delay (unsigned long loops)
{
	__asm__ volatile ("1:\n"
	  "subs %0, %1, #1\n"
	  "bne 1b":"=r" (loops):"0" (loops));
}


/*
 * Miscellaneous platform dependent initialisations
 */

int board_init (void)
{
	S3C24X0_CLOCK_POWER * const clk_power = S3C24X0_GetBase_CLOCK_POWER();
	S3C24X0_GPIO * const gpio = S3C24X0_GetBase_GPIO();
	S3C24X0_MEMCTL * const memctl = S3C24X0_GetBase_MEMCTL();
	unsigned long bus_conf;
	
	/*Buzzer_Stop*/
	gpio->GPBCON &= ~3;			//set GPB0 as output
	gpio->GPBCON |= 1;
	gpio->GPBDAT &= ~1;

	/* to reduce PLL lock time, adjust the LOCKTIME register */
	clk_power->LOCKTIME = 0xFFFFFF;

	/* configure MPLL */
	clk_power->MPLLCON = ((M_MDIV << 12) + (M_PDIV << 4) + M_SDIV);

	/* some delay between MPLL and UPLL */
	delay (4000);

	/* configure UPLL */
	clk_power->UPLLCON = ((U_M_MDIV << 12) + (U_M_PDIV << 4) + U_M_SDIV);

	/* some delay between MPLL and UPLL */
	delay (8000);

	/* set up the I/O ports */
	gpio->GPACON = 0x007FFFFF;
	gpio->GPBCON = 0x002a9655;
	gpio->GPBUP = 0x000007FF;
	gpio->GPCCON = 0xAAAAAAAA;
	gpio->GPCUP = 0x0000FFFF;
	gpio->GPDCON = 0xAAAAAAAA;
	gpio->GPDUP = 0x0000FFFF;
	gpio->GPECON = 0xAAAAAAAA;
	gpio->GPEUP = 0x0000FFFF;
	gpio->GPFCON = 0x000055AA;
	gpio->GPFUP = 0x000000FF;
	gpio->GPGCON = 0xFD95FFBA;
	gpio->GPGUP = 0x0000FFFF;
#ifdef CONFIG_SERIAL3
	gpio->GPHCON = 0x002AAAAA;
#else
	gpio->GPHCON = 0x002AFAAA;
#endif
	gpio->GPHUP = 0x000007FF;

	gpio->GPJCON = 0x2AAAAAA;

#if 0
	/* USB Device Part */
	/*GPGCON is reset for USB Device */
	gpio->GPGCON = (gpio->GPGCON & ~(3 << 24)) | (1 << 24); /* Output Mode */
	gpio->GPGUP = gpio->GPGUP | ( 1 << 12);			/* Pull up disable */

	gpio->GPGDAT |= ( 1 << 12) ; 
	gpio->GPGDAT &= ~( 1 << 12) ; 
	udelay(20000);
	gpio->GPGDAT |= ( 1 << 12) ; 
#endif
	/*configure for cs8900 chip IO*/
	bus_conf = memctl->BWSCON;
	memctl->BWSCON = (bus_conf & ~0x0000F000) | 0x0000d000;

	/* arch number of AKAE2440-Board */
	gd->bd->bi_arch_number = MACH_TYPE_AKAE2440;

	/* adress of boot parameters */
	gd->bd->bi_boot_params = 0x30000100;

	icache_enable();
	dcache_enable();

	return 0;
}

void board_video_init(GraphicDevice *pGD)
{
	S3C24X0_LCD * const lcd = S3C24X0_GetBase_LCD();

	/* FIXME: select LCM type by env variable */

	/* Configuration for GTA01 LCM on QT2410 */
	lcd->LCDCON1 = 0x00000178; /* CLKVAL=1, BPPMODE=16bpp, TFT, ENVID=0 */

	lcd->LCDCON2 = 0x019fc3c1;
	lcd->LCDCON3 = 0x0039df67;
	lcd->LCDCON4 = 0x00000007;
	lcd->LCDCON5 = 0x0001cf09;
	lcd->LPCSEL  = 0x00000000;
}

int dram_init (void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;

	return 0;
}

/* The sum of all part_size[]s must equal to the NAND size, i.e., 0x4000000.
   "initrd" is sized such that it can hold two uncompressed 16 bit 640*480
   images: 640*480*2*2 = 1228800 < 1245184. */

unsigned int dynpart_size[] = {
    CFG_UBOOT_SIZE, 0x20000, 0x200000, 0xa0000, 0x3d5c000-CFG_UBOOT_SIZE, 0 };
char *dynpart_names[] = {
    "u-boot", "u-boot_env", "kernel", "splash", "rootfs", NULL };


