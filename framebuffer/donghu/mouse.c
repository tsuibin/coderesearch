#include "five.h"

static int fd;
/*
static  char color_hidbymouse[MW * 2 + 1][MW * 2 + 1];
保存颜色信息的数组有两字节，应该使用short类型数组
*/
static short color_hidbymouse[MW * 2 + 1][MW * 2 + 1];

/*
*初始化鼠标设备
*/
void init_mouse (void)
{
	fd = open ("/dev/input/mice", O_RDONLY);

	if (fd < 0)
	{
		printf ("Open /dev/input/mice error\n");
		printf ("use \"sudo ./a.out\" to try again\n");
		exit (5);
	}
}

/*
* 获取鼠标坐标
* 并对越界进行限制
*/
int get_mouse_position (void)
{
	//unsigned char buf[8];
	int dx, dy, mx1, my1;
	char buf[3];
	int i, j, k, l;
	long location = 0L;
	mx1 = mx;
	my1 = my;

	//read (fd, buf, 8);
	read (fd, buf, 3);
	//dx = buf [1] - ((buf[0] & 0x10) ? 256 : 0);
	//dy = -buf [2] + ((buf[0] & 0x20) ? 256 : 0);
	dx = buf[1];
	dy = -buf[2];
	mx += dx;
	my += dy;

	for (i = mx1 - MW, k = 0; i <= mx1 + MW; i++, k++)
	{
		for (j = my1 - MW, l = 0; j <= my1 + MW; j++, l++)
		{
			if (i <= vinfo.xres - 1 && j <= vinfo.yres - 1 && i >= 0 && j >= 0)
			{
				location = i + j * vinfo.xres;
				*(fbp + location) = color_hidbymouse[k][l];
			}
		}
	}

	if (mx < 0)
	{
		mx = 0;
	}
	if (mx > vinfo.xres - 1)
	{
		mx = vinfo.xres - 1;
	}
	if (my < 0)
	{
		my = 0;
	}
	if (my > vinfo.yres - 1)
	{
		my = vinfo.yres - 1;
	}
	
	if (buf[0] & 0x01) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void close_mouse (void)
{
	close (fd);
}
	
/*
* draw the mouse
*/
void show_mouse (void)
{
	int i, j, k, l;
	long location = 0L;

	for (i = mx - MW, k = 0; i <= mx + MW; i++, k++)
	{
		for (j = my - MW, l = 0; j <= my + MW; j++, l++)
		{
			if (i <= vinfo.xres - 1 && j <= vinfo.yres - 1 && i >= 0 && j >= 0)
			{
				location = i + j * vinfo.xres;
				color_hidbymouse[k][l] = *(fbp + location);
				*(fbp + location) = 0xf800;
			}
		}
	} 
}

	
