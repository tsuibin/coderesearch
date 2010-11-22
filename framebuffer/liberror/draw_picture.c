#include "comm.h"
#include "math.h"
#define PI 3.1415926

unsigned char  *buf_24_32;		
unsigned char  *pic_buf;
short height = 0;
short width = 0;

void get_picture_info(char * picture)
{

	printf("~~~~~~~~%s \n",picture); 
	buf_24_32 = decode_jpeg("3.jpg", &width, &height); 

	pic_buf =malloc(width * height * 4);

	//printf("w:%d h:%d\n", width, height);

	transform24_32(buf_24_32, pic_buf);

}


int show_pixel(screen_info_t screen_inf, int x, int y, u32_t  color)
{
		u32_t *p;

		p = (u32_t*)((char*)screen_inf.fbmem + ((screen_inf.w * x + y)*screen_inf.bpp)/8);

		*p = color;

		return 0;
}


void sircle(screen_info_t screen_inf , char * picture)
{
		int i, j;
		u32_t *color1;
		get_picture_info(picture);
		color1 = (u32_t *)pic_buf;//transform char* type to int * type;
		
		for(i = 0; i < screen_inf.h; i++)
				for(j = 0; j < screen_inf.w; j++)
				{
					if(i < height && j < width)
					{
						if((i - screen_inf.h/2)*(i - screen_inf.h/2 ) + (j - screen_inf.w/2)*(j - screen_inf.w/2) <= 90000)
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}
					}
				}
}


void leftup_to_rightdown(screen_info_t screen_inf, char *picture)
{
	int i, j, n1, n2 = 0;	
	u32_t *color1;
	color1 = (u32_t *)pic_buf;//transform char* type to int * type;
	get_picture_info(picture);

	for(n1 = 0; n1 < screen_inf.h; n1 += 5)
	{
		if(n2 < screen_inf.w)
		{
			for(i = 0; i < n1; i++)
			{
				for(j = 0; j < n2; j++)
				{
				
					if(i < height && j < width)
					{
						
						show_pixel(screen_inf, i, j, *(color1+(screen_inf.h - n1 + i - 1) * width + screen_inf.w - n2 + j - 1));
					}
				}
			}
		}
		n2 += 8;
	}

}



void sircle_district(screen_info_t screen_inf, char * picture)
{
		int i, j, m = 1;
		u32_t *color1;
		
		get_picture_info(picture);
		color1 = (u32_t *)pic_buf;//transform char* type to int * type;

		for(;m < 10000;)
		{
		for(i = 0; i < screen_inf.h; i++)
				for(j = 0; j < screen_inf.w; j++)
				{
					if(i < height && j < width)
					{
#if 0

						if((atan(((double)i - height/2)/((double)j - width/2)) <= PI/40*m)&& 
						atan(((double)i - height/2)/((double)j - width/2))  >= 0 )
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}
						if((atan(((double)i - height/2)/((double)j - width/2)) <= PI/2 + PI/40*m)&& 
						atan(((double)i - height/2)/((double)j - width/2))  >= PI/2 )
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}

						if((atan(((double)i - height/2)/((double)j - width/2)) <= PI + PI/40*m)&& 
						atan(((double)i - height/2)/((double)j - width/2))  >= PI )
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}
						if((atan(((double)i - height/2)/((double)j - width/2)) <= (PI/4)*3 + PI/40*m)					&&atan(((double)i - height/2)/((double)j - width/2))  >= (PI/4)*3 )
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}
#endif
						if(((((double)i - screen_inf.h/2)/((double)j - screen_inf.w/2)) <= m/10)&& 
						((((double)i - screen_inf.h/2)/((double)j - screen_inf.w/2))  >= 0 ))
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}
						if(((((double)j - screen_inf.w/2)/((double)i - screen_inf.h/2)) >= -m/10)&& 
						((((double)j - screen_inf.w/2)/((double)i - screen_inf.h/2)) <= 0 ))
						{
							show_pixel(screen_inf, i, j, *(color1+i * width + j));
						}
					}
				}
				if(m < 10)
				{
					m++;
				}
				else if(m < 100)
				{
					m = m + 2;
				}
				else if(m < 1000)
				{
					m = m + 300;
				}
				else 
				m = m + 500;
		}
}

void show_curton(screen_info_t screen_inf, char *picture)
{

		int i, j;
		int count = 0;
		int n1  = screen_inf.h/40;
		int n2  = screen_inf.w/40;
		int m1 = 0, m2 = 0;
		u32_t *color1;
		get_picture_info(picture);
		color1 = (u32_t *)pic_buf;//transform char* type to int * type;
		while(count < 15000)
		{
		m1 =( rand()%40)*n1;
		m2 =( rand()%40)*n2;
		for(i = 0; i < n1; i++)
			for(j = 0; j < n2; j++)
			{
				show_pixel(screen_inf, i + m1, j + m2 , *(color1 + (i + m1)*width + j + m2));
			}

		usleep(50);
			count++;
		}		
}
