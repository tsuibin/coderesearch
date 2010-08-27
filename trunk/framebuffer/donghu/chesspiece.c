#include "five.h"

void draw_chesspiece (void)
{
	long x = 0L, y = 0L;
	long location = 0L;
	int i = 0, j = 0;

	x = vinfo.xres / 2;
	y = vinfo.yres / 2;
	
	for (i = x - R; i <= x + R; i++)
	{
		for (j = y - R; j <= y + R; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= R * R)
			{
				location = i + j * vinfo.xres;
				*(fbp + location) = 0xffff;
			}
		}
	}
}
