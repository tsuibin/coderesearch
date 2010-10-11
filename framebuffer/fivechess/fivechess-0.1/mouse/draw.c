#include "common.h"
#include "font_8x16.h"

#define MIN(A,B)   ( ((A) < (B) ) ? (A) :(B) )

void draw_alpha_point (int  point_x,int point_y,int color,int a);
int draw_point (int point_x,int point_y,int point_color_32);


int chessboard_init_x = 115+240;  // 棋盘的初始位置
int chessboard_init_y = 115;


/*
 * 函数功能：在屏幕上显示数字
 */

void draw_num(int chess_x,int chess_y,int color,int num)   
{
	int i,j,k;
 for(j = (48+num )* 16,k= 0 ;j<(49+num)*16;j++,k++)    //在fontdata_8x16的数组中0是从48位开始的
        {
                unsigned char c = fontdata_8x16[j];

                for(i = 0 ;i < 8 ;i++)
                {
                        if( (c >> i) & 1)
                                draw_point((chess_x + 8-i),(chess_y+k),color);
			
                }
        }

}

/*
 *函数功能：在棋子上画数字
 */

void draw_chess_num(int chess_array_x ,int chess_array_y ,int chess_color )
{
		if( chess_num  <10)
		{	
		draw_num(chess_array_x * chess_gap + chessboard_init_x - 6 ,chess_array_y * chess_gap + chessboard_init_y - 6 ,chess_color,chess_num);
		}
		else if(chess_num >= 10 && chess_num <100)
		{
		draw_num(chess_array_x * chess_gap + chessboard_init_x   ,chess_array_y * chess_gap + chessboard_init_y - 6 ,chess_color,chess_num%10);
		draw_num(chess_array_x * chess_gap + chessboard_init_x - 8 ,chess_array_y * chess_gap + chessboard_init_y - 6 ,chess_color,chess_num/10);
		}
		else
		{
		draw_num(chess_array_x * chess_gap + chessboard_init_x + 4 ,chess_array_y * chess_gap + chessboard_init_y - 6 ,chess_color,chess_num%10);
		draw_num(chess_array_x * chess_gap + chessboard_init_x - 4 ,chess_array_y * chess_gap + chessboard_init_y - 6 ,chess_color,chess_num%100/10);
                draw_num(chess_array_x * chess_gap + chessboard_init_x - 12 ,chess_array_y * chess_gap + chessboard_init_y - 6 ,chess_color,chess_num/100);
                }


}


/*
 * 函数功能：画横线  
 * line_x ,line_y 为横线的起始坐标值 
 * line_length 画横线的长度  
 * line_color  线的颜色
 */

int draw_wide_line(int line_x,int line_y,int line_length,int  line_color)   
{
        int i;

        for ( i = 0 ; i < line_length ; i++ )
        {
         draw_point(line_x + i,line_y,line_color);
        }
        return 0;
}

/*
 * 函数功能：画具有透明效果的横线  
 * line_x ,line_y 为横线的起始坐标值 
 * line_length 画横线的长度  
 * line_color  线的颜色
 */

int draw_alpha_wide_line(int line_x,int line_y,int line_length,int line_color)  
{
        int i;
	int thick = 200;   //透明的浓度

        for ( i = 0 ; i < line_length ; i++ )
        {
		draw_alpha_point(line_x + i,line_y,line_color,thick);
        }
        return 0;
}

/*
 * 函数功能：画竖线的
 * line_x,line_y 为竖线的起始坐标
 * line_length 画竖线的长度
 * line_color 线的颜色
 */

int draw_height_line(int line_x,int line_y,int line_length,int line_color)
{
	int i;

	for ( i = 0 ;i < line_length; i ++)
	{
		draw_point(line_x ,line_y +i ,line_color);
	}
		return 0;

}


/*
 *函数功能：将32顔色转化为16位
 */



short change_32to16(int color_32)
{
	short color_16;
	short dr,dg,db;

	dr = ( color_32 >> 16) * 0x1f / 0xff;
	dg = ( ( color_32 & 0x0000ff00) >> 8) * 0x3f / 0xff;
	db = ( color_32 & 0x000000ff ) * 0x1f / 0xff;

	color_16 = dr << 11 | dg << 5 | db;
	return color_16;
}




int draw_point (int point_x,int point_y,int point_color_32)   
{
        short * fbmem_16;

        if( point_x > screen_wide  || point_y > screen_height )
                return 0;

        switch ( bpp )
        {
        case 32:
                fbmem[point_x + point_y * screen_wide] = point_color_32;
                break;
        case 16:
                fbmem_16 = (short * )fbmem;
                fbmem_16[point_x + point_y * screen_wide ] = change_32to16( point_color_32 );
                break;
        default:
                printf("其他...\n");
        }

	return 0;

}

/*
 *函数功能：画具有透明效果的点
 */

void draw_alpha_point (int point_x,int point_y,int point_color_32,int thick)   
{
        int srccolor;
	short src_color;
        int dr,dg,db;
        int sr,sg,sb;
	short * fbmem_16;
	short alpha_color;

	if (bpp == 16)
	{
		fbmem_16 = (short *)fbmem;

        src_color = fbmem_16[point_x + point_y * screen_wide ];

        sr = (src_color >> 11) & 0x1f;
        sg = (src_color >> 5) & 0x3f;
        sb = src_color & 0x1f;
	
	alpha_color = change_32to16( point_color_32 );

        dr = (alpha_color >> 11) & 0x1f;
        dg = (alpha_color >> 5 ) & 0x3f;
        db = alpha_color & 0x1f;

	dr = MIN ( 255,(( dr * (255 - thick) + sr * thick ) / 255));
        dg = MIN ( 255,(( dg * (255 - thick) + sg * thick ) / 255));
        db = MIN ( 255,(( db * (255 - thick) + sb * thick) / 255));

        alpha_color = dr << 11 | dg <<5 | db ;
	
	fbmem_16[point_x + point_y * screen_wide ] = alpha_color;  // 为了中途16-32-16 转换麻烦直接在此画点
	}
	else if(bpp == 32)
	{
		srccolor = fbmem[point_x + point_y * screen_wide];
		sr = (srccolor >> 16) & 0xff;
		sg = (srccolor >> 8 ) & 0xff;
		sb = srccolor & 0xff;

		dr = (point_color_32 >> 16) & 0xff;
		dg = (point_color_32 >>8 ) & 0xff;
		db = (point_color_32 ) &  0xff;

	 dr = MIN ( 255,(( dr * (255 - thick ) + sr * thick ) / 255 ));
         dg = MIN ( 255,(( dg * (255 - thick ) + sg * thick ) / 255));
         db = MIN ( 255,(( db * (255 - thick ) + sb * thick ) / 255));

        point_color_32 = dr<<16 | dg <<8 | db ;
		
		draw_point(point_x,point_y,point_color_32);  
	}

}
/*                                                                                                                                                         
 * 函数功能：  画圆的函数,是用线画圆  ，画的是实心圆
 */

void circlepoint(int x,int m,int n,int y,int circle_color) 
{
        draw_wide_line( m - x ,y + n ,2 * x ,circle_color);
        draw_wide_line( m - y, x + n, 2 * y ,circle_color);
        draw_wide_line( m - y, n - x, 2 * y ,circle_color);
        draw_wide_line( m - x, n - y ,2 * x ,circle_color);

}


/*
 *函数功能：运用的是中点画圆法
 */

void midpointcircle(int m,int n,int r,int circle_color)          
{
        int x = 0;
        int y = r;
        int d = 1 - r ;
        int d1 = 3 ;
        int d2 = 2 - r - r ;
        circlepoint( x , m , n , y ,circle_color);
        while( x < y)
        {
                if( d < 0)
                {
                d += d1;
                d1 += 2;
                }
                else
                {
                d += ( d1 + d2);
                d1 += 2;
                d2 += 2;
                y --;
                }
                x++;
                circlepoint(x,m,n,y,circle_color);
        }
}
                                                                                                                                                  

