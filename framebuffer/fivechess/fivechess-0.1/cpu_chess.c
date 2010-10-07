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
int aka522_chess (void);


 
int cpu_chess (void) //   人下棋，画出棋子，并判断棋子的是否成五
{
 if (chess_num == 0)
    {
       midpointcircle ( chess_line_num /2 * chess_gap + chessboard_init_x,
              chess_line_num/2 * chess_gap + chessboard_init_y, circle_r, chess_one_color     );
       array_chess[chess_line_num/2][chess_line_num/2] = 2 ;

       chess_num++;
         midpointcircle (chess_line_num/2  * chess_gap + chessboard_init_x,
                                chess_line_num/2  * chess_gap + chessboard_init_y, circle_r,chess_two_color);

        draw_num (chess_line_num/2 * chess_gap + chessboard_init_x - 6, chess_line_num/2 * chess_gap + chessboard_init_y - 6, 0xffffff, chess_num);
			if(search_side_maxnum(array_x,array_y,1) +1 >=5)  //棋子下后， 是否成五
				return 100;
                              return 1;
	}


						if (chess_num >= 400)
								return 10000;

       aka522_chess();
                        chess_num++;



                array_chess[array1][array2]=2;

                midpointcircle (array1 * chess_gap + chessboard_init_x,
                                array2 * chess_gap + chessboard_init_y, circle_r,chess_two_color);
//								printf("red \n");
                
			draw_chess_num(array1 ,array2,0xffffff);	
//				画棋子上的数字
		

		if(search_side_maxnum(array1,array2,2) +1 >=5)  //棋子下后， 是否成五
				return 100;
												return 0;
}
