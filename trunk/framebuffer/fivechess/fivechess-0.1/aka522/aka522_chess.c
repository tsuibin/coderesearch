#include "common.h"
#include <sys/time.h>
#include <stdlib.h>

int direction_var[4][4] = { {1, 0, -1, 0},	//四个方向增量数组
{1, 1, -1, -1},
{0, 1, 0, -1},
{-1, 1, 1, -1},
};

// 这个矩阵，行代表四个不同的边，列代表一条边上代表没的方向  两个一组构成坐标
int temp_value[20][20];
int score_one[20][20];
int score_two[20][20];
int score_mix[20][20];
int score[20][20];
int array1,array2;
/*
 *函数功能：计算该点一个方向到另一方棋子的距离   这个函数的最终目的  解决下废棋的情况
 *            *_____*   * 表示对方的棋子，_ 表示我方可能下的位置，如果该点其他方向没有什么，那么我方下在_内是永远不可能成五的
 */
int calculate_pattern_345_score (int chess_ax, int chess_ay, int chess_flag);	//  计算  类型3 4  的最终权重
void midpointcircle(int m,int n,int r,int circle_color);
int calculate_pattern_2_score (int chess_ax, int chess_ay, int chess_flag);	// 计算类型2的权重  这个函数仅为当  find_chess()搜索到的权值为1 时才调用这个函数
void draw_num(int chess_x,int chess_y,int color,int num)   ;
void draw_chess_num(int chess_array_x ,int chess_array_y ,int chess_color );

int
find_opposite_direction_num (int chess_ax, int chess_ay, int locate,
			     int chess_flag)
{
  int dir_num = 0;
  int dx = 0;
  int dy = 0;
  int total_num = 0;

  for (dir_num = 1; dir_num <= 6; dir_num++)
    {
      dx = chess_ax + dir_num * direction_var[locate][0];
      dy = chess_ay + dir_num * direction_var[locate][1];

      if (array_chess[dx][dy] == 1 || dx < 0 || dx > (chess_line_num - 1) ||	//array_chess[dx][dy] == 1 相当于已经固定死了
	  dy < 0 || dy > (chess_line_num - 1) || dir_num == 6)
	{
	  return total_num;
	}
      else
	total_num++;
    }

	return 0;
}

/*
 *函数功能： 同上，这是寻找该点沿相反方向到对方棋子的距离
 *
 */

int
find_positive_direction_num (int chess_ax, int chess_ay, int locate,
			     int chess_flag)
{

  int dir_num = 0;
  int dx = 0;
  int dy = 0;
  int total_num = 0;

  for (dir_num = 1; dir_num <= 6; dir_num++)
    {
      dx = chess_ax + dir_num * direction_var[locate][2];
      dy = chess_ay + dir_num * direction_var[locate][3];

      if (array_chess[dx][dy] == 1 || dx < 0 || dx > (chess_line_num - 1) || dy < 0	// 同理如上此处另一方向也是固定死了的
	  || dy > (chess_line_num - 1) || dir_num == 6)
	{
	  return total_num;
	}

      else
	total_num++;
    }
		return 0;
}


/*
 *函数功能：计算该点沿一个方向对方连续的棋子数
 *
 */

int
search_opposite_direction_num (int chess_ax, int chess_ay, int locate,
			       int chess_flag)
{
  int dir_num = 0;
  int dx = 0;
  int dy = 0;
  int total_num = 0;

  for (dir_num = 1; dir_num <= 6; dir_num++)
    {
      dx = chess_ax + dir_num * direction_var[locate][0];
      dy = chess_ay + dir_num * direction_var[locate][1];

      if (array_chess[dx][dy] == chess_flag  && dx >= 0
	  && dx < chess_line_num && dy >= 0 && dy < chess_line_num)
	{
	  total_num++;
	}
      else
	return total_num;
    }
		return 0;
}

/*
 *函数功能：计算该点沿相反方向对方连续的棋子数
 *
 */

int
search_positive_direction_num (int chess_ax, int chess_ay, int locate,
			       int chess_flag)
{
  int dir_num = 0;
  int dx = 0;
  int dy = 0;
  int total_num = 0;

  for (dir_num = 1; dir_num <= 6; dir_num++)
    {
      dx = chess_ax + dir_num * direction_var[locate][2];
      dy = chess_ay + dir_num * direction_var[locate][3];

      if (array_chess[dx][dy] == chess_flag   && dx >= 0
	  && dx < chess_line_num && dy >= 0 && dy < chess_line_num)
	{
	  total_num++;
	}

      else
	return total_num;
    }

	return 0;
}

/*
 *函数功能：计算一边两个方向到对方棋子之间的位置个数 ,也就是看有没有死棋的地方了
 */

int
find_side_totalnum (int chess_ax, int chess_ay, int locate, int chess_flag)	//计算两个方向的对方棋子的和
{
  int find_total_num = 0;

  if (chess_flag == 2)		//  这是专门用来寻找我方的
    {

      find_total_num =
	find_opposite_direction_num (chess_ax, chess_ay, locate,
				     chess_flag) +
	find_positive_direction_num (chess_ax, chess_ay, locate, chess_flag);

#if 1
      if (find_total_num < temp_value[chess_ax][chess_ay])
	temp_value[chess_ax][chess_ay] = find_total_num;
#endif

      if (find_total_num < 4)
	score[chess_ax][chess_ay] = -24;

    }
			return 0;

}

/*
 *函数功能：计算一边两个方向对方连续的棋子的个数
 *
 */

int
search_side_totalnum (int chess_ax, int chess_ay, int locate, int chess_flag)
{
  int total_num = 0;
  total_num =
    search_opposite_direction_num (chess_ax, chess_ay, locate,
				   chess_flag) +
    search_positive_direction_num (chess_ax, chess_ay, locate, chess_flag);
  return total_num;

}


/*
 *函数功能：求四个大方向的对方棋子连续个数最大值
 *
 */

int
search_side_maxnum (int chess_ax, int chess_ay, int chess_flag)
{
  int locate = 0;
  int max_num = 0;
  int side_temp_num = 0;

  for (locate = 0; locate < 4; locate++)
    {
      side_temp_num =
	search_side_totalnum (chess_ax, chess_ay, locate, chess_flag);

      if (side_temp_num >= max_num)
	max_num = side_temp_num;
    }
  return max_num;
}



/*
 *
 * 函数功能:计算对方该点处的得分函数
 */
int
calculate_one_score (int chess_ax, int chess_ay)
{

  int locate = 0;
  int side_temp_num = 0;
  int pa341_temp_score = 0;
  int pa21_temp_score = 0;

  for (locate = 0; locate < 4; locate++)
    {
      side_temp_num = search_side_totalnum (chess_ax, chess_ay, locate, 1);

      if (side_temp_num >= 4)
	{
	  score_one[chess_ax][chess_ay] = 95;	    
	}

      if (side_temp_num >= score_one[chess_ax][chess_ay])
	score_one[chess_ax][chess_ay] = side_temp_num;
    }


  pa341_temp_score = calculate_pattern_345_score (chess_ax, chess_ay, 1);

  if (pa341_temp_score >= score_one[chess_ax][chess_ay])
		score_one[chess_ax][chess_ay]= pa341_temp_score;

    if (score_one[chess_ax][chess_ay] <= 1)
      {
	pa21_temp_score = calculate_pattern_2_score (chess_ax, chess_ay, 1);

	if (pa21_temp_score >= score_one[chess_ax][chess_ay])
	  	score_one[chess_ax][chess_ay]  = pa21_temp_score;

	if (score_one[chess_ax][chess_ay] >= 20)
	  score_one[chess_ax][chess_ay] = 20;
	}


  return 0;

}

int
calculate_two_score (int chess_ax, int chess_ay)
{
  int locate = 0;
  int side_temp_num = 0;
  int pa342_temp_score = 0;
  int pa22_temp_score = 0;

  for (locate = 0; locate < 4; locate++)
    {
	find_side_totalnum(chess_ax,chess_ay,locate,2);

      side_temp_num = search_side_totalnum (chess_ax, chess_ay, locate, 2);
      if (side_temp_num >= 4)
	{
	score_two[chess_ax][chess_ay] = 100;
		return 0;
	}

      if (side_temp_num >= score[chess_ax][chess_ay])
	score_two[chess_ax][chess_ay] = side_temp_num;

    }

  pa342_temp_score = calculate_pattern_345_score (chess_ax, chess_ay, 2);

  if (pa342_temp_score >= score_two[chess_ax][chess_ay])
    score_two[chess_ax][chess_ay] = pa342_temp_score;


  if (score_two[chess_ax][chess_ay] <= 1)
    {

      pa22_temp_score = calculate_pattern_2_score (chess_ax, chess_ay, 2);

      if (pa22_temp_score >= score_two[chess_ax][chess_ay])
	score_two[chess_ax][chess_ay]  = pa22_temp_score;

      if (score_two[chess_ax][chess_ay] >= 20)
	score_two[chess_ax][chess_ay] = 20;

    }


	return 0;


}

/*
 * 函数功能：计算该点对方与我方的最终得分值
 */

int
calculate_finalscore (int chess_ax, int chess_ay)
{
	int temp_score;
	
	calculate_one_score(chess_ax,chess_ay);
	calculate_two_score(chess_ax,chess_ay);

	if (score[chess_ax][chess_ay] >=0)
	{
		if(score_one[chess_ax][chess_ay] > score_two[chess_ax][chess_ay])
			score[chess_ax][chess_ay] = score_one[chess_ax][chess_ay];
		else if (score_one[chess_ax][chess_ay] <= score_two[chess_ax][chess_ay])
			score[chess_ax][chess_ay] = score_two[chess_ax][chess_ay];
		else
		{
			;
		}

	}
	else if(score[chess_ax][chess_ay] == -24)
	{
			if(score_one[chess_ax][chess_ay] > score_two[chess_ax][chess_ay])
				temp_score = score_one[chess_ax][chess_ay];
			else
				temp_score = score_two[chess_ax][chess_ay];
				
			if(score[chess_ax][chess_ay] + temp_score >= 0)
				score[chess_ax][chess_ay] = temp_score;
			else
				score[chess_ax][chess_ay] = 0;

	}
	else
	{



	}

	return score[chess_ax][chess_ay];

}




/*
 *函数功能：计算棋盘上得分最高的点的坐标值
 */

int
aka522_chess (void)
{
  int chess_ax, chess_ay;
  int chess_max = 0;
  int store_samemax_x[chess_line_num * chess_line_num] = { 0 };
  int store_samemax_y[chess_line_num * chess_line_num] = { 0 };
  int store_samemax_num = 0;
  int test_chess[20][20];

  int chess_tmp = 0;

  int rand_num = 0;

  struct timeval tv;

  int i, j;

  for (i = 0; i < 20; i++)
    for (j = 0; j < 20; j++)
      {
	temp_value[i][j] = 20;
	score_one[i][j] = 0;
	score_two[i][j] = 0;
	score_mix[i][j] = 0;
	score[i][j] = 0;
      }


  if (chess_num == 0)
    {
      midpointcircle (10 * chess_gap + chessboard_init_x,
		      10 * chess_gap + chessboard_init_y, circle_r,
		      chess_two_color);
      array_chess[10][10] =2;
      chess_num++;
      draw_num (10 * chess_gap + chessboard_init_x - 6,
		10 * chess_gap + chessboard_init_y - 6, 0xffffff, chess_num);
      return 0;

    }				// 画圆

  for (chess_ax = 0; chess_ax < chess_line_num; chess_ax++)
    {
      for (chess_ay = 0; chess_ay < chess_line_num; chess_ay++)
	{
	  if (array_chess[chess_ax][chess_ay] == 0)
	    {
	      chess_tmp = calculate_finalscore (chess_ax, chess_ay);
	      test_chess[chess_ax][chess_ay] = chess_tmp;

	      if (chess_tmp > chess_max)
		{
		  store_samemax_num = 0;
		  store_samemax_x[store_samemax_num] = chess_ax;
		  store_samemax_y[store_samemax_num] = chess_ay;
		  chess_max = chess_tmp;
		}
	      else if (chess_tmp == chess_max)
		{
		  store_samemax_num++;
		  store_samemax_x[store_samemax_num] = chess_ax;
		  store_samemax_y[store_samemax_num] = chess_ay;
		}
	      else
		{

		}
	    }
	  else
	    {

	    }

	}
    }


  gettimeofday (&tv, NULL);


  srand (tv.tv_usec);		//    suseconds_t tv_usec;    /* microseconds */
  rand_num = rand () % (store_samemax_num + 1);
  rand_num = rand_num * (store_samemax_num + 1) / (store_samemax_num + 1);





  if (chess_max == 0 && array_chess[9][9] == 0)	// 是当所有的计算值为0时的情况    
    {
      store_samemax_x[0] = 9;
      store_samemax_y[0] = 9;
      rand_num = 0;

    }


	array1 = store_samemax_x[rand_num];
	array2 = store_samemax_y[rand_num];


#if 0

  for (j = 0; j < 20; j++)
    {
      for (i = 0; i < 20; i++)
	{
	  if (score_one[i][j] == 0)
	    printf ("--");
	  else if (score_one[i][j] < 10)
	    printf ("A%d", score_one[i][j]);
	  else
	    printf ("%d", score_one[i][j]);
	}
      printf ("\n");
    }
  printf ("\n");

  for (j = 0; j < 20; j++)
    {
      for (i = 0; i < 20; i++)
	{
	  if (score_two[i][j] == 0)
	    printf ("--");
	  else if (score_two[i][j] < 10)
	    printf ("B%d",score_two[i][j]);
	  else 
	      printf("%d",score_two[i][j]);
	}
      printf ("\n");
    }

  printf ("\n");

#endif 
  return 0;
}
