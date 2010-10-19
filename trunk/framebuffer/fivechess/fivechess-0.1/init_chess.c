#include "common.h"


int draw_wide_line(int line_x,int line_y,int line_length,int  line_color); 
int draw_alpha_wide_line(int line_x,int line_y,int line_length,int line_color) ; 
int draw_height_line(int line_x,int line_y,int line_length,int line_color);

//#define chess_line_num  15  // 棋盘的边数        相关定义在common.h文件中
int chessboard_init_x = 115+240;  // 棋盘的初始位置
int chessboard_init_y = 115;
int chess_gap = 30;		//格子之间的间距
int chess_num = 0 ;             //棋子的数量

int chess_one_color  = 0xff0000;    //棋子1的颜色
int chess_two_color  = 0xff;        //   棋子2 的颜色
int circle_r = 14;              //  棋子的半径

int chessboard_back_color = 0x00ffffff;          //背景颜色  
int chessboard_line_color = 0xffff00;          // 棋盘线的颜色

int array_chess[chess_line_num][chess_line_num];
int start = 1;                   //  1 表示红方先走，0表示蓝方先走
int PLAYER_NUM = 2;               //当PLAYER_NUM = 1时为人机对战模式(aka522 vs human)，当PALYER_NUM =2时为机机对战模式(aka522 vs mxcai2010) 其他情况尚未定义


/*
 * 函数功能: 画棋盘
 */

void draw_chess (void )   // 画棋盘
{
	int i,j;

	for(i = 0;i < screen_height ;i++ )
                draw_alpha_wide_line(0,i,screen_wide,chessboard_back_color);

  for (i = 0;i < chess_line_num; i++)
    {
      draw_wide_line (chessboard_init_x, chessboard_init_y + i * chess_gap, (chess_line_num - 1 ) * chess_gap, chessboard_line_color);
      draw_height_line (chessboard_init_x + i * chess_gap, chessboard_init_y, (chess_line_num - 1) * chess_gap,chessboard_line_color);
    }
	for( i = 0 ;i < chess_line_num ;i ++)
		for( j = 0 ;j < chess_line_num ;j ++)
			array_chess[i][j] =0;

}
