#include "five.h"

void draw_background (void)
{
	long x = 0L, y = 0L;
	long location = 0L;
	int i = 0, j = 0;
		
	x = vinfo.xres / 2;
	y = vinfo.yres / 2;
	location = (x - N * M - B) + (y - N * M - B) * vinfo.xres;
	
	for (i = 0; i <= 2 * (N * M + B); i++)
	{
		for (j = 0; j <= 2 * (N * M + B); j++)
		{
			*(fbp + location + j) = 0x07e0;
		}
		location += vinfo.xres;
	}
}



			
