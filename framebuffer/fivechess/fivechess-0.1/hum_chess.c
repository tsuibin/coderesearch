#include  "common.h"
#include "com.h"


/*
 *函数功能：人下棋，画出符合条件位置的棋子，标上数字 
 *
 */
void midpointcircle(int m,int n,int r,int circle_color); 
void draw_num(int chess_x,int chess_y,int color,int num); 
void draw_chess_num(int chess_array_x ,int chess_array_y ,int chess_color );
int search_side_maxnum (int chess_ax, int chess_ay, int chess_flag);

int  hum_player(void )
{
if(start == 0)
{
  if (chess_num == 0)
    {
       midpointcircle (chess_line_num/2  * chess_gap + chessboard_init_x,
              chess_line_num/2  * chess_gap + chessboard_init_y, circle_r, chess_one_color     );
       array_chess[chess_line_num/2 ][chess_line_num/2 ] = 1;

       chess_num++;
        draw_num (chess_line_num/2  * chess_gap + chessboard_init_x - 6, chess_line_num/2 * chess_gap + chessboard_init_y - 6, 0x0, chess_num);
			if(search_side_maxnum(array_x,array_y,1) +1 >=5)  //棋子下后， 是否成五
								return 100;
											return 0;
	}
}

             if (array_chess[array_x][array_y]==0)
                {
                        chess_num++;
                array_chess[array_x][array_y]=1;
                midpointcircle (array_x * chess_gap + chessboard_init_x,
                                array_y * chess_gap + chessboard_init_y, circle_r,chess_one_color);

			draw_chess_num(array_x ,array_y,0x0);	

	        	}
		return 0;
}

int  mxcai2010_player(void )
{
 if (chess_num == 0)
    {
       midpointcircle (chess_line_num/2  * chess_gap + chessboard_init_x,
              chess_line_num/2  * chess_gap + chessboard_init_y, circle_r, chess_one_color     );
       array_chess[chess_line_num/2 ][chess_line_num/2 ] = 1;

       chess_num++;
        draw_num (chess_line_num/2  * chess_gap + chessboard_init_x - 6, chess_line_num/2 * chess_gap + chessboard_init_y - 6, 0x0, chess_num);
			if(search_side_maxnum(array_x,array_y,1) +1 >=5)  //棋子下后， 是否成五
								return 100;
											return 0;
	}	


       think_chess();
                        chess_num++;



                array_chess[array_x][array_y]=1;

                midpointcircle (array_x * chess_gap + chessboard_init_x,
                                array_y * chess_gap + chessboard_init_y, circle_r,chess_one_color);
                
			draw_chess_num(array_x ,array_y,0x0);	

					return 0;
}

 
int hum_chess (void) //   人下棋，画出棋子，并判断棋子的是否成五
{

int tmp = 0 ;

		if (chess_num >= 400)
				return 10000;



		switch(PLAYER_NUM)
		{
			case 1: 
				tmp = hum_player();
				
					break;
			case 2: 
				tmp = mxcai2010_player();
					break;
			default:
					printf(" 其他情况\n");
					break;
		}
						

			if (tmp == 100)
					return 100;

		if(search_side_maxnum(array_x,array_y,1) +1 >=5)  //棋子下后， 是否成五
				return 100;
												return 0;
}









