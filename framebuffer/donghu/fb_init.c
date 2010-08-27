#include "five.h"
/*
* 初始化fb设备文件
* 注意需要把分辨率设置为1024*768 
* 不然话出来的东西可能不一样
*/
short * init_fb (int fp)
{
	short * fbp;
	fp = open ("/dev/fb0", O_RDWR);
	
	if (fp < 0)
	{
		printf ("Error: Can not open framebuffer device\n");
		exit (1);
	}

	if (ioctl (fp, FBIOGET_FSCREENINFO, &finfo))
	{
		printf ("Error reading fixed information\n");
		exit (2);
	}

	if (ioctl (fp, FBIOGET_VSCREENINFO, &vinfo))
	{
		printf ("Error reading variable information\n");
		exit (3);
	}

	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	fbp = (short *) mmap (0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fp, 0);

	if ((int) fbp == -1)
	{
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit (4);
	}

	return fbp;
}
