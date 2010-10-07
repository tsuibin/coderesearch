#include "common.h"
#include "com.h"

int have_chess(int x,int y)
{
	if (0 == array_chess[x][y])
		return 0;
	return 1;	
}

int make_chess(int x,int y)
{
	if (x < 0 || x > XSTEP)
		return 0;
	if (y < 0 || y > YSTEP)
		return 0;
	if (0 == have_chess(x,y))
		return 1;
	else
		return 0;				
}	

/**************************************************/
int comp(int x,int y,int who)
{
	int i,j;
	int nx,ny;
	int count;
	int len = 5;

	//right,bottom,r_b,r_t
	int dirx[4] = {1,0,1,1};
	int diry[4] = {0,1,1,-1};

	for (i = 0;i < 4;i++)
	{ 
		nx = x;
		ny = y;
		count = 0;
		for (j = 0;j < len;j++)
		{
			if(nx < 0 || nx > (XSTEP - 1))
				break;
			if(ny < 0 || ny < (YSTEP - 1))
				break;
			if (array_chess[nx][ny] != who)
				break;
			if (array_chess[nx][ny] == who)
			{
				count++;
//				printf("count = %d\n",count);
			}	
			nx += dirx[i];
			ny += diry[i]; 
		}

		if (count == 5)
		{	
		//	printf("game over! num = %d\n",num-1);
		//	printf("nx = %d,ny = %d\n",nx,ny);
			return 1;	
		}	
	}
	
	return 0;
}

int adjust(int who)
{
	int i,j;
	int m;

	for (i = 0;i < XSTEP;i++)
	{
		for (j = 0;j < YSTEP;j++)
		{ 
			if(1 == have_chess(i,j))
			{
				m = comp(i,j,who);
				if (1 == m)
					return who;
			}
		}
	}
	return 0;
}	
/***********************************************/

int record1(int a1,int b1,int a2,int b2)
{
	int ret;
	int chess = 0,blank = 0;
	chess = a1 + a2;
	blank = b1 + b2;
	
	//_oo_oo_  
	if(chess >= 4 && blank == 2)
		ret = 90000;
	//xoo_oo_	
	if(chess >= 4 && blank == 1)
		ret = 80000;
	//xoo_oox	
	if(chess >= 4 && blank == 0)
		ret = 70000;	
		
	//_o_oo_  __000_
	if(chess == 3 && blank == 2)
		ret = 9000;
	//xoo_o_	xooo__  xo_oo_
	if(chess == 3 && blank == 1)
		ret = 3000;	
		
	//__oo_ _o_o_  
	if(chess == 2 && blank == 2)
		ret = 4000;
	//xoo__	
	if(chess == 2 && blank == 1)
		ret = 500;			
	
	
	//_o__	
	if(chess == 1 && blank == 2)
		ret = 400;
	//xo__	
	if(chess == 1 && blank == 1)
		ret = 50;		
		
	if(chess == 0 && blank == 2)
		ret = 3;	
	if(chess == 0 && blank == 1)
		ret = 1;
	//xooo_x	
	if(chess < 4 && blank == 0)
		ret = 0;		

	return ret;

}

int record2(int a1,int b1,int a2,int b2)
{
	int ret;
	int chess = 0,blank = 0;
	chess = a1 + a2;
	blank = b1 + b2;
	
	//_oo_oo_  
	if(chess >= 4 && blank == 2)
		ret = 500000;
	//xoo_oo_	
	if(chess >= 4 && blank == 1)
		ret = 400000;
	//xoo_oox	xoooo_x
	if(chess >= 4 && blank == 0)
		ret = 300000;	
		
	//_o_oo_  __000_
	if(chess == 3 && blank == 2)
		ret = 12000;
	//xoo_o_	xooo__  xo_oo_
	if(chess == 3 && blank == 1)
		ret = 4500;	
		
	//__oo_ _o_o_  
	if(chess == 2 && blank == 2)
		ret = 5000;
	//xoo__	
	if(chess == 2 && blank == 1)
		ret = 600;			
	
	
	//_o__	
	if(chess == 1 && blank == 2)
		ret = 500;
	//xo__	
	if(chess == 1 && blank == 1)
		ret = 60;		
			
	if(chess == 0 && blank == 2)
		ret = 5;
	if(chess == 0 && blank == 1)
		ret = 2;
	//xooo_x	
	if(chess < 4 && blank == 0)
		ret = 0;		

	return ret;

}

int  find(int x,int y,int who)
{
	int i,j;
	int nx,ny;
	int count1[4] = {0},count2[4] = {0};
	int blank1[4] = {0},blank2[4] = {0};
	int len = 4,ret = 0;
	int rec[4] = {0};
	int flag,flag0,flag1,flag2;
	//right,bottom,r_b,l_b**left,top,l_t,r_t;
	int dirx[8] = {1,0,1,-1,-1,0,-1,1};
	int diry[8] = {0,1,1,1,0,-1,-1,-1};	
	
	for (i = 0;i < 4;i++)
	{
		nx = x;
		ny = y;
		flag = 0;flag0 = 0;
		for (j = 0;j < len;j++)
		{
			nx += dirx[i];
			ny += diry[i];

			if(nx < 0 || nx > (XSTEP - 1))
			{	
				break;
			}	
			if(ny < 0 || ny > (YSTEP - 1))
			{
				break;
			}
			
			if (array_chess[nx][ny] != who || array_chess[nx][ny] == 0)
			{
				if (array_chess[nx][ny] == 0)
				{	
					blank1[i] += 1;
				}
				else
				{
					flag0 = 1;
					if(nx <= 4 || ny <= 4)
						flag = 1;
				}
				break;
			}
			if (array_chess[nx][ny] == who)
			{	
				count1[i] += 1;
			}
		}
		nx = x;
		ny = y;
		flag1 = 0;flag2 = 0;
		for (j = 0;j < len;j++)
		{
			nx += dirx[i + 4];
			ny += diry[i + 4];

			if(nx < 0 || nx > (XSTEP - 1))
			{
				break;
			}	
			if(ny < 0 || ny > (YSTEP - 1))
			{
				break;
			}	
			if (array_chess[nx][ny] != who || array_chess[nx][ny] == 0)
			{
				if (array_chess[nx][ny] == 0)
				{	
					blank2[i] += 1;
				}	
				else
				{
					flag2 = 1;
					if ((XSTEP -nx) <= 4 || (YSTEP - ny) <= 4)
						flag1 = 1;
				}	
				break;
			}
			if (array_chess[nx][ny] == who)
			{	
				count2[i] += 1;
			}	
		}

		if(who == PLAYER1)
			rec[i] = record1(count1[i],blank1[i],count2[i],blank2[i]);
		else if (who == PLAYER2)
			rec[i] = record2(count1[i],blank1[i],count2[i],blank2[i]);

		if (flag == 1)
		{
			rec[i] = 0;
		//	printf("one :out who = %d\n",who);
		}
		if (flag1 == 1)
		{
			rec[i] = 0;
		//	printf("two :out who = %d\n",who);
		}
		/*
		if (flag0 == 1 && flag2 == 1 && ((count1[i] + count2[i]) < 4))
		{
			rec[i] = 0;
			printf("set zero who = %d\n",who);
		}
		*/
	}

	ret = rec[0] + rec[1] + rec[2] + rec[3];

	return ret;
}


void think_chess(void)
{
	int i,j;
	int rec1 = 0,rec2 = 0;
	int rec = 0,max = 0;
	array_x = 0,array_y = 0;
#if 0
 if (chess_num == 0)
    {
       midpointcircle (9 * chess_gap + chessboard_init_x,
              9 * chess_gap + chessboard_init_y, circle_r, chess_one_color     );
       array_chess[9][9] = 2;
       chess_num++;
        draw_num (9 * chess_gap + chessboard_init_x - 6, 9 * chess_gap + chessboard_init_y - 6, 0x0, chess_num);
                              return ;
     }               // 画圆
#endif
	for (i = 0;i < XSTEP;i++)
	{
		for (j = 0;j < YSTEP;j++)
		{
			if (0 == have_chess(i,j))
			{
				rec1 = find(i,j,PLAYER1);
				rec2 = find(i,j,PLAYER2);
				rec = rec1 +rec2;
				if(max <= rec)
				{
					max = rec;
					array_x = i;
					array_y = j;
				}
			}	
		}	
	}	
/*
	printf("num :%d\n",num);
	printf("max:x = %d,y = %d\n",max_x,max_y);
	
	i = max_x;
	j = max_y;
		
	cx = i * STEP + X_START;
	cy = j * STEP + Y_START;
		
	array_chess[i][j] = PLAYER2;
	printf("i = %d,j = %d\n",i,j);	
*/	
}

