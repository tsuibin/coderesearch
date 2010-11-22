#include "comm.h"

int init_framebuf(screen_info_t *screen_inf)
{
	int fb ;
	fb = open(SCREEN_DEV, O_RDWR);
	if(fb < 0)
	{
		perror("SCREEN_DEV:");
		return -1;
	}

	ioctl(fb, FBIOGET_VSCREENINFO, &fb_var);

	screen_inf->w = fb_var.xres;
	screen_inf->h = fb_var.yres;
	screen_inf->bpp = fb_var.bits_per_pixel;

	printf("framebuf inf:%d\t%d\t%d\n", screen_inf->w,screen_inf->h, screen_inf->bpp);
	screen_inf->fbmem = mmap(NULL,screen_inf->w*screen_inf->h*screen_inf->bpp/8, PROT_WRITE|PROT_READ, MAP_SHARED, fb, 0);
	return 0;

}

