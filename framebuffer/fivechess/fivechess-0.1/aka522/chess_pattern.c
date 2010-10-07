#include "common.h"
#include "string.h"

  int side_num = 0;
  int array_one_x[21] = { 0 };
  int array_one_y[21] = { 0 };
  int array_two_x[21] = { 0 };
  int array_two_y[21] = { 0 };
  int array_side_one[21] = { 0 };
  int array_side_two[21] = { 0 };
  int side_one_max = 0;
  int side_two_max = 0;

/*
 *函数功能:计算该点沿某个方向向两头扩展的最大长度，直到遇到边界为止
 */

int 
check (int chess_ax, int chess_ay, int locate, int num)	
{

	int array_cx[21] = { 0 };
	int array_cy[21] = { 0 };

  for (side_num = 1; side_num <= 20; side_num++)
    {

      array_cx[side_num - 1] =
	chess_ax + side_num * direction_var[locate][0 + 2 * num];
      array_cy[side_num - 1] =
	chess_ay + side_num * direction_var[locate][1 + 2 * num];
      if (array_cx[side_num - 1] < 0 || array_cx[side_num - 1] > 19
	  || array_cy[side_num - 1] < 0 || array_cy[side_num - 1] > 19)
	return side_num - 1;
    }
		return 0;
}


/*
 *函数功能：计算某一方向上各点的坐标对应的值（0,1,2)
 *
 */
void init_pattern(int chess_ax,int chess_ay,int locate)
{

  side_one_max = check (chess_ax, chess_ay, locate, 0);	//符合条件的一个方向的最大长度
  side_two_max = check (chess_ax, chess_ay, locate, 1);	//符合另外一个方向的最大长度

  for (side_num = 1; side_num <= side_one_max; side_num++)
    {

      array_one_x[side_num - 1] = chess_ax + side_num * direction_var[locate][0];
      array_one_y[side_num - 1] = chess_ay + side_num * direction_var[locate][1];	//计算相应的坐标值
      array_side_one[side_num - 1] = array_chess[array_one_x[side_num - 1]][array_one_y[side_num - 1]];	//计算该点坐标值点的数值
    }

  for (side_num = 1; side_num <= side_two_max; side_num++)
    {
      array_two_x[side_num - 1] = chess_ax + side_num * direction_var[locate][2];	// 这是另一个方向的，同理如上
      array_two_y[side_num - 1] = chess_ay + side_num * direction_var[locate][3];
      array_side_two[side_num - 1] =
	array_chess[array_two_x[side_num - 1]][array_two_y[side_num - 1]];
    }

}


int side_one_num;
int side_two_num;

int search_pattern(char * string_x,char * string_y,int chess_flag)
{
	int i = 0 ;
	int j = 0 ;
	int flag_x = 1;
	int flag_y = 1;
	 side_one_num = 0 ;
	 side_two_num = 0 ;
	int num_x ;
	int num_y;

	num_x = strlen( string_x);
	num_y = strlen( string_y);

//	if( num_x < side_one_max || num_y < side_two_max)
//			return 0;

	

	for(i = 0 ;i < num_x; i ++)
	{
		if(( string_x[i] - 48) == 0 )
		{
			if(array_side_one[i] == 0)
			{
				;
			}
			else
			{
				return 0;
			}
		}
		else if(( string_x[i] - 48)  == 1 )
		{
			if( array_side_one[i] == chess_flag)
			{
				;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			 printf("error \n");
		}
	}


	for( j = 0 ;j < num_y;j ++)
	{
		if( (string_y[j] - 48)  == 0)
		{
			if(array_side_two[j] == 0)
			{
				;
			}
			else
			{
				return 0;
			}
		}
		else if ((string_y[j] - 48) == 1)
		{
			if(array_side_two[j] == chess_flag)
			{
				;
			}
			else
			{
				return 0;
			}
		}
		else
			{
			 printf("error\n");
			}
	}


	if( flag_x  && flag_y)
	{
		for( i = num_x ;i < side_one_max && array_side_one[i] == 0 ;i ++)
			side_one_num ++;

		for( j = num_y; j < side_two_max && array_side_two[j] == 0; j ++)
			side_two_num ++;
	}

	return 1;
}

int search_pattern_double(char * string_x ,char * string_y , int chess_flag)
{
	if ( search_pattern(string_x ,string_y,chess_flag))
		return 1;
	else if (search_pattern(string_y ,string_x,chess_flag))
		return 1;
	else
		return 0;
}

/*
 *函数功能：在一个方向上，寻找类型5的点，并根据其具体情况返回相应的权值
 *
 */

int
pattern_5 (int chess_ax, int chess_ay, int locate, int chess_flag)	//寻找 类型五的点及其返回值
{
	init_pattern(chess_ax,chess_ay,locate);

  int flag_pa5 = 0;

	if( search_pattern_double("1","101",chess_flag))
	{
		flag_pa5 = 1;
	}
	else if( search_pattern_double("1","011",chess_flag))
	{
		flag_pa5 = 1;
	}
	else if( search_pattern_double("11","01",chess_flag))
	{
		flag_pa5 = 1;
	}
	else
	{
		;
	}


  if (flag_pa5 == 1)
    {
      if (chess_flag == 2)
	return 95;
      else if (chess_flag == 1)
	return 25;
      else
	{
	  return 0;
	}
    }
  else
    return 0;

}




/*
 *函数功能：在一个方向上，寻找类型4的点，并根据其具体情况返回相应的权值
 *
 *
 */


int
pattern_4 (int chess_ax, int chess_ay, int locate, int chess_flag)	// 寻找类型为4的点的权值
{

		init_pattern(chess_ax,chess_ay,locate);


  int flag_pa4 = 0;

	if(search_pattern_double("","111",chess_flag))
	{
		flag_pa4 = 1;
	}
	else if(search_pattern_double("1","11",chess_flag))
	{
		flag_pa4 = 1;
	}
#if 0
	else if(search_pattern_double("","0111",chess_flag))            //FIXME         
	{
		flag_pa4 = 1;
	}
#endif 
	else
	{
		;
	}


  if (flag_pa4 == 1)
    {
      if (side_one_num > 0 && side_two_num > 0)
	{
	  if (chess_flag == 2)
	    return 85;
	  else if (chess_flag == 1)
	    {
//	      printf ("akaedu\n");
	      return 80;
	    }
	  else
	    return 0;
	}
      else if (side_one_num > 0 || side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 1)	// 我方60
	    {
	      if (chess_flag == 2)
		return 70;
	      else if (chess_flag == 1)
		{
			return 25; // FIXME
		}
	      else
		return 0;
	    }
	  else
	    {

	      return 0;
	    }
	}
      else
	return 0;
    }
  else
    {
      return 0;
    }
}

/*
 *函数功能： 在一个方向上，寻找类型3的点，并根据其具体情况返回相应的权值
 *
 */

int
pattern_3 (int chess_ax, int chess_ay, int locate, int chess_flag)	//计算该点为类型3的权值
{
		init_pattern(chess_ax,chess_ay,locate);

  int flag_pa31 = 0;
  int flag_pa32 = 0;

	if(  search_pattern_double("1","1",chess_flag) )
	{
		flag_pa31 = 1;
	}
	else if( search_pattern_double("","11",chess_flag))	
	{
		flag_pa31 = 1;
	}
	else if( search_pattern_double("1","01",chess_flag))
	{
		flag_pa32 = 1;
	}
	#if 0
	else if( search_pattern_double("","011",chess_flag))      //FIXME
	{
		flag_pa33 = 1;
	}

	#endif 
	else
		{
			;
		}

  if (flag_pa31 == 1)
    {
      if (side_one_num > 0 && side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 3)
	    {
	      if (chess_flag == 2)
		return 30;
	      else if (chess_flag == 1)
		{
//			printf("akaedu\n");       //FIXME
		return 28;
		}
	      else
		return 0;
	    }
	  else if (side_one_num + side_two_num == 2)
	    {
	      if (chess_flag == 2)
		return 27;
	      else if (chess_flag == 1)
		return 22;
	      else
		return 0;
	    }
	  else
	    return 0;
	}
      else if (side_one_num > 0 || side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 2)
	    {
	      if (chess_flag == 2)
		return 13;
	      else if (chess_flag == 1)
		return 8;
	      else
		return 0;
	    }
	  else
	    {
	      return 0;
	    }
	}
      else
	{
	  return 0;
	}
    }
  else if (flag_pa32 == 1)
    {
      if (side_one_num > 0 && side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 2)
	    {
	      if (chess_flag == 2)
		return 27;
	      else if (chess_flag == 1)
		return 25;
	      else
		return 0;
	    }
	  else
	    {
	      return 0;
	    }
	}
      else if (side_one_num > 0 || side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 1)
	    {
	      if (chess_flag == 2)
		return 13;                   // 25
	      else if (chess_flag == 1)
		return 8;                  // 8
	      else
		return 0;
	    }
	  else
	    {
	      return 0;

	    }
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      return 0;
    }

}


/*
 *函数功能：在一个方向，寻找类型2的点，并根据其具体情况返回相应的权值
 */


int
pattern_2 (int chess_ax, int chess_ay, int locate, int chess_flag)	// 寻找类型为2的点
{

   init_pattern(chess_ax,chess_ay,locate);

  int flag_pa21 = 0;
  int flag_pa22 = 0;
  int flag_pa23 = 0;
  //int dn = 0;

	if(search_pattern_double("","1",chess_flag))
		flag_pa21 = 1;
	else if(search_pattern_double("","01",chess_flag))
		flag_pa22 = 1;
	else if(search_pattern_double("","001",chess_flag))
		flag_pa23 = 1;
	else
	{
		;
	}

  if (flag_pa21 == 1)
    {
      if (side_one_num > 0 && side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 3)
	    return 50;
	  else
	    return 40;
	}
      else if (side_one_num > 0 || side_two_num > 0)
	{
	  if (side_one_num + side_two_num > 3)
	    return 3;
	  else
	    return 2;
	}
      else
	{
	  return 0;
	}


    }
  else if (flag_pa22 == 1)
    {
      if (side_one_num > 0 && side_two_num > 0)
	{
	  if (side_one_num + side_two_num > 2)
	    return 0;          //7
	  else
	    return 0;          //6
	}
      else if (side_one_num > 0 || side_two_num > 0)
	{
	  if (side_one_num + side_two_num > 3)
	    return 0;           // 3
	  else
	    return 0;           //0
	}
      else
	{
	  return 0;
	}

    }
  else if (flag_pa23 == 1)
    {
      if (side_one_num > 0 && side_two_num > 0)
	{
	  if (side_one_num + side_two_num >= 2)
	    return 0;              //6   
	  else
	    return 0;
	}
      else if (side_one_num > 0 || side_two_num > 0)
	{
	  if (side_one_num + side_two_num > 1)
	    return 0;              //4
	  else
	    return 0;
	}
    }
  else
    {
      return 0;
    }
			return 0;
}

/*
 *函数功能：计算类型2，该点各个方向的综合分数
 */

int
calculate_pattern_2_score (int chess_ax, int chess_ay, int chess_flag)	// 计算类型2的权重  这个函数仅为当  find_chess()搜索到的权值为1 时才调用这个函数
{				//各个方向的权值
  int locate;
  int pa2_max_score = 0;
  int pa2_temp_score = 0;
  int pa2_num = 0;
  for (locate = 0; locate < 4; locate++)
    {
      pa2_temp_score = pattern_2 (chess_ax, chess_ay, locate, chess_flag);
      if (pa2_temp_score >= 40)
	{
	  pa2_num ++;
	  pa2_temp_score = pa2_temp_score / 10;
	}
      pa2_max_score = pa2_max_score + pa2_temp_score;

    }
#if 1


  if (pa2_num >= 2)
    {
      pa2_max_score = 9 * pa2_num;
    }


  if (chess_flag == 2 && pa2_num >= 2)
    return pa2_max_score + 1;
  else if (chess_flag == 1 && pa2_num >= 2)
    return pa2_max_score;
  else
 #endif

    return pa2_max_score;


}

/*
 *函数功能：计算类型3、4，及3、4类型混合，该点各个方向的综合得分
 *
 */


int
calculate_pattern_345_score (int chess_ax, int chess_ay, int chess_flag)	//  计算  类型3 4  的最终权重
{

  int pa3_max_score = 0;
  int locate = 0;
  int max_score = 0;
  int pa4_temp_score = 0 ;
  int pa3_temp_score = 0 ;
  int flag_pa4 = 0;
  int pa4_num = 0;
  int flag_pa33 = 0 ;
  int flag_pa34 = 0 ;
  int flag_pa41 = 0 ;
  int flag_pa42 = 0 ;
  int flag_pa43 = 0 ;
  int flag_pa44 = 0 ;

/******4 4 单边*/

for( locate =0 ;locate < 4 ;locate ++)
{
		pa4_temp_score = pattern_4(chess_ax,chess_ay,locate,chess_flag);
			if( pa4_temp_score == 75)
					flag_pa43++;
			else if(pa4_temp_score == 25)
					flag_pa44++;
			else 
				{
				}
}


	if(flag_pa43 >= 2)
	{
		pa4_temp_score = 81;
		printf(" flag_pa43 81\n");
	}

	if (pa4_temp_score > max_score)
			max_score = pa4_temp_score;


	if(flag_pa44 >= 2)
	{
		pa4_temp_score = 86;
		printf(" flag_pa44 86");
	}

	if( pa4_temp_score > max_score)
	{
			max_score = pa4_temp_score;
	}

					

	for( locate = 0 ; locate < 4 ;locate ++)
	{
		pa3_temp_score = pattern_4(chess_ax,chess_ay,locate,chess_flag);
				if( pa3_temp_score ==30)
						flag_pa33 ++;
				else if (pa3_temp_score == 28)
						flag_pa34 ++;
				else 
					{

					}

	}


	if( flag_pa33 >= 1 && flag_pa43 >= 1)
				pa3_temp_score = 85;

	if(pa3_temp_score >= max_score)
		max_score = pa3_temp_score ;

	if(flag_pa34 >=1 && flag_pa44 >=1)
	{
				pa3_temp_score = 84;
				printf("pa3_temp_score  84 \n");
	}

	if(pa3_temp_score >= max_score)
				pa3_temp_score = pa3_temp_score;





// 34 三四混合计算


  for (locate = 0; locate < 4; locate++)
    {
      pa4_temp_score = pattern_4 (chess_ax, chess_ay, locate, chess_flag);
			if( pa4_temp_score == 80)
//				printf("you are 80\n");
 
      if (pa4_temp_score >= 80)
	{
	  flag_pa41 = 1;
	}
      if (pa4_temp_score == 70)
	{
	  flag_pa42 = 1;
	  pa4_num++;
	}

      if (pa4_temp_score >= max_score)
	max_score = pa4_temp_score;

      pa3_max_score =
	pa3_max_score + pattern_3 (chess_ax, chess_ay, locate, chess_flag);

    }

	
  if (pa3_max_score >= 30 && flag_pa4 == 1)
    pa3_max_score = 65;
  else if (pa3_max_score >= 60 && flag_pa4 == 0)
    pa3_max_score = 60;
  else if (pa4_num >= 2)
    pa3_max_score = 82;
  else if (flag_pa41 == 1 && pa3_max_score >= 30)
    pa3_max_score = 86;
  else if (flag_pa42 == 1 && pa3_max_score >= 30)
    pa3_max_score = 74;
  else
    {

    }


  if (pa3_max_score >= max_score)
    max_score = pa3_max_score;


  int max_tmp_2 = 0;
  max_tmp_2 = calculate_pattern_2_score (chess_ax, chess_ay, chess_flag);
#if 0
  if (pa3_max_score >= 27 && pa3_max_score <= 30)
    {
      pa3_max_score += max_tmp_2;
      if (pa3_max_score >= 45)
	pa3_max_score = 45;
    }

  if (max_score <= pa3_max_score)
    max_score = pa3_max_score;

#endif

  if (max_tmp_2 >= 27)
    {
      if (max_score <= max_tmp_2)
	max_score = max_tmp_2;
    }

  return max_score;


}



/* 
 * 
 *注意单四与双三    多个四组合  横向双三
 *双单四
 */


