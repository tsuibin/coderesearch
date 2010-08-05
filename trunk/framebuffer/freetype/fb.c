#include "common.h"
#include <linux/fb.h> //FBIOGET_VSCREENINFO
#include <sys/mman.h>

#define filename "/dev/fb0"

int w,h,bpp;
struct fb_var_screeninfo fb_var;
int * fbmem;

int init_fb (void)
{
	int fd;
	int i;
	fd = open(filename,O_RDWR);

	if(fd<0)
	{
	printf("Open %s error!\n",filename);
	return -1;
	}
	ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);
	w = fb_var.xres;
	h = fb_var.yres;
	bpp = fb_var.bits_per_pixel;
	printf("Framebuffer:%dx%d-%dbpp\n",w,h,bpp);
	fbmem = mmap(0,w*h*bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	return 0;
}


