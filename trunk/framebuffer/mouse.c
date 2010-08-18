#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // gcc link with -lm
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <unistd.h>
//1 init view
//2 init mouse
//3 read data，draw point
//4 while
//
typedef struct point{
	int x;
	int y;
} POINT;


static int w,h,bpp;
static int cx,cy;
static struct fb_var_screeninfo fb_var;
static unsigned short *fb_mem;	//framebuffer设置的为8位
static int fb ,fd;

int	init_fb (void)
{
	//获取显示的地址
	//打开设备
	//获取设备的信息
	//获取地址
	if (fb<0)
	{	
		printf("Can't open device fb0\n");
		printf("try:sudo \n");//尝试使用sudo
		return -1;
	}
	//出错处理
	ioctl (fb,FBIOGET_VSCREENINFO,&fb_var); //get device 分辨率，宏在fb.h中/usr/
	w	= fb_var.xres;
	h	= fb_var.yres;
	bpp	= fb_var.bits_per_pixel;//颜色位:位，每像素

	printf("Framebuffer : %d x %d y - %d bpp\n",w,h,bpp);

	fb_mem = mmap(NULL,(w*h*bpp/8),PROT_READ|PROT_WRITE,MAP_SHARED,fb,0);

	cx = w/2;
	cy = h/2;
//	cx = w;
//	cy = h;


	return 0;
}


//draw point
void fb_point (int x,int y,short color)
{
//	printf("%d\n",color); 
	//fb_mem[y*w+x]=color;
	int i = 1680*1050;
	for (;i > 0;i--)
	{
		fb_mem[i]=color;
	}
}

//mouse operstion
int init_mouse(void)
{
	fd=open("/dev/input/mice",O_RDONLY);

	if (fd<0)
	{
		printf("open /dev/input/mice error");
		return -1;	
	}

	return fd;

}



int read_mouse(int fd)
{
	unsigned char buf[8];
	read(fd,buf,8);
	int dx,dy;

	dx = buf[1]-((buf[0]&0x10)?256:0);
	dy = -buf[2]+((buf[0]&0x20)?256:0);
	//printf ("cx = %d, cy = %d,dx = %d,dy = %d\n",cx,cy,dx,dy);
	cx += dx;
	cy += dy;	
	printf ("cx = %d, cy = %d,dx = %d,dy = %d\n",cx,cy,dx,dy);

	if (cx < 0)
	{
		cx = 0;
	}
	if (cx > w)
	{
		cx = w;
	}
	if (cy < 0)
	{
		cy = 0;
	}
	if (cy > h)
	{
		cy = h;
	}
	if (buf[0]&0x1)
	{
		return 0;	
	}
}

void fb_circle(POINT center, int radius, short color)
{

	int p_x,p_y;
	int x,y,tmp;
	for(x=center.x-radius; x<=center.x+radius; x++)
	{
		p_x = x;
		tmp = sqrt((float)radius*radius-(x-center.x)*(x-center.x));
		p_y = center.y + tmp;
		fb_point(p_x,p_y,color);
		p_y = center.y - tmp;
		fb_point(p_x,p_y,color);
	}
	for(y=center.y-radius; y<=center.y+radius; y++)
	{
		p_y = y;
		tmp = sqrt((float)radius*radius-(y-center.y)*(y-center.y));
		p_x = center.x + tmp;
		fb_point(p_x,p_y,color);
		p_x = center.x - tmp;
		fb_point(p_x,p_y,color);
	}

}

int  main  (void)
{
	int ret;
	int ret1;	
	int i;

	fb = open("/dev/fb0",O_RDWR);
	ret = init_fb();
	if (ret < -1)
	{
		return -1;
	}
	ret = init_mouse();
	while(1)
	{
		ret1=read_mouse(ret);

		if (ret1==-1) 
			continue;

	//	for(i = 300;i<=700;i++)
	//		fb_point(i,400,0XF800);
	//	for(i=400;i<1000;i++)
	//		fb_point(300,i,0XF800);
	
	fb_point(cx,cy,0XF800);
					//fb_point(cx,cy+1,0XF800);

		//POINT center = { 600, 500};
		//int radius = 100;
		//fb_circle(center, radius, 0xF800);

	}
	return  0;
}


