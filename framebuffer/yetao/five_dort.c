#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#define white 0xffff
#define block 0x0000
int wigth,high,bpp;//屏幕的宽高和像数
struct fb_var_screeninfo fb_var;
unsigned short *fb_short;
short  buf[144];
int fb,fd;
int cx,cy;//鼠标坐标
void get_back(int,int);
void back_back(int,int);

int init_fb(void)//获取显示的地址
{
	if(fb < 0)
	{
		printf("Can't open device fb0\n");
		printf("try:sudo \n");
		return -1;
	}
	ioctl(fb,FBIOGET_VSCREENINFO,&fb_var);//获取设备分辨率
	wigth = fb_var.xres;
	high = fb_var.yres;
	bpp =  fb_var.bits_per_pixel;
////////////////////////////////////////////////////////	
	cx = wigth/2;//鼠标位置初始化
	cy = high/2;
///////////////////////////////////////////////////////
	printf("Framebuffer:%d x %d y %d bpp \n",wigth,high,bpp);

	fb_short = mmap(NULL,wigth*high*bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fb,0);////////每个像数点的映射位置，在Framebuffer里面
	return 0;
}
void fb_point(int x,int y,short color)//获取要写入像数点起始位置
{
	fb_short[y*wigth + x] = color;
}

void fb_back(int x,int y,int r)//画棋盘底层背景
{
	
	int i,j;
	for(i = 0;i < 600;i++) for(j = 0;j < 640;j++) {
			fb_point(x+i,y+j,0x8686);
		}
}
void fp_drow()///画棋盘线条
{
	int i,j;
		for(i = 0; i < 560;i++)///14(40) *15(40)
			for(j = 0;j <= 600;j+=40)
				fb_point(350+i,80+j,0xf800);

		for(i = 0; i < 600;i++)///14(40) *15(40)
			for(j = 0;j <= 560;j+=40)
				fb_point(350+j,80+i,0xf800);
}
void fb_chessman(int x,int y,int color)///画棋盘棋子
{
	int i,j;
	int r = 18;
	for(j = y -r;j<= y+r;j++)
	{
		for(i = x -r;i <= x+r;i++)
		{
			if((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
				fb_point(i,j,color);
		}
	}

}
int open_mouse(void)/////打开鼠标文件
{
	int fm;
	char buf[8];

	fm =open("/dev/input/mice",O_RDONLY);
	if(!fm)
	{
		printf("Failed to open mouse!\n");
		return -1;
	}
	return fm;
}

int read_mouse(int fm)/////读取鼠标状态
{
	char buf[8];
	read(fm,buf,8);
	int dx,dy;
//	dy = buf[2] - ((buf[0]&0x20)?256:0);
	

	dx = buf[1];//////获取鼠标移动相对位置
	dy = buf[2];
	cx += dx;///获取鼠标相对位移
	cy -= dy;
	if(cx < 8)///鼠标边界判断
		cx = 8;
	if(cx > wigth-8)
		cx = wigth-8;
	if(cy < 8)
		cy = 8;
	if(cy > high-30)
		cy = high-30;
}
void drow_mouse(int x,int y,short color)//////画鼠标图案
{
	int i,j;
	int r = 6;
	for(j = y -r;j<= y+r;j++)
	{
		for(i = x -r;i <= x+r;i++)
		{
			if((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
			fb_point(i,j,color);
		}
	}

}

void get_back(int c_x,int c_y)///获取鼠标中心周围信息并移动前将背景复制
{
	int r = 6;
	int x = c_x - r;
	int y = c_y - r;
	int i,j,k = 0;

	for(j = y ;j <= y + 2*r ; j++)
	{
		for(i = x  ;i <= x + 2*r ; i++)
		{
			buf[k++] = fb_short[j*wigth + i];
		}
	}

}

void back_back(int c_x,int c_y)//将原背景还原
{
	char r = 6;
	int x = c_x - r;
	int y = c_y - r;
	int i,j,k= 0;

	for(j = y ;j <= y + 2*r ; j++)
	{
		for(i = x ;i <= x + 2*r ; i++)
		{
			fb_short[j*wigth+i] = buf[k++];
		}
	}
}
void init_mouse1(int *c_x,int *c_y,int *pret)
{
	*pret = open_mouse();
	read_mouse(*pret);
	get_back(cx,cy);
	*c_x = cx;
	*c_y = cy;
	drow_mouse(cx,cy,0xe050);
}

void init_mouse2(int *c_x,int *c_y,int *pret)
{		
//		back_back(c_x,c_y);//********此语句放此地则结果差别很大
		read_mouse(*pret);
		back_back(*c_x,*c_y);///********
		get_back(cx,cy);
		
		drow_mouse(cx,cy,0xe050);
		*c_x = cx;
		*c_y = cy;

		printf("cx =%d cy = %d\n",cx,cy );

}
char click_chessman(void)
{
	char click;
	int fm;
	char buf[8];
	
	fm = open_mouse();
	read(fm,buf,8);
	click =0x07&buf[0];
	printf("click = %x\n",click);

	return click;	
}

void find_dort(int *c_x,int *c_y)///找出棋盘交叉位置并在最近交叉位置下子
{
	char click;
	int x,y;
	int xa,ya;
	int x_b,y_b;
	int fm;
	char buf[8];
	int *pret;

	x = cx - 350;
	y = cy - 80;
	xa = x/40;
	ya = y/40;
	x_b = x%40;
	y_b = y%40;
	
	if( x_b <= 20)
	{
		*c_x = xa*40 + 350;
	}
	else
	{
		*c_x = (xa + 1 )*40 + 350;
	
	}
	if(y_b <= 20)
	{
		*c_y = ya*40 + 80;
	}
	else
	{
		*c_y = (ya + 1)*40 + 80;
	}


//	if( 330<= *c_x && *c_x <= 910&& 60<= *c_y && *c_y <=700 )
/*	
	click = click_chessman();////////////////////////
	if(0x01 == click )
		fb_chessman(*c_x,*c_y,white);	
	if(0x02 == click )
		fb_chessman(*c_x,*c_y,block);
*/	
	
}
void delay(void)
{
	int i,j;
	for(i = 0;i <50;i++)
		for(j = 0;j < 100 ;j++);

}

int main(int argc, char *argv[])
{
	char click;
	int ret;
	int retmouse;
	int i,j,m,n;
	int c_x,c_y;
	int x_dort,y_dort;

	int *pc_x = &c_x;
	int *pc_y = &c_y;
	int *pret = &retmouse;

	fb = open("/dev/fb0",O_RDWR);
	ret = init_fb();
	if(ret < 0)
		return -1;
	
	fb_back(330,60,560);
	fp_drow();

	init_mouse1(pc_x,pc_y,pret);
	
/*	retmouse = open_mouse();
	read_mouse(retmouse);
	get_back(cx,cy);
	c_x = cx;
	c_y = cy;
	drow_mouse(cx,cy,0xe050);
*/
	while(1)
	{


			click = click_chessman();	
			while(click == 0)
			{
				init_mouse2(pc_x,pc_y,pret);/////////////////////////////////////////////
		//		delay();
				click = click_chessman();
			}
			if(0 != click)
			{
				back_back(cx,cy);
				find_dort(&x_dort,&y_dort);
				get_back(cx,cy);
				if( 330<= x_dort && x_dort <= 910&& 60<= y_dort && y_dort <=680 )
				{
					if(0x01 == click )
					{
						delay();
					//	while((click = click_chessman()) );
						
						fb_chessman(x_dort,y_dort,white);	
						get_back(cx,cy);
					}
				
					else if(0x02 == click )
					{
						
						delay();
					//	while((click = click_chessman()));	
						
						fb_chessman(x_dort,y_dort,block);
						get_back(cx,cy);
					}
					else
					{
						printf("please down\n");
					}
				
				}
				c_x = cx;
				c_y = cy;
				back_back(c_x,c_y);
		//		click = click_chessman();	
	
			}
//		init_mouse2(pc_x,pc_y,pret);
/*		read_mouse(retmouse);
		back_back(c_x,c_y);
		get_back(cx,cy);
		drow_mouse(cx,cy,0xe050);
		c_x = cx;
		c_y = cy;
		printf("cx =%d cy = %d\n",cx,cy );
*/		
	}
	return 0;
}
