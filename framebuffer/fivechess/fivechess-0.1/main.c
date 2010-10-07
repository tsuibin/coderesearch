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

	draw_chess();     //  画棋盘

  fd = init_mouse ();    //   初始化鼠标


  if (fd < 0)
    {
      printf ("Open /dev/input/mice error\n");
      return -1;
    }


if (PLAYER_NUM ==1)                   //人机对战模式
{
  while (1)
    {

      ret = read_mouse (fd); //  读鼠标的坐标

      recover_mouse_buf ();      // 恢复上次坐标点处的区域数据

      if (ret == 0)
	{
	if(check_mouse_pix())               //判断鼠标当前所在的坐标值是否在棋盘内，如果在则把坐标值转化为棋盘数组的下标
	{
		save_mouse_buf();//消除鼠标单击左键时的闪耀  在鼠标按下不显示则注释这两行
		draw_mouse();
		continue;
	}

	if(chess_num %2 ==(abs(start-1))) 
	{
		temp = hum_chess();
		if( temp == 100)//    如果  hum_chess  人下棋后是否成五个，如果成五个，如果成立则回100 
		{
		printf("red win \n");
		break;
		}
		else if (temp == 10000)
		{
			printf("和棋\n");
			break;
		}
		else
		{

		}
	}

	}

	if(chess_num %2 ==(abs(start-0)))
	{
		temp = cpu_chess();
		if(temp == 100)      // 同理如上
		{
		 printf("aka522  win\n");
			break;
		}
		else if (temp == 10000)
		{
			printf("和棋 \n");
			break;
		}
		else
		{


		}
	}
	save_mouse_buf();                   //   保存鼠标点处的区域的数据
      draw_mouse ();                   //     画该点处的鼠标

    }
	printf("赢了......\n");
}
else                                                //机机对战模式
{


while(1)
{
	if(chess_num %2 ==( abs(start-1) )) 
	{
		temp = hum_chess();
		if( temp == 100)//    如果  hum_chess  人下棋后是否成五个，如果成五个，如果成立则回100 
		{
		printf("mxcai2010 win \n");
		break;
		}
		else if (temp == 10000)
		{
			printf("和棋\n");
			break;
		}
		else
		{

		}
	}
	sleep(1);

	if(chess_num %2 == start )
	{
		temp = cpu_chess();
		if(temp == 100)      // 同理如上
		{
		 printf("aka522  win\n");
			break;
		}
		else if (temp == 10000)
		{
			printf("和棋 \n");
			break;
		}
		else
		{


		}

	}

		sleep(1);

   }

	printf("赢了......\n");
}

	close(fd);
  return 0;
}
