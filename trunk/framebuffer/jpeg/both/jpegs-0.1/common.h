#ifndef __common_h__
#define __common_h__

/*
   全局变量声明 回调函数类型定义
 */


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

extern int *fbmem;                  
extern int bpp,w,h;
extern short wid,height;
typedef void ( * callback_t)(unsigned char * pic_buf,unsigned char * buf_32_16);
extern int scroll_color;
extern int back_color ;
extern int scroll ;
extern int scroll_head ;

typedef struct link_img{
	char * img_name;
	struct link_img * next;
} * Link_img;

Link_img l_img, img_tmp ,l_img_head;


#endif
