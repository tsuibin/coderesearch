#include "five.h"
/*#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <stdlib.h>
*/

void draw_chessboard (void)
{
	long x = 0L, y = 0L;
	long location = 0L;
	int i = 0, j = 0;
	
	x = vinfo.xres / 2;
	y = vinfo.yres / 2;
	location = (x - N * M) + (y - N * M) * vinfo.xres;
	
	for (i = 0; i < 2 * N + 1; i++)
	{
		for (j = 0; j <= 2 * N * M; j++)
		{
			*(fbp + location + j) = 0x001f;
		}
		location += M * vinfo.xres; 
	}

	location = (x - N * M) + (y - N * M) * vinfo.xres;
	for (i = 0; i< 2 * N + 1; i++)
	{
		for (j = 0; j <= 2 * N * M; j++)
		{
			*(fbp + location + j * vinfo.xres) = 0x001f;
		}
		location += M;
	}
}



			
