//该类提供方块图形 ，图形在4*4区域的位置信息 ，对图形进行旋转变化功能

#include "myitem.h"
#include <QtGlobal>
#include <time.h>

//以下是7个方块图形的数组
unsigned char item1[4*4]=
{
0,1,1,0,
0,1,1,0,
0,0,0,0,
0,0,0,0
};
unsigned char item2[4*4]=
{
0,0,0,1,
0,0,0,1,
0,0,0,1,
0,0,0,1
};

unsigned char item3[4*4]=
{
0,0,1,0,
0,1,1,0,
0,1,0,0,
0,0,0,0
};
unsigned char item4[4*4]=
{
0,1,0,0,
0,1,1,0,
0,0,1,0,
0,0,0,0
};
unsigned char item5[4*4]=
{
0,0,1,0,
0,0,1,0,
0,1,1,0,
0,0,0,0
};
unsigned char item6[4*4]=
{
0,1,0,0,
0,1,0,0,
0,1,1,0,
0,0,0,0
};

unsigned char item7[4*4]=
{
0,1,0,0,
1,1,1,0,
0,0,0,0,
0,0,0,0
};

MyItem::MyItem()
{

    qsrand(time(0));    //每次执行程序为随机数产生不同的初值

}

unsigned char* MyItem::getItem()
{
    unsigned char *currentItem=NULL;
    switch(qrand()%7)   //随机选取一个图形
    {
        case 0 : currentItem = item1;break;
        case 1 : currentItem = item2;break;
        case 2 : currentItem = item3;break;
        case 3 : currentItem = item4;break;
        case 4 : currentItem = item5;break;
        case 5 : currentItem = item6;break;
        case 6 : currentItem = item7;break;
    }
    return currentItem;
}

int MyItem::currentItem_endPos(unsigned char *currentItem,unsigned char end)
        //返回当前图形在其4*4网格中的位置信息
{
    int k = 0;
    switch(end)
    {
        case 'd' :   //返回从上面数图形一共占几行
        {
            for(int row=3;row>=0;row--)
                for(int col=0;col<4;col++)
                {
                    if(*(currentItem+row*4+col) || k ==1)
                        return row;
                }
        }
        case 'r' :  //返回从左边数图形一共占几列
        {
            for(int col=3;col>=0;col--)
                for(int row=0;row<4;row++)
                {
                if(*(currentItem+row*4+col) || k ==1)
                        return col;
                }
        }
        case 'l' :  //返回从左边数图形从第几列开始
        {
            for(int col=0;col<4;col++)
                for(int row=0;row<4;row++)
                {
                    if(*(currentItem+row*4+col) || k ==1)
                        return col;
                }
        }
        default: return 0;
    }
}

unsigned char* MyItem::itemChange(unsigned char *currentItem)//改变图形形状
{
    unsigned char* tempItem = new unsigned char[4*4];
     //必须用临时的数组，不能将其变成全局变量，否则可能出错
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            *(tempItem +(3-j)*4+i)=*(currentItem +i*4+j); //将图形逆时针旋转90度,先放到临时数组中
        }

    return tempItem;
}
