#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <fcntl.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <jpeglib.h>
#include <jerror.h>

//#define N 1024
#define STEP 30
#define RANGE 15
#define XSTEP 20
#define YSTEP 20

#define X_START 355
#define Y_START 115
#define X_END (X_START + (XSTEP - 1) * STEP)
#define Y_END (Y_START + (YSTEP - 1) * STEP)

#define PLAYER1 1
#define PLAYER2 2

//int 	display_pic (char * filename);
/*
void	draw_chessboard (int color);
int 	draw_chess(int x1,int y1,int radius,int color);
void	set_background (int h, int v,int color);

void	draw_cross (int h,int v,int len,int color);
void	draw_circle (int h,int v,int radius,int color);
//void	draw_rectangle (int h,int v,int len,int width,int color);
void	draw_one_line (int h_start,int v_start,int h_end,int v_end,int color);

void	draw_mouse(int x,int y);
void	get_mouse_color (int h,int v,int len);
void	recover_mouse (int h,int v,int len);

int 	fb_pixel(int x, int y, unsigned int color);

int 	init_mouse (void);
int 	read_mouse (int fd);

int 	fb_close(void);
int 	fb_munmap(void);

int		adjust(int who);
*/
void	think_chess(void);
#if 0
extern  unsigned int 	*fbmem;
extern  unsigned int    fb_width;
extern  unsigned int    fb_height;
extern  unsigned int    fb_depth;
//extern  unsigned int	color_buf[N];
extern	int 		cx,cy;	
extern  int 		chessboard[XSTEP][YSTEP];
extern	int		mouse_color;
extern 	int 	num;
#endif

#endif
