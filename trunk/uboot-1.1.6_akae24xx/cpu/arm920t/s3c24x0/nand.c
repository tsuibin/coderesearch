/*
 * (C) Copyright 2006 OpenMoko, Inc.
 * Author: Harald Welte <laforge@openmoko.org>
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

#if 0
#define DEBUGN	printf
#else
#define DEBUGN(x, args ...) {}
#endif

#if (CONFIG_COMMANDS & CFG_CMD_NAND)
#if !defined(CFG_NAND_LEGACY)

#include <nand.h>
#if defined(CONFIG_S3C2410)
#include <s3c2410.h>
#elif defined(CONFIG_S3C2440)
#include <s3c2440.h>
#endif

#define __REGb(x)	(*(volatile unsigned char *)(x))
#define __REGi(x)	(*(volatile unsigned int *)(x))

#define	NF_BASE		0x4e000000

#define	NFCONF		__REGi(NF_BASE + 0x0)

#if defined(CONFIG_S3C2410)
/*
#define oNFCMD		0x4
#define	oNFADDR		0x8
#define oNFDATA		0xc
#define oNFSTAT		0x10*/
#define NFECC0		__REGb(NF_BASE + 0x14)
#define NFECC1		__REGb(NF_BASE + 0x15)
#define NFECC2		__REGb(NF_BASE + 0x16)
#define NFCONF_nFCE	(1<<11)

#define S3C2410_NFCONF_EN          (1<<15)
#define S3C2410_NFCONF_512BYTE     (1<<14)
#define S3C2410_NFCONF_4STEP       (1<<13)
#define S3C2410_NFCONF_INITECC     (1<<12)
#define S3C2410_NFCONF_TACLS(x)    ((x)<<8)
#define S3C2410_NFCONF_TWRPH0(x)   ((x)<<4)
#define S3C2410_NFCONF_TWRPH1(x)   ((x)<<0)

#elif defined(CONFIG_S3C2440)
/*
#define oNFCMD		0x8
#define oNFADDR		0xc
#define oNFDATA		0x10
#define oNFSTAT		0x20
*/
#define	NFCONT		__REGi(NF_BASE + 0x04)
#define	NFMECC0		__REGi(NF_BASE + 0x2C)
#define NFCONF_nFCE	(1<<1)
#define S3C2440_NFCONF_INITECC		(1<<4)
#define S3C2440_NFCONF_MAINECCLOCK	(1<<5)
#define nand_select()		(NFCONT &= ~(1 << 1))
#define nand_deselect()		(NFCONT |= (1 << 1))
#define nand_clear_RnB()	(NFSTAT |= (1 << 2))
#define nand_detect_RB()	{ while(!(NFSTAT&(1<<2))); }
#define nand_wait()		{ while(!(NFSTAT & 0x4)); } /* RnB_TransDectect */

#endif

#define	NFCMD		__REGb(NF_BASE + oNFCMD)
#define	NFADDR		__REGb(NF_BASE + oNFADDR)
#define	NFDATA		__REGb(NF_BASE + oNFDATA)
#define	NFSTAT		__REGb(NF_BASE + oNFSTAT)


static void s3c2410_hwcontrol(struct mtd_info *mtd, int cmd)
{
	struct nand_chip *chip = mtd->priv;

	DEBUGN("hwcontrol(): 0x%02x: ", cmd);

	switch (cmd) {
	case NAND_CTL_SETNCE:
#if defined(CONFIG_S3C2410)
		NFCONF &= ~NFCONF_nFCE;
#elif defined(CONFIG_S3C2440)
		NFCONT &= ~NFCONF_nFCE;
#endif
		DEBUGN("NFCONF=0x%08x\n", NFCONF);
		break;
	case NAND_CTL_CLRNCE:
#if defined(CONFIG_S3C2410)
		NFCONF |= NFCONF_nFCE;
#elif defined(CONFIG_S3C2440)
		NFCONT |= NFCONF_nFCE;
#endif
		DEBUGN("NFCONF=0x%08x\n", NFCONF);
		break;
	case NAND_CTL_SETALE:
		chip->IO_ADDR_W = NF_BASE + oNFADDR;
		DEBUGN("SETALE\n");
		break;
	case NAND_CTL_SETCLE:
		chip->IO_ADDR_W = NF_BASE + oNFCMD;
		DEBUGN("SETCLE\n");
		break;
	default:
		chip->IO_ADDR_W = NF_BASE + oNFDATA;
		break;
	}
	return;
}

static int s3c2410_dev_ready(struct mtd_info *mtd)
{
	DEBUGN("dev_ready\n");
	return (NFSTAT & 0x01);
}

static void s3c2410_cmdfunc(struct mtd_info *mtd, unsigned cmd,
			    int column, int page_addr)
{
	DEBUGN("cmdfunc(): 0x%02x, col=%d, page=%d\n", cmd, column, page_addr);

	switch (cmd) {
	case NAND_CMD_READ0:
	case NAND_CMD_READ1:
	case NAND_CMD_READOOB:
		NFCMD = cmd;
		NFADDR = column & 0xff;
		NFADDR = page_addr & 0xff;
		NFADDR = (page_addr >> 8) & 0xff;
		NFADDR = (page_addr >> 16) & 0xff;
		break;
	case NAND_CMD_READID:
		NFCMD = cmd;
		NFADDR = 0;
		break;
	case NAND_CMD_PAGEPROG:
		NFCMD = cmd;
		printf("PAGEPROG not implemented\n");
		break;
	case NAND_CMD_ERASE1:
		NFCMD = cmd;
		NFADDR = page_addr & 0xff;
		NFADDR = (page_addr >> 8) & 0xff;
		NFADDR = (page_addr >> 16) & 0xff;
		break;
	case NAND_CMD_ERASE2:
		NFCMD = cmd;
		break;
	case NAND_CMD_SEQIN:
		printf("SEQIN not implemented\n");
		break;
	case NAND_CMD_STATUS:
		NFCMD = cmd;
		break;
	case NAND_CMD_RESET:
		NFCMD = cmd;
		break;
	default:
		break;
	}

	while (!s3c2410_dev_ready(mtd));
}

#ifdef CONFIG_S3C2410_NAND_HWECC
void s3c2410_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
	DEBUGN("s3c2410_nand_enable_hwecc(%p, %d)\n", mtd ,mode);
	NFCONF |= S3C2410_NFCONF_INITECC;
}

static int s3c2410_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat, u_char *ecc_code)
{
	ecc_code[0] = NFECC0;
	ecc_code[1] = NFECC1;
	ecc_code[2] = NFECC2;
	DEBUGN("s3c2410_nand_calculate_hwecc(%p,): 0x%02x 0x%02x 0x%02x\n", mtd , ecc_code[0], ecc_code[1], ecc_code[2]);

	return 0;
}

int s3c2410_nand_correct_data(struct mtd_info *mtd, u_char *dat, u_char *read_ecc, u_char *calc_ecc)
{
	if (read_ecc[0] == calc_ecc[0] &&
	    read_ecc[1] == calc_ecc[1] &&
	    read_ecc[2] == calc_ecc[2])
	    	return 0;

	printf("s3c2410_nand_correct_data: not implemented\n");
	return -1;
}
#endif

// HCLK=100Mhz
#define TACLS		1//7	// 1-clk(0ns) 
#define TWRPH0		4//7	// 3-clk(25ns)
#define TWRPH1		0//7	// 1-clk(10ns)  //TACLS+TWRPH0+TWRPH1>=50ns

int board_nand_init(struct nand_chip *nand)
{
	u_int32_t cfg;
	u_int8_t tacls, twrph0, twrph1;
	S3C24X0_CLOCK_POWER * const clk_power = S3C24X0_GetBase_CLOCK_POWER();
	int i=1;

	DEBUGN("board_nand_init()\n");

	clk_power->CLKCON |= (1 << 4);

	/* initialize hardware */
	twrph0 = 3; twrph1 = 0; tacls = 0;

#if defined(CONFIG_S3C2410)
	cfg = S3C2410_NFCONF_EN;
	cfg |= S3C2410_NFCONF_TACLS(tacls - 1);
	cfg |= S3C2410_NFCONF_TWRPH0(twrph0 - 1);
	cfg |= S3C2410_NFCONF_TWRPH1(twrph1 - 1);

	NFCONF = cfg;
#elif defined(CONFIG_S3C2440)
	NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4)|(0<<0);	
	// TACLS		[14:12]	CLE&ALE duration = HCLK*TACLS.
	// TWRPH0		[10:8]	TWRPH0 duration = HCLK*(TWRPH0+1)
	// TWRPH1		[6:4]	TWRPH1 duration = HCLK*(TWRPH1+1)
	// AdvFlash(R)	[3]		Advanced NAND, 0:256/512, 1:1024/2048
	// PageSize(R)	[2]		NAND memory page size
	//						when [3]==0, 0:256, 1:512 bytes/page.
	//						when [3]==1, 0:1024, 1:2048 bytes/page.
	// AddrCycle(R)	[1]		NAND flash addr size
	//						when [3]==0, 0:3-addr, 1:4-addr.
	//						when [3]==1, 0:4-addr, 1:5-addr.
	// BusWidth(R/W) [0]	NAND bus width. 0:8-bit, 1:16-bit.
	
	NFCONT = (0<<13)|(0<<12)|(0<<10)|(0<<9)|(0<<8)|(1<<6)|(1<<5)|(1<<4)|(1<<1)|(1<<0);
	// Lock-tight	[13]	0:Disable lock, 1:Enable lock.
	// Soft Lock	[12]	0:Disable lock, 1:Enable lock.
	// EnablillegalAcINT[10]	Illegal access interupt control. 0:Disable, 1:Enable
	// EnbRnBINT	[9]		RnB interrupt. 0:Disable, 1:Enable
	// RnB_TrandMode[8]		RnB transition detection config. 0:Low to High, 1:High to Low
	// SpareECCLock	[6]		0:Unlock, 1:Lock
	// MainECCLock	[5]		0:Unlock, 1:Lock
	// InitECC(W)	[4]		1:Init ECC decoder/encoder.
	// Reg_nCE		[1]		0:nFCE=0, 1:nFCE=1.
	// NANDC Enable	[0]		operating mode. 0:Disable, 1:Enable.
	/*
	twrph0 = 7; twrph1 = 7; tacls = 7;
	NFCONF = (tacls<<12)|(twrph0<<8)|(twrph1<<4)|(0<<0);
	NFCONT = (0<<13)|(0<<12)|(0<<10)|(0<<9)|(0<<8)|(1<<6)|(1<<5)|(1<<4)|(1<<1)|(1<<0);*/
#endif
	/* initialize nand_chip data structure */
	nand->IO_ADDR_R = nand->IO_ADDR_W = NF_BASE + oNFDATA;

	/* read_buf and write_buf are default */
	/* read_byte and write_byte are default */

	/* hwcontrol always must be implemented */
	nand->hwcontrol = s3c2410_hwcontrol;

	nand->dev_ready = s3c2410_dev_ready;

#ifdef CONFIG_S3C2410_NAND_HWECC
	nand->enable_hwecc = s3c2410_nand_enable_hwecc;
	nand->calculate_ecc = s3c2410_nand_calculate_ecc;
	nand->correct_data = s3c2410_nand_correct_data;
	nand->eccmode = NAND_ECC_HW3_512;
#else
	nand->eccmode = NAND_ECC_SOFT;
#endif

#ifdef CONFIG_S3C2410_NAND_BBT
	nand->options = NAND_USE_FLASH_BBT;
#else
	nand->options = 0;
#endif

#if defined(CONFIG_S3C2440)
/*
	nand_select();
	nand_clear_RnB();
	NFCMD = NAND_CMD_RESET;
	{ volatile int i; for (i = 0; i < 10; i ++); }
	nand_detect_RB();
	nand_deselect();
*/
#endif

	DEBUGN("end of nand_init\n");

	return 0;
}

#else
 #error "U-Boot legacy NAND support not available for S3C24xx"
#endif
#endif
