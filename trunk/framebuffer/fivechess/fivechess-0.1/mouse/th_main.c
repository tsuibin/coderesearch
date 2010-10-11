#include <stdio.h>
#include "common.h"
#include <unistd.h>
#include <stdlib.h>


void draw_chess (void );   // 画棋盘
int init_fb (void);
int init_mouse(void); 
int read_mouse(int fd);
void save_mouse_buf (void );
int draw_mouse (void);             
int  check_mouse_pix( void); 
int hum_chess (void); //   人下棋，画出棋子，并判断棋子的是否成五
int cpu_chess (void);
void recover_mouse_buf (void );



int
main (int argc, char *argv[])
{

int  ret, fd;
int temp = 0;

  ret = init_fb ();  //  初始化设备文件   
  if (ret != 0)
    return ret;

//	draw_chess();     //  画棋盘

  fd = init_mouse ();    //   初始化鼠标


  if (fd < 0)
    {
      printf ("Open /dev/input/mice error\n");
      return -1;
    }


  while (1)
  {

	ret = read_mouse (fd); //  读鼠标的坐标
	recover_mouse_buf ();      // 恢复上次坐标点处的区域数据
	save_mouse_buf();                   //   保存鼠标点处的区域的数据
	draw_mouse ();                   //     画该点处的鼠标

  }


	close(fd);
  return 0;
}
