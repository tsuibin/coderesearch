#include "common.h"
#include <linux/fb.h> //FBIOGET_VSCREENINFO
#include <sys/mman.h>
#include <sys/ioctl.h>



#define filename "/dev/fb0"  //打开设备名

int screen_wide,screen_height,bpp;  // 屏幕的宽和高以及颜色位数
struct fb_var_screeninfo fb_var;
int  * fbmem;
int mouse_cx,mouse_cy;//鼠标的坐标值

/*
 *函数功能：初始化framebuffer
 */

int init_fb (void)
{
	int fd;

	fd = open(filename,O_RDWR);

	if(fd<0)
	{
	printf("Open %s error!\n",filename);
	//printf("TRY:sudo %s\n",argv[0]);
	return -1;
	}

	ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);

	screen_wide = fb_var.xres;
	screen_height = fb_var.yres;
	bpp = fb_var.bits_per_pixel;

	printf("Framebuffer:%dx%d-%dbpp\n",screen_wide ,screen_height,bpp);

	fbmem = mmap( 0,screen_wide * screen_height * bpp / 8, PROT_READ | PROT_WRITE ,MAP_SHARED , fd , 0 );

	mouse_cx = screen_wide / 2;
	mouse_cy = screen_height / 2;

	return 0;
}


