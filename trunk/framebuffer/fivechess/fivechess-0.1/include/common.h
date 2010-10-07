#ifndef __common_h__
#define __common_h__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

#define chess_line_num  20

extern int mouse_cx,mouse_cy;              //鼠标在屏幕上的坐标位置
extern int ret;             
extern int screen_wide,screen_height,bpp;              //    屏幕的宽度，高度，以及是16位，24位还是32位
extern int * fbmem;                  
extern int chessboard_init_x;                 // 棋盘的初始位置
extern int chessboard_init_y;		
extern int chess_gap ;                 // 棋盘间的空格  
extern int chess_one_color;         // 人下棋时的棋子的颜色
extern int chess_two_color;         // 电脑下棋时的棋子的颜色
extern int circle_r;                //   棋子的半径
extern int array_chess[chess_line_num][chess_line_num];   // 棋盘数组，我方的数值为1，电脑为2 ,空棋为 0
extern int chess_num;                        //   计算一共下棋的个数
extern int array_x,array_y;                    //   棋盘数组的横，纵坐标值
extern int direction_var[4][4];                         // 四个方向的坐标值
extern int start;
extern int save_cx;  // 保存鼠标上次位置的鼠标 
extern int save_cy;
extern int cx,cy;                      // 鼠标的值
extern int array1,array2;
extern int PLAYER_NUM;

#endif
