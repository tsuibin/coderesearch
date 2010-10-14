#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include <math.h>
#include <unistd.h>




unsigned short change16 (unsigned int color);	// 将32色彩转化为16色彩的
void draw_back (int init_x, int init_y, int leng_w, int leng_h, unsigned int color);


void
transform24_16 (unsigned char *pic_buf, unsigned char *buf_24_16)
{
  int i, j;
  unsigned short color_16;

  for (i = 0; i < height; i = i + 1)
   {
    for (j = 0; j < wid; j = j + 1)
      {
	unsigned char dr, dg, db;
	unsigned short *tran_16;
	tran_16 = (unsigned short *) buf_24_16;

	dr = (pic_buf[(i * wid + j) * 3] * 0x1f) / 0xff;
	dg = (pic_buf[(i * wid + j) * 3 + 1] * 0x3f) / 0xff;
	db = (pic_buf[(i * wid + j) * 3 + 2] * 0x1f) / 0xff;

	color_16 = dr << 11 | dg << 5 | db;
	tran_16[i * wid + j] = color_16;
      }
    }
	
	free(pic_buf);
}

void
transform24_32 (unsigned char *pic_buf, unsigned char *buf_24_32)
{
  int i, j;
  unsigned int color_32;

  for (i = 0; i < height; i = i + 1)
   {
    for (j = 0; j < wid; j = j + 1)
      {
	unsigned char dr, dg, db;
	unsigned int *tran_32;
	tran_32 = (unsigned int *) buf_24_32;

	dr = pic_buf[(i * wid + j) * 3];
	dg = pic_buf[(i * wid + j) * 3 + 1];
	db = pic_buf[(i * wid + j) * 3 + 2];

	color_32 = dr << 16 | dg << 8 | db;
	tran_32[i * wid + j] = color_32;
      }
    }

	free(pic_buf);
}


void
show_pic_1 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, int portion, callback_t tran24_32_16)
{
  int i = 0;
  int j = 0;
  int k = 0;
  int w_num = 0;
  int h_num = 0;
  unsigned char *buf_32_16;
  unsigned  short *fbmem_16;

  fbmem_16 = (unsigned short *) fbmem;

  buf_32_16 = (unsigned char *) malloc (wid * height * bpp / 2);	// 为了适应不同的环境上

  tran24_32_16 (pic_buf, buf_32_16);

  for (k = 1; k <= portion; k++)
    {
      for (j = 0; j < leng_w; j++)
	{
	  for (i = (k - 1) * leng_h / portion; i < k * leng_h / portion; i++)
	    {
	      w_num = j * wid / leng_w;
	      h_num = i * height / leng_h;
	      if (bpp == 16)
		{
		  unsigned short *tran_16 = (unsigned short *) buf_32_16;
		  fbmem_16[init_x + j + (i + init_y) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		  unsigned int *tran_32 = (unsigned int *) buf_32_16;
		  fbmem[init_x + j + (i + init_y) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else
		{

		}
	    }
	  usleep (1000);
	}
    }
  free (buf_32_16);

}


void
show_pic_2 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran24_32_16)
{
  int i = 0;
  int j = 0;
  int k = 0;
  int w_num = 0;
  int h_num = 0;
  int tmp_k = 0;

  unsigned char *buf_24_32_16;
  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  unsigned short *fbmem_16;
  fbmem_16 = (unsigned short *) fbmem;

  tran24_32_16 (pic_buf,buf_24_32_16);


  for (k = 0; k < leng_w; k = k + 5)
    {
      for (j = 0; j < leng_w; j++)
	{
	  for (i = 0; i < leng_h; i++)
	    {

	      tmp_k = k * leng_h / leng_w;

	      if ((init_x + k + j) >= (init_x + leng_w)
		  && (init_x + k + j) <= (init_x + 2 * leng_w)
		  && (init_y + i + tmp_k) > (init_y + leng_h)
		  && (init_y + i + tmp_k) < (init_y + 2 * leng_h))
		{
		  w_num = j * wid / leng_w;
		  h_num = i * height / leng_h;

		  if (bpp == 16)
		    {
		      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;

		      fbmem_16[init_x + k + j + (i + init_y + tmp_k) * w] =
			tran_16[w_num + h_num * wid];
		    }
		  else if (bpp == 32)
		    {
		      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;

		      fbmem[init_x + k + j + (i + init_y + tmp_k) * w] =
			tran_32[w_num + h_num * wid];
		    }
		  else
		    {

		    }
		}
	    }
	}
    }
  free (buf_24_32_16);
}

void
show_pic_3 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16)
{
  int i = 0;
  int k = 0;
  int w_num = 0;
  int h_num = 0;
  unsigned char *buf_24_32_16;
  unsigned short *fbmem_16;
  int nn;
  int on[leng_w];
  int down[leng_w];
  int left[leng_h];
  int right[leng_h];
  int left_flag[leng_h];
  int right_flag[leng_h];
  int locate[4] = { 0 };
  int center_w = leng_w / 4;
  int center_h = leng_h / 4;
  int left_tmp;
  int right_tmp;
  int f_num;
  int l;


  fbmem_16 = (unsigned short *) fbmem;
  buf_24_32_16 = (unsigned char *) malloc (wid * height * bpp / 8);

  tran_24_32_16 (pic_buf, buf_24_32_16);



  for (i = 0; i < leng_w; i++)
    {
      on[i] = i - center_w;
      down[i] = i - center_w;
    }

  for (i = 0; i < leng_h; i++)
    {
      left[i] = i - center_h;
      right[i] = i - center_h;
      left_flag[i] = 0;
      right_flag[i] = 0;

    }


  for (f_num = 0; f_num < leng_w; f_num++)
    {
      k = rand () % leng_w;

      if (on[k] != 999)
	{
	  locate[0] = on[k];
	  on[k] = 999;
	}
      else
	{
	  for (l = 0; l < leng_w; l++)
	    {
	      if (on[(k + l) % leng_w] != 999)
		{
		  locate[0] = on[(k + l) % leng_w];
		  on[(k + l) % leng_w] = 999;
		  break;
		}

	    }
	}



      k = rand () % leng_w;
      if (down[k] != 999)
	{
	  locate[1] = down[k];
	  down[k] = 999;
	}
      else
	{

	  for (l = 0; l < leng_w; l++)
	    {
	      if (down[(k + l) % leng_w] != 999)
		{
		  locate[1] = down[(k + l) % leng_w];
		  down[(k + l) % leng_w] = 999;
		  break;
		}

	    }
	}



      if (right_flag[f_num * leng_h / leng_w] == 0)
	{
	  k = rand () % leng_h;
	  if (right[k] != 999)
	    {
	      locate[2] = right[k];
	      right_tmp = right[k];
	      right[k] = 999;
	    }
	  else
	    {

	      for (l = 0; l < leng_h; l++)
		{
		  if (right[(k + l) % leng_h] != 999)
		    {
		      locate[2] = right[(k + l) % leng_h];
		      right[(k + l) % leng_h] = 999;
		      break;
		    }

		}
	    }
	  right_flag[f_num * leng_h / leng_w] = 1;
	}
      else
	{
	  locate[2] = right_tmp;
	}



      if (left_flag[f_num * leng_h / leng_w] == 0)
	{
	  k = rand () % leng_h;
	  if (left[k] != 999)
	    {
	      locate[3] = left[k];
	      left_tmp = left[k];
	      left[k] = 999;
	    }
	  else
	    {

	      for (l = 0; l < leng_w; l++)
		{
		  if (left[(k + l) % leng_h] != 999)
		    {
		      locate[3] = left[(k + l) % leng_h];
		      left[(k + l) % leng_h] = 999;
		      break;
		    }

		}
	    }
	  left_flag[f_num * leng_h / leng_w] = 1;
	}
      else
	{
	  locate[3] = left_tmp;
	}





      for (i = -center_h + 1; i <= 0; i++)
	{

	  w_num = (center_w - locate[0] * i / center_h) * wid / leng_w;
	  h_num = ((center_h + i)) * height / leng_h;

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;

	      fbmem_16[(init_x + center_w - locate[0] * i / center_h) +
		       (init_y + (center_h + i)) * w] =
		tran_16[w_num + h_num * wid];

	    }
	  else if (bpp == 32)
	    {
	     unsigned  int *tran_32 = (unsigned int *) buf_24_32_16;

	      fbmem[(init_x + center_w - locate[0] * i / center_h) +
		    (init_y + (center_h + i)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}

      for (i = 0; i < (leng_h - center_h - 1); i++)
	{



	  w_num =
	    (center_w +
	     locate[1] * i / (leng_h - center_h - 1)) * wid / leng_w;
	  h_num = ((center_h + i)) * height / leng_h;

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + center_w +
			locate[1] * i / (leng_h - center_h - 1)) + (init_y +
								    (center_h
								     +
								     i)) *
		       w] = tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	    unsigned   int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + center_w +
		     locate[1] * i / (leng_h - center_h - 1)) + (init_y +
								 (center_h +
								  i)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {


	    }
	}

      for (nn = 0; nn < leng_w - center_w - 1; nn++)
	{
	  w_num = (center_w + nn) * wid / leng_w;
	  h_num =
	    (center_h +
	     locate[2] * nn / (leng_w - center_w - 1)) * height / leng_h;

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + center_w + nn) + (init_y + center_h +
						   locate[2] * nn / (leng_w -
								     center_w
								     -
								     1)) *
		       w] = tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + center_w + nn) +
		    (init_y + center_h +
		     locate[2] * nn / (leng_w - center_w - 1)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}


      for (nn = -center_w + 1; nn <= 0; nn++)
	{
	  w_num = (center_w + nn) * wid / leng_w;
	  h_num = (center_h - locate[3] * nn / (center_w)) * height / leng_h;

	  if (bpp == 16)
	    {
	     unsigned  short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + center_w + nn) +
		       (init_y + center_h -
			locate[3] * nn / (center_w)) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	     unsigned  int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + center_w + nn) +
		    (init_y + center_h - locate[3] * nn / (center_w)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}
      usleep (2500);

    }
  free (buf_24_32_16);
}


void
show_pic_4 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16)
{
  int mm, nn;
  int k, i;
  int w_num, h_num;
  unsigned short *fbmem_16;
  fbmem_16 = (unsigned short *) fbmem;
  unsigned char *buf_24_32_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  tran_24_32_16 (pic_buf,buf_24_32_16);


  for (k = -2 * leng_w; k <= 2 * leng_w; k++)
    {

      for (i = -leng_h / 2; i < leng_h / 2; i++)
	{



	  w_num = (leng_w / 2 - k * i / leng_h / 2) * wid / leng_w;
	  h_num = ((leng_h / 2 + i)) * height / leng_h;
	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + leng_w / 2 - k * i / leng_h / 2) +
		       (init_y + (leng_h / 2 + i)) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + leng_w / 2 - k * i / leng_h / 2) +
		    (init_y + (leng_h / 2 + i)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}

      mm = k * leng_h / (4 * leng_w);

      for (nn = -2 * leng_w; nn < 2 * leng_w; nn++)
	{
	  w_num = (leng_w / 2 + nn / 4) * wid / leng_w;
	  h_num = (leng_h / 2 + mm * nn / (2 * leng_w)) * height / leng_h;
int tmp;
		      // (init_y + leng_h / 2 + mm * nn / (2 * leng_w)) * w] =
		tmp = init_y + leng_h /2 + mm * nn/(2 * leng_w);
	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
		if( tmp >=h)
		{
			tmp = h -1;
		}
	      fbmem_16[(init_x + leng_w / 2 + nn / 4) + (tmp) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + leng_w / 2 + nn / 4) +
		    (tmp) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}

      usleep (2500);

    }

  free (buf_24_32_16);
}







void
show_pic_5 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16)
{
  int i, k, m, l;
  int w_num, h_num;
  int locate;
  int rand_line[leng_h];
  unsigned short *fbmem_16;

  unsigned char *buf_24_32_16;
  buf_24_32_16 = (unsigned char *)malloc (wid * height * bpp / 8);
  fbmem_16 = (unsigned short *) fbmem;

  tran_24_32_16 (pic_buf,buf_24_32_16);

  for (i = 0; i < leng_h; i++)
    rand_line[i] = i;


  for (m = 0; m < leng_h; m++)
    {
      k = rand () % leng_h;
      if (rand_line[k] != 9999)
	{
	  locate = rand_line[k];
	  rand_line[k] = 9999;
	}
      else
	{

	  for (l = 0; l < leng_h; l++)
	    {
	      if (rand_line[(k + l) % leng_h] != 9999)
		{
		  locate = rand_line[(k + l) % leng_h];
		  rand_line[(k + l) % leng_h] = 9999;
		  break;
		}

	    }
	}

      for (i = 0; i < leng_w; i++)
	{
	  w_num = i * wid / leng_w;
	  h_num = locate * height / leng_h;
	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + i) + (init_y + locate) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	     unsigned  int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + i) + (init_y + locate) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  //                      else
	  {

	  }
	}
      usleep (2500);
    }
  free (buf_24_32_16);

}

void
show_pic_6 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, int portion, callback_t tran_24_32_16)
{

  int w_num;
  int h_num;
  int locate;
  int i, j, k;
  unsigned char *buf_24_32_16;
  unsigned short *fbmem_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);
  fbmem_16 = (unsigned short *) fbmem;

  tran_24_32_16 (pic_buf,buf_24_32_16);


  for (locate = 1; locate <= portion; locate++)
    {
      for (j = 0; j < leng_w; j++)
	{
	  for (i = (locate - 1) * leng_h / portion;
	       i < locate * leng_h / portion; i++)
	    {
	      if (locate % 2 == 0)
		k = leng_w - 1 - j;
	      else
		k = j;

	      w_num = k * wid / leng_w;
	      h_num = i * height / leng_h;

	      if (bpp == 16)
		{
		 unsigned  short *tran_16 = (unsigned short *) buf_24_32_16;
		  fbmem_16[init_x + k + (i + init_y) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		 unsigned  int *tran_32 = (unsigned int *) buf_24_32_16;
		  fbmem[init_x + k + (i + init_y) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else
		{

		}
	    }
	  usleep (1000);
	}

    }

  free (buf_24_32_16);
}

void
show_pic_7 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, int portion, callback_t tran_24_32_16)
{
  int w_num;
  int h_num;
  int i, j, k;
  int share_portion;
 unsigned  char *buf_24_32_16;
 unsigned  short *fbmem_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  tran_24_32_16 (pic_buf,buf_24_32_16);
  fbmem_16 = (unsigned short *) fbmem;

  share_portion = leng_h / portion;

  for (j = 0; j < leng_w; j++)
    {
      for (k = 1; k <= portion / 2; k++)
	{
	  for (i = (2 * k - 1) * share_portion; i < 2 * k * share_portion;
	       i++)
	    {
	      w_num = j * wid / leng_w;
	      h_num = i * height / leng_h;
	      if (bpp == 16)
		{
		  unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
		  fbmem_16[init_x + j + (i + init_y) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		  unsigned  int *tran_32 = (unsigned int *) buf_24_32_16;
		  fbmem[init_x + j + (i + init_y) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else
		{

		}
	    }
	  for (i = (2 * (k - 1)) * share_portion;
	       i < (2 * k - 1) * share_portion; i++)
	    {
	      w_num = (leng_w - 1 - j) * wid / leng_w;
	      h_num = i * height / leng_h;
	      if (bpp == 16)
		{
		  unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
		  fbmem_16[init_x + (leng_w - 1 - j) + (i + init_y) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		  unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
		  fbmem[init_x + (leng_w - 1 - j) + (i + init_y) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else
		{

		}
	    }

	  usleep (1000);
	}
    }
  free (buf_24_32_16);
}









void
show_pic_8 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16)
{

  unsigned short *fbmem_16;
  int w_num;
  int h_num;
  int i, j, k;
 unsigned  char *buf_24_32_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  fbmem_16 = (unsigned short *) fbmem;
  tran_24_32_16 (pic_buf, buf_24_32_16);

  for (k = 0; k < leng_w / 5; k = k + 5)
    {
      for (j = 0; j < leng_w * 4 / 5 + k; j++)
	{
	for (i = 0; i < (leng_h * 4 / 5 + k * leng_h / leng_w); i++)
	  {
	    w_num = j * wid / (leng_w * 4 / 5 + k);
	    h_num = i * height / (leng_h * 4 / 5 + k);
	    if (bpp == 16)
	      {
		unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
		fbmem_16[init_x + j + (i + init_y) * w] =
		  tran_16[w_num + h_num * wid];
	      }
	    else if (bpp == 32)
	      {
		unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
		fbmem[init_x + j + (i + init_y) * w] =
		  tran_32[w_num + h_num * wid];
	      }
	    else
	      {

	      }
	  }
	}
    }
  free (buf_24_32_16);
}



void
show_pic_9 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16)
{
  unsigned short *fbmem_16;
  int w_num;
  int h_num;
  int i, j, k;
  unsigned char *buf_24_32_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  fbmem_16 = (unsigned short *) fbmem;

  tran_24_32_16 (pic_buf, buf_24_32_16);

  for (k = 0; k < leng_w / 5; k = k + 5)
    {
      for (j = 0; j < leng_w * 3 / 5 + 2 * k; j++)
	for (i = 0; i < (leng_h * 3 / 5 + 2 * k * leng_h / leng_w); i++)
	  {
	    w_num = j * wid / (leng_w * 3 / 5 + 2 * k);

	    h_num = i * height / (leng_h * 3 / 5 + 2 * k * leng_h / leng_w);

	    if (bpp == 16)
	      {
		unsigned short *tran_16 = (unsigned short *) buf_24_32_16;

		fbmem_16[init_x + j + (leng_w / 5 - k) +
			 (i + init_y + leng_h / 5 -
			  k * leng_h / leng_w) * w] =
		  tran_16[w_num + h_num * wid];
	      }
	    else if (bpp == 32)
	      {
		unsigned int *tran_32 = (unsigned int *) buf_24_32_16;

		fbmem[init_x + j +  (leng_w/5 - k) +(i + init_y  + leng_h/5 - k * leng_h/leng_w) * w] =
		  tran_32[w_num + h_num * wid];
	      }
	    else
	      {

	      }
	  }
    }
  free (buf_24_32_16);
}


void
show_pic_10 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, callback_t tran_24_32_16)
{
  unsigned short *fbmem_16;
  int w_num;
  int h_num;
  int i, j;
  int locate;
  unsigned char *buf_24_32_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  fbmem_16 = (unsigned short *) fbmem;

  tran_24_32_16 (pic_buf, buf_24_32_16);


  for (locate = leng_w / 2; locate >= 0; locate--)
    {

      for (i = 0; i < leng_h; i++)
	{
	  for (j = locate; j <= locate; j++)
	    {
	      w_num = j * wid / leng_w;
	      h_num = i * height / leng_h;




	      if (bpp == 16)
		{
		  unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
		  fbmem_16[init_x + j + (i + init_y) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		  unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
		  fbmem[init_x + j + (i + init_y) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else
		{

		}

	    }
	}



      usleep (2500);
      draw_back (init_x + locate - scroll, init_y - scroll_head, scroll,
		 leng_h + 2 * scroll_head, scroll_color);


      for (i = 0; i < leng_h; i++)
	{
	  for (j = leng_w - 1 - locate; j >= leng_w - 1 - locate; j--)
	    {
	      w_num = j * wid / leng_w;
	      h_num = i * height / leng_h;
	      if (bpp == 16)
		{
		  unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
		  fbmem_16[init_x + j + (i + init_y) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		  unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
		  fbmem[init_x + j + (i + init_y) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else
		{

		}

	    }
	}



      usleep (2500);

      draw_back (init_x + leng_w - locate, init_y - scroll_head, scroll,
		 leng_h + 2 * scroll_head, scroll_color);
    }


  for (i = 0; i <= leng_w / 2; i++)
    {
      draw_back (init_x + i - scroll, init_y - scroll_head, scroll,
		 leng_h + 2 * scroll_head, scroll_color);
      usleep (2500);
      draw_back (init_x + i - scroll, init_y - scroll_head, 1,
		 leng_h + 2 * scroll_head, back_color);

      draw_back (init_x + leng_w - i, init_y - scroll_head, scroll,
		 leng_h + 2 * scroll_head, scroll_color);
      usleep (2500);
      draw_back (init_x + leng_w + scroll - i, init_y - scroll_head, 1,
		 leng_h + 2 * scroll_head, back_color);

    }
  free (buf_24_32_16);


}

unsigned short
change16 (unsigned int color)		// 将32色彩转化为16色彩的
{
  unsigned short colorto16;
  unsigned  short dr, dg, db;

  dr = (color >> 16) * 0x1f / 0xff;
  dg = ((color & 0x0000ff00) >> 8) * 0x3f / 0xff;
  db = (color & 0x000000ff) * 0x1f / 0xff;

  colorto16 = dr << 11 | dg << 5 | db;
  return colorto16;
}

void
draw_back (int init_x, int init_y, int leng_w, int leng_h, unsigned int color)
{
  int i, j ,tmp_w ,tmp_h;
  unsigned short *fbmem_16;

  fbmem_16 = (unsigned short *) fbmem;


  for (i = 0; i < leng_h; i++)
    for (j = 0; j < leng_w; j++)
      {
	if (bpp == 16)
	  {
		tmp_w = init_x + j ;
		tmp_h = init_y + i ;
		if( init_x + j >=w )
		{
			tmp_w = w - 1;
		}
		else if( init_y + i >= h)
		{
			
			tmp_h = h - 1;
		}
		else
		{

		}

	    unsigned short color16;
	    color16 = change16 (color);
	    fbmem_16[tmp_w  + (tmp_h ) * w] = color16;

	  }
	else if (bpp == 32)
	{
		tmp_w = init_x + j ;
		tmp_h = init_y + i ;
		if( init_x + j >=w )
		{
			tmp_w = w - 1;
		}
		else if( init_y + i >= h)
		{
			
			tmp_h = h - 1;
		}
		else
		{

		}
	  fbmem[tmp_w  + (tmp_h) * w] = color;
	}
	else
	  {

	  }

      }
}

void
show_pic_11 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, callback_t tran_24_32_16)
{
  int mm, nn;
  int k, i;
  int w_num, h_num,tmp_w,tmp_h;
  unsigned short *fbmem_16;
  fbmem_16 = (unsigned short *) fbmem;
  unsigned char *buf_24_32_16;

  buf_24_32_16 = malloc (wid * height * bpp / 8);

  tran_24_32_16 ( pic_buf,buf_24_32_16);




  for (k = 0; k <= leng_w * 2; k++)
    {

      for (i = -leng_h / 2; i <= 0; i++)
	{



	  w_num = (leng_w / 2 - k * i / leng_h / 2) * wid / leng_w;
	  h_num = ((leng_h / 2 + i)) * height / leng_h;
	
	tmp_w = (init_x + leng_w / 2 - k * i / leng_h / 2);
	tmp_h =  (init_y + (leng_h / 2 + i));
	if( tmp_w >= w )
	{
		tmp_w = w -1;
	}
	else if(tmp_h >= h)
	{
		tmp_h = h -1;
	}
	else if(tmp_w < 0)
		tmp_w = 0;
	else if(tmp_h < 0)
		tmp_h = 0;
	else 
	{
	;
	}

	  if (bpp == 16)
	    {
		if( tmp_w >=w || tmp_w < 0 || tmp_h >= h || tmp_h <0)
			printf("%d      entry %d ",tmp_w,tmp_h);
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[tmp_w + tmp_h * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[tmp_w + tmp_h * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}
      usleep (1000);
    }

  for (mm = -leng_h / 2; mm <= leng_h / 2; mm++)
    {
      for (nn = 0; nn < 2 * leng_w; nn++)
	{
	  w_num = (leng_w / 2 + nn / 4) * wid / leng_w;
	  h_num = (leng_h / 2 + mm * nn / (2 * leng_w)) * height / leng_h;

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + leng_w / 2 + nn / 4) +
		       (init_y + leng_h / 2 + mm * nn / (2 * leng_w)) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + leng_w / 2 + nn / 4) +
		    (init_y + leng_h / 2 + mm * nn / (2 * leng_w)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}


      usleep (2000 * leng_w / leng_h);
    }

  for (k = -2 * leng_w; k <= 2 * leng_w; k++)
    {

      for (i = 0; i < leng_h / 2; i++)
	{



	  w_num = (leng_w / 2 - k * i / leng_h / 2) * wid / leng_w;
	  h_num = ((leng_h / 2 + i)) * height / leng_h;

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + leng_w / 2 - k * i / leng_h / 2) +
		       (init_y + (leng_h / 2 + i)) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + leng_w / 2 - k * i / leng_h / 2) +
		    (init_y + (leng_h / 2 + i)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}
      usleep (1000);
    }

  for (mm = -leng_h / 2; mm <= leng_h / 2; mm++)
    {
      for (nn = -2 * leng_w; nn < 0; nn++)
	{
	  w_num = (leng_w / 2 + nn / 4) * wid / leng_w;
	  h_num = (leng_h / 2 + mm * nn / (2 * leng_w)) * height / leng_h;
	tmp_w = (init_x + leng_w / 2 + nn / 4);
	tmp_h =  init_y + leng_h / 2 + mm * nn / (2 * leng_w);
	if( tmp_w >= w )
	{
		tmp_w = w -1;
	}
	else if(tmp_h >= h)
	{
		tmp_h = h -1;
	}
	else if(tmp_w < 0)
		tmp_w = 0;
	else if(tmp_h < 0)
		tmp_h = 0;
	else 
	{
	;
	}

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[tmp_w + tmp_h * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[tmp_w + tmp_h * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}


      usleep (2000 * leng_w / leng_h);
    }

  for (k = -2 * leng_w; k <= 0; k++)
    {

      for (i = -leng_h / 2; i <= 0; i++)
	{



	  w_num = (leng_w / 2 - k * i / leng_h / 2) * wid / leng_w;
	  h_num = ((leng_h / 2 + i)) * height / leng_h;

	  if (bpp == 16)
	    {
	      unsigned short *tran_16 = (unsigned short *) buf_24_32_16;
	      fbmem_16[(init_x + leng_w / 2 - k * i / leng_h / 2) +
		       (init_y + (leng_h / 2 + i)) * w] =
		tran_16[w_num + h_num * wid];
	    }
	  else if (bpp == 32)
	    {
	      unsigned int *tran_32 = (unsigned int *) buf_24_32_16;
	      fbmem[(init_x + leng_w / 2 - k * i / leng_h / 2) +
		    (init_y + (leng_h / 2 + i)) * w] =
		tran_32[w_num + h_num * wid];
	    }
	  else
	    {

	    }
	}
      usleep (1000);
    }

  free (buf_24_32_16);
}

void
show_pic_12 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, int portion, callback_t tran24_32_16)
{
  int i = 0;
  int j = 0;
  int k = 0;
  int w_num = 0;
  int h_num = 0;
  unsigned char *buf_32_16;
  unsigned short *fbmem_16;
  int m;

  fbmem_16 = (unsigned short *) fbmem;

  buf_32_16 =(unsigned char *) malloc (wid * height * bpp / 2);	// 为了适应不同的环境上

 // tran_24_32_16 ((char *)pic_buf, (char *)buf_24_32_16);
  tran24_32_16(pic_buf, buf_32_16);

  for (m = 0; m < leng_h / portion; m++)
    {
      for (k = 1; k <= portion; k++)
	{

	  for (i = (k - 1) * leng_h / portion + m;
	       i <= (k - 1) * leng_h / portion + m; i++)
	    {

	      for (j = 0; j < leng_w; j++)
		{
		  w_num = j * wid / leng_w;
		  h_num = i * height / leng_h;
		  if (bpp == 16)
		    {
		     unsigned  short *tran_16 = (unsigned short *) buf_32_16;
		      fbmem_16[init_x + j + (i + init_y) * w] =
			tran_16[w_num + h_num * wid];
		    }
		  else if (bpp == 32)
		    {
		      unsigned int *tran_32 = (unsigned int *) buf_32_16;
		      fbmem[init_x + j + (i + init_y) * w] =
			tran_32[w_num + h_num * wid];
		    }
		  else
		    {

		    }
		}
	    }
	}
      usleep (25000);
    }
  free (buf_32_16);
}




void
show_pic_13 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	     int leng_h, callback_t tran_24_32_16)
{
  int i, j, k, m, l;
  int w_num, h_num;
  int locate;
  unsigned short *fbmem_16;
  unsigned char *buf_24_32_16;
  int num_x = 50;
  int num_y = 50;

  int num = num_x * num_y;

  int rand_square[num];
  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);
  fbmem_16 = (unsigned short *) fbmem;

  tran_24_32_16 (pic_buf,buf_24_32_16);

  for (i = 0; i < num; i++)
    rand_square[i] = i;


  for (m = 0; m < num; m++)
    {
      k = rand () % num;
      if (rand_square[k] != 9999)
	{
	  locate = rand_square[k];
	  rand_square[k] = 9999;
	}
      else
	{

	  for (l = 0; l < num; l++)
	    {
	      if (rand_square[(k + l) % num] != 9999)
		{
		  locate = rand_square[(k + l) % num];
		  rand_square[(k + l) % num] = 9999;
		  break;
		}

	    }
	}
      for (i = leng_w * (locate % num_x) / num_x;
	   i < leng_w * (locate % num_x + 1) / num_x; i++)
	{
	  for (j = leng_h * (locate / num_y) / num_y;
	       j < leng_h * (locate / num_y + 1) / num_y; j++)
	    {
	      w_num = i * wid / leng_w;
	      h_num = j * height / leng_h;
	      if (bpp == 16)
		{
		 unsigned  short *tran_16 = (unsigned short *) buf_24_32_16;
		  fbmem_16[(init_x + i) + (init_y + j) * w] =
		    tran_16[w_num + h_num * wid];
		}
	      else if (bpp == 32)
		{
		 unsigned  int *tran_32 = (unsigned int *) buf_24_32_16;
		  fbmem[(init_x + i) + (init_y + j) * w] =
		    tran_32[w_num + h_num * wid];
		}
	      else

		{

		}
	    }
	}
      usleep (1000);
    }
  free (buf_24_32_16);

}



void
show_pic_14 (unsigned char *pic_buf, int init_x, int init_y, int leng_w,
	    int leng_h, callback_t tran_24_32_16)
{
 unsigned  short *fbmem_16;
  int w_num;
  int h_num;
  int i, j, k;
 unsigned  char *buf_24_32_16;

  buf_24_32_16 =(unsigned char *) malloc (wid * height * bpp / 8);

  fbmem_16 = (unsigned short *) fbmem;

  tran_24_32_16 (pic_buf, buf_24_32_16);

  for (k = 0; k < leng_w /2; k = k + 5)
    {
      for (j = 0; j <  2 * k; j++)
	for (i = 0; i < 2 * k * leng_h / leng_w; i++)
	  {
	    w_num = (leng_w/2  -  k +j) * wid / (leng_w );

	    h_num =(leng_h/2 -k * leng_h/leng_w  + i) * height / (leng_h );

	    if (bpp == 16)
	      {
		unsigned short *tran_16 = (unsigned short *) buf_24_32_16;

		fbmem_16[init_x + j + (leng_w / 2 - k) +
			 (i + init_y + leng_h / 2 -
			  k * leng_h / leng_w) * w] =
		  tran_16[w_num + h_num * wid];
	      }
	    else if (bpp == 32)
	      {
		unsigned int *tran_32 = (unsigned int *) buf_24_32_16;

		fbmem[init_x + j +  (leng_w/2 - k) +(i + init_y  + leng_h/2 - k * leng_h/leng_w) * w] =
		  tran_32[w_num + h_num * wid];
	      }
	    else
	      {

	      }
	  }
	usleep(1000);
    }
  free (buf_24_32_16);
}


