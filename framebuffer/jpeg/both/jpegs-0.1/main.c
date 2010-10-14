# include <stdio.h>
# include "common.h"


short wid, height;		//原始图片的宽和高
int init_x;			//初始图片的横坐标
int init_y;			// 初始图片的纵坐标
int pic_w;			//显示图片的宽
int pic_h;			//显示图片的高

int scroll_color = 0xffffff;	// 卷轴的颜色
int back_color = 0x0;		//  背景颜色
int scroll = 60;		//  卷轴的宽度
int scroll_head = 40;		//  卷轴头的高度

void transform24_32 (unsigned char *pic_buf, unsigned char *buf_32_16);	// 将24颜色处理成32位函数
void transform24_16 (unsigned char *pic_buf, unsigned char *buf_32_16);	// 将24颜色处理成16位函数
void init_fb();
void show_pic_1 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, int portion, callback_t tran24_32_16);
void
show_pic_2 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran24_32_16);
void
show_pic_3 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16);
void
show_pic_4 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16);
void
show_pic_5 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16);
void
show_pic_6 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, int portion, callback_t tran_24_32_16);
void
show_pic_7 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, int portion, callback_t tran_24_32_16);
void
show_pic_8 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16);
void
show_pic_9 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16);
void
show_pic_10 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, callback_t tran_24_32_16);
void
show_pic_11 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, callback_t tran_24_32_16);
void
show_pic_12 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, int portion, callback_t tran24_32_16);
void
show_pic_13 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, callback_t tran_24_32_16);
void
show_pic_14 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16);

void search_img();
void free_img_buf ();
Link_img get_img(Link_img  tmp );
u_char *decode_jpeg (char * filename, short *widthPtr, short *heightPtr);

int
main (int argc, char *argv[])
{

  unsigned char *buf;
  int style_num = 1;
  callback_t tran24_32_16;	// 回调函数，用于选择16,32颜色

  init_fb ();			//初始化设备  

  if (bpp == 16)
    tran24_32_16 = (callback_t ) transform24_16;
  else if (bpp == 32)
    tran24_32_16 = (callback_t) transform24_32;
  else
    {
      printf ("Please use sudo  or   bpp is not 32 or 16\n");
      return 0;

    }

  search_img ();		//  寻找目录下的图片名称

  init_x = 0;
  init_y = 0;
  pic_w = w;
  pic_h = h;

  img_tmp = l_img_head->next;
  while (img_tmp != NULL)
    {
      buf = (unsigned char *) decode_jpeg (img_tmp->img_name, &wid, &height);


      switch (style_num)
	{
	case 1:
	  show_pic_1 (buf, init_x, init_y, pic_w, pic_h, 3, tran24_32_16);
	  break;
	case 2:
	  show_pic_2 (buf, init_x - pic_w, init_y - pic_h, pic_w, pic_h,
		      tran24_32_16);
	  break;
	case 3:
	  show_pic_3 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 4:
	  show_pic_4 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 5:
	  show_pic_5 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 6:
	  show_pic_6 (buf, init_x, init_y, pic_w, pic_h, 5, tran24_32_16);
	  break;
	case 7:
	  show_pic_7 (buf, init_x, init_y, pic_w, pic_h, 16, tran24_32_16);
	  break;
	case 8:
	  show_pic_8 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 9:
	  show_pic_9 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 10:
	  show_pic_10 (buf, init_x + scroll, init_y + scroll_head,
		       pic_w - 2 * scroll, pic_h - 2 * scroll_head,
		       tran24_32_16);
	  break;
	case 11:
	  show_pic_11 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 12:
	  show_pic_12 (buf, init_x, init_y, pic_w, pic_h, 8, tran24_32_16);
	  break;
	case 13:
	  show_pic_13 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	case 14:
	  show_pic_14 (buf, init_x, init_y, pic_w, pic_h, tran24_32_16);
	  break;
	default:
	  printf ("其他情况\n");
	  break;
	}
      img_tmp = get_img (img_tmp);
	if(style_num >13)
		style_num = 0 ;

	style_num ++;
if ( img_tmp == NULL)
  img_tmp = l_img_head->next;


}

  free_img_buf ();		//  释放图片名和结点所申请的内存空间


  return 0;

}
