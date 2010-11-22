
#include "comm.h"

void transform24_32(unsigned char *pic_buf, unsigned char *buf_24_32)
{
	int i,j;
	unsigned int color_32;
	
	for(i = 0; i < height ; i++)
	{
		for(j = 0; j < width ; j++)
		{
			unsigned char dr, dg, db;
			unsigned int *tran_32;
			tran_32 = (unsigned int *)buf_24_32;

			dr = pic_buf[(i * width + j) * 3];
			dg = pic_buf[(i * width + j) * 3 + 1];
			db = pic_buf[(i * width + j) * 3 + 2];

			color_32 = dr<<16 | dg<<8 | db;
			tran_32[i * width + j] = color_32;
		}
	}

		free(pic_buf);

}
