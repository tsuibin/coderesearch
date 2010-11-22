#ifndef _COMM_H_
#define _COMM_H_

#include <stdio.h>
#include <linux/fb.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAXLINE 100
#define SCREEN_DEV "/dev/fb0"
#define DIRPATH "../../../picture/"
#define u32_t unsigned int
#define u8_t unsigned char


struct fb_var_screeninfo fb_var;
typedef struct screenbuf
{
	int w;
	int h;
	int bpp;
	int *fbmem;

}screen_info_t;

extern int scroll_color;
extern int back_color;
extern int scroll;
extern int scroll_head;
extern short width;
extern unsigned char *pic_buf;
extern short height;


typedef void (*callback_t)(unsigned char *pic_buf, unsigned char *buf_32_16);

typedef void (*draw_picture)(screen_info_t screen_inf, char *picture);
typedef unsigned char u_char;
u_char *decode_jpeg (char * filename, short *widthPtr, short *heightPtr);
void get_picture_info(char *picture);
void transform24_32(unsigned char *pic_buf, unsigned char *buf_24_32);
void sircle(screen_info_t screen_inf, char *picture);
void leftup_to_rightdown(screen_info_t screen_inf, char *picture);
void sircle_district(screen_info_t screen_inf, char *picture);
void show_curton(screen_info_t screen_inf, char *picture);

typedef struct link_img
{
	char img_name[MAXLINE];
	struct link_img *next;
}*link_img;

link_img l_img, img_tmp;
extern link_img l_img_head;

#endif
