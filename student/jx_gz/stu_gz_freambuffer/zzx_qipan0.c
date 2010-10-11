#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
	
int w,h ,bpp;

short *fbmem;

void pm_print(void)
{
	int i,j;

	for (i = 300; i <= 900;i += 30)
	{
		for (j = 80;j <=680; j ++)
			*(fbmem + j * w + i) = 0x0CB0;
	}
	for (i = 80; i <= 680; i += 30)
	{
		for (j = 300;j <= 900; j++)
			*(fbmem + i * w + j) = 0x0CB0;
	}
	return ;
}

int main(int argc , char *argv[])	
{
	int fd;
	struct fb_var_screeninfo fb_var;
	int i = 0 ;

	fd = open("/dev/fb0",O_RDWR);
	ioctl (fd,FBIOGET_VSCREENINFO,&fb_var);
	w   = fb_var.xres;
	h   = fb_var.yres;
	bpp = fb_var.bits_per_pixel;
	printf ("Framebuffer %d*%d-%dbpp\n",w,h,bpp);

	fbmem = mmap (0,w*h*bpp/8,PROT_WRITE|PROT_READ,
		        MAP_SHARED,fd,0);
	pm_print();
//for (;i < 400;i++)
//		*(fbmem + 10  * w + 200 + i) = 0xFF00; 

//	for (i = 0;i < 400;i++)
//		*(fbmem + (15 + i) * w + 200 + i) = 0xFFFF; 
	
//	*(fbmem + 20 * w + 600) = 0xF800;
	return 0;
}

