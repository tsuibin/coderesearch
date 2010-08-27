#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <stdlib.h>
 
#define N 7
#define M 30 //M = grid width, N = chessboard width
#define R 15 //(棋子半径)
#define B 10 //背景超过棋盘长度
#define MW 10 //鼠标正方形显示宽度/2
extern struct fb_var_screeninfo vinfo;
extern struct fb_fix_screeninfo finfo;
extern long screensize;
extern int mx;
extern int my;
extern short * fbp;

extern void draw_background (void);
extern void draw_chessboard (void);
extern short * init_fb (int fp);
extern void draw_chesspiece (void);
extern int get_mouse_position (void);
extern void init_mouse (void);
extern void close_mouse (void);
extern void show_mouse (void);
