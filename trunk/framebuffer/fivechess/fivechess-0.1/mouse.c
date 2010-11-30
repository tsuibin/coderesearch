#include "common.h"
#include "mouse.h"
#include <unistd.h>




int array_x = 0;
int array_y = 0;
int  mouse_buf[C_WIDTH * C_HEIGHT];
int save_mouse_cx,save_mouse_cy;
int draw_point (int point_x,int point_y,int point_color_32); 

/* 
 * 函数功能：初始化鼠标
 */

int init_mouse(void)       
{
	int fd;
	fd = open("/dev/input/mice",O_RDONLY);
	return fd;
}

/*
 * 函数功能：读鼠标的值
 */

int read_mouse(int fd)
{
	unsigned char buf[8];
	int mouse_dx,mouse_dy;
	int ret = -1;
	static int button = 0;

	read(fd,buf,8);    // 读鼠标值到buf中
printf("~~~~~~~~~~~~~~~~~~~~~\n"); 
	printf("buf0 %d\n",buf[0]); 
	printf("buf1 %d\n",buf[1]); 
	printf("buf2 %d\n",buf[2]); 
	printf("buf3 %d\n",buf[3]); 
	printf("buf4 %d\n",buf[4]); 
	printf("buf5 %d\n",buf[5]); 
	printf("buf6 %d\n",buf[6]); 
	printf("buf7 %d\n",buf[7]); 

	mouse_dx = buf[1] - ((buf[0] & 0x10 ) ? 256 : 0);
	mouse_dy = -buf[2] + ((buf[0] & 0x20) ? 256 : 0);
	
	mouse_cx += mouse_dx;   //   mouse_cx 的初始值为 屏幕宽度的一半 
	mouse_cy += mouse_dy;  //    mouse_cy 的初始值为 屏莫高度的一半  cx ,cy 的初始值在 fb.c 的函数中
	if(mouse_cx < 0)
		mouse_cx = 0;

	if(mouse_cx > screen_wide - 20 )        //减去20的原因是处理边界问题
		mouse_cx = screen_wide - 20;

	if(mouse_cy < 0)
		mouse_cy = 0;

	if(mouse_cy > screen_height - 20)
		mouse_cy = screen_height - 20;              //   处理边界问题

	if(buf[0] & 0x1)             //   判断鼠标左键的值
	{
		button = 1;          //处理鼠标BUG
	}
	else if(button == 1)
	{
		button = 0;
		return 0;
	
	}
	else
	{
	;
	}

	return ret;
		
}

/*
 * 函数功能：画鼠标
 */

int draw_mouse (void)             
{
	int i=0;
	
	for( i = 0;i <  C_WIDTH * C_HEIGHT ; i++)
	{
		if( cursor_pixel[i] == 0x0)
			draw_point( mouse_cx + ( i % C_WIDTH ) , mouse_cy + ( i / C_WIDTH ) , 0x00ffffff);
		else if ( cursor_pixel[i] == 0xFFFF)
			draw_point( mouse_cx + ( i % C_WIDTH ) , mouse_cy + ( i / C_WIDTH ) , 0x00000000);
		else
		{
		;
		}

	}
		return 0;			

}

/*
 *函数功能：判断鼠标当前所在的点的坐标值是否在棋盘内
 *          如果是在棋盘则把鼠标点处的值转化为棋盘的数组下标值
 */

int  check_mouse_pix( void)    
{

	int chess_max_border_x = chessboard_init_x + chess_gap/2 + (chess_line_num - 1) * chess_gap ;
	int chess_max_border_y = chessboard_init_y + chess_gap/2 + (chess_line_num - 1) * chess_gap ;
	int chess_min_border_x = (chessboard_init_x - chess_gap / 2);
	int chess_min_border_y = (chessboard_init_y - chess_gap / 2);

if (mouse_cx < chess_max_border_x  && mouse_cy < chess_max_border_y && mouse_cx > chess_min_border_x  && mouse_cy > chess_min_border_y)
		{	
			array_x = (mouse_cx - chess_min_border_x) / chess_gap;
			array_y = (mouse_cy - chess_min_border_y) / chess_gap;
			return 0;
		}
	else
		return 1;

}




void save_mouse_buf (void )
{
        short * fbmem_16;

        save_mouse_cx = mouse_cx;
        save_mouse_cy = mouse_cy;
        int i=0;
        for(i = 0;i<C_WIDTH * C_HEIGHT;i++)
                if(bpp == 16)
                {
                        fbmem_16 = (short *)fbmem;
                mouse_buf[i] = fbmem_16[save_mouse_cx + (i % C_WIDTH ) + ( save_mouse_cy + (i / C_WIDTH )) * screen_wide];
                }
                else if(bpp == 32)
                {
                         mouse_buf[i] = fbmem[save_mouse_cx + ( i % C_WIDTH ) + ( save_mouse_cy + (i / C_WIDTH )) * screen_wide];
                }
                else
                {
		;
                }


}


void recover_mouse_buf (void )
{
        short * fbmem_16;
        int i=0;

        for( i = 0;i < C_WIDTH * C_HEIGHT;i++)
		{
                if(cursor_pixel[i] != 0XFFFFFFFF)
				{
                        if(bpp ==16 )
                        {
                                fbmem_16 = (short *) fbmem;
                                fbmem_16[save_mouse_cx + ( i % C_WIDTH ) + ( save_mouse_cy + i / C_WIDTH ) * screen_wide ] = mouse_buf[i];
                        }
                        else if(bpp ==32)
                        {
                                fbmem[save_mouse_cx + ( i % C_WIDTH ) + (save_mouse_cy + i / C_WIDTH ) * screen_wide ]= mouse_buf[i];

                        }
				}
			else
			{
			;
			}
		}
}
