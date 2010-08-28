/*
 *
 *  (C) 2009 by AKAEDU(www.akaedu.org). 
 *
 *  Author: weiqin <qinwei1998@hotmail.com>
 *  
 *  cammand for boot linux, implement for akae24xx board
 */

#include <common.h>
#include <command.h>
#include <image.h>
#include <zlib.h>
#include <asm/byteorder.h>

#if defined(CONFIG_AKAE2410) || defined (CONFIG_AKAE2440) 

#define SHOW_BOOT_PROGRESS(arg)
#define LINUX_ZIMAGE_MAGIC	0x016f2818

#define SZ_1K                           0x00000400
#define SZ_4K                           0x00001000
#define SZ_8K                           0x00002000
#define SZ_16K                          0x00004000
#define SZ_32K							0x00008000
#define SZ_64K                          0x00010000
#define SZ_128K                         0x00020000
#define SZ_256K                         0x00040000
#define SZ_512K                         0x00080000

#define SZ_1M                           0x00100000
#define SZ_2M                           0x00200000
#define SZ_4M                           0x00400000
#define SZ_8M                           0x00800000
#define SZ_16M                          0x01000000
#define SZ_32M                          0x02000000
#define SZ_64M                          0x04000000
#define SZ_128M                         0x08000000
#define SZ_256M                         0x10000000
#define SZ_512M                         0x20000000
#define DEFAULT_BOOTPARAM               0x30000100

static struct tag *params;

static void setup_start_tag(void)
{
	ulong address;
	char * bootparam;

	bootparam = getenv("bootparam");
	if( bootparam != 0 ){
		address = simple_strtoul(bootparam, NULL, 16);
	}else{
		address = DEFAULT_BOOTPARAM;
	}
		
	params = (struct tag *)address;

	params->hdr.tag = ATAG_CORE;
	params->hdr.size = tag_size (tag_core);

	params->u.core.flags = 0;
	params->u.core.pagesize = 0;
	params->u.core.rootdev = 0;

	params = tag_next (params);
}

static void setup_memory_tags (void)
{
	ulong  sdram_start;
	ulong  sdram_size;

	sdram_size = SZ_64M;
	sdram_start = 0x30000000;

	params->hdr.tag = ATAG_MEM;
	params->hdr.size = tag_size (tag_mem32);

	params->u.mem.start = sdram_start;
	params->u.mem.size = sdram_size;

	params = tag_next (params);
}

static void setup_commandline_tag (char *commandline)
{
	char *p;

	if (!commandline)
		return;

	/* eat leading white space */
	for (p = commandline; *p == ' '; p++);

	/* skip non-existent command lines so the kernel will still
	 * use its default command line.
	 */
	if (*p == '\0')
		return;

	params->hdr.tag = ATAG_CMDLINE;
	params->hdr.size =
		(sizeof (struct tag_header) + strlen (p) + 1 + 4) >> 2;

	strcpy (params->u.cmdline.cmdline, p);

	params = tag_next (params);
}


static void setup_end_tag (void)
{
	params->hdr.tag = ATAG_NONE;
	params->hdr.size = 0;
}

static char linux_commandline[SZ_4K];

/*
  * supported kernel option:
  * console=	[KNL] Output console device and options.
  * root=		[KNL] Root filesystem
  * nfsroot=[<server-ip>:]<root-dir>[,<nfs-options>]
  * ip=<client-ip>:<server-ip>:<gw-ip>:<netmask>:<hostname>:<device>:<autoconf>
  * mtdparts=	[MTD]
  */

extern int build_linux_mtdoption(char * optionbuf, int len);

int build_linux_cmdline(char * cmdline, int len)
{
	char tmp_option[256];
	char *bootmode = getenv ("bootmode");
	char *bootarg = getenv ("bootargs");
	char *init = getenv ("init");
	char *mtdpart;
//	char *bootmode = "ramdisk";

	if( bootmode == NULL ){
		printf("bootmode env not set\r\n");
		return -1;
	}
	
	memset(cmdline, 0x0, len);
	if( bootarg && init ){
		sprintf(cmdline, "%s init=%s cs89x0_media=rj45 ", bootarg, init);
	}else{
		sprintf(cmdline, "cs89x0_media=rj45 ");
	}
		
	if( strcmp(bootmode, "ramdisk") == 0 ){
		sprintf(tmp_option, "initrd=0x30800000,%s root=/dev/ram ", getenv("rdsize"));				
		strcat(cmdline, tmp_option);				
	}else if( strcmp(bootmode, "nand") == 0 ){//Root filesystem = nand parts
		strcat(cmdline, "root=/dev/mtdblock2 ");
	}else if( strcmp(bootmode, "nfs") == 0 ){//Root filesystem = nfs
		memset(tmp_option, 0, 256);
		sprintf(tmp_option, "root=/dev/nfs nfsroot=%s:%s ", 
			getenv("serverip"), getenv("nfsroot") );
		strcat(cmdline, tmp_option);		
	}
	/*set mtd partion setting*/
	mtdpart = getenv("mtdparts");
	if( mtdpart ){
		memset(tmp_option, 0, 256);
		if( build_linux_mtdoption(tmp_option, 256) == 0)
			strcat(cmdline, tmp_option);
	}
	/*set ip option*/
	memset(tmp_option, 0, 256);
	sprintf(tmp_option, " ip=%s:%s:%s:%s::eth0:off ", 
		getenv("ipaddr"), getenv("serverip"), 
		getenv("gateway"), getenv("netmask") );
	strcat(cmdline, tmp_option);	
}

int do_myboot (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong	addr;
	ulong mach_type;
	void (*theKernel)(int zero, int arch, uint params);
	char * bootparam;

	if (argc != 2) {
		printf ("Usage:\n%s\r\n", cmdtp->usage);
		return 1;
	}
	
	addr = simple_strtoul(argv[1], NULL, 16);
	
	if (*(ulong *)(addr + 9*4) != LINUX_ZIMAGE_MAGIC) {
		printf("Warning: this binary is not compressed linux kernel image\r\n");
		printf("zImage magic = 0x%08lx\r\n", *(ulong *)(addr + 9*4));
		return 1;
	} else {
		printf("zImage magic = 0x%08lx\r\n", *(ulong *)(addr + 9*4));
	}

	build_linux_cmdline(linux_commandline, SZ_4K);	
	printf ("## Booting image at %08lx ...\r\n", addr);

	theKernel = (void (*)(int, int, uint))addr;
	/*
	 * We have reached the point of no return: we are going to
	 * overwrite all exception vector code, so we cannot easily
	 * recover from any failures any more...
	 */
	setup_start_tag ();
	setup_memory_tags ();
	setup_commandline_tag (linux_commandline);
	setup_end_tag ();

	/* we assume that the kernel is in place */
	printf ("\nStarting kernel ...\r\n");
	bootparam = getenv("bootparam");
	if( bootparam != 0 ){
		addr = simple_strtoul(bootparam, NULL, 16);
	}else{
		addr = DEFAULT_BOOTPARAM;
	}

#if defined(CONFIG_AKAE2410)
	mach_type = 1874;
#elif defined(CONFIG_AKAE2440)
	mach_type = 1875;
#endif
	printf("MACH_TYPE = %d\r\n", mach_type);
	theKernel (0, mach_type, addr);

	return 1;
}

U_BOOT_CMD(
 	myboot,	CFG_MAXARGS, 0, do_myboot,
 	"myboot - boot linux image from memory\r\n",
 	"myboot - usage: myboot [addr]\r\n"
);

#endif

