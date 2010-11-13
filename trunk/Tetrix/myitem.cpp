//�����ṩ����ͼ�� ��ͼ����4*4�����λ����Ϣ ����ͼ�ν�����ת�仯����

#include "myitem.h"
#include <QtGlobal>
#include <time.h>

//������7������ͼ�ε�����
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

    qsrand(time(0));    //ÿ��ִ�г���Ϊ�����������ͬ�ĳ�ֵ

}

unsigned char* MyItem::getItem()
{
    unsigned char *currentItem=NULL;
    switch(qrand()%7)   //���ѡȡһ��ͼ��
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
        //���ص�ǰͼ������4*4�����е�λ����Ϣ
{
    int k = 0;
    switch(end)
    {
        case 'd' :   //���ش�������ͼ��һ��ռ����
        {
            for(int row=3;row>=0;row--)
                for(int col=0;col<4;col++)
                {
                    if(*(currentItem+row*4+col) || k ==1)
                        return row;
                }
        }
        case 'r' :  //���ش������ͼ��һ��ռ����
        {
            for(int col=3;col>=0;col--)
                for(int row=0;row<4;row++)
                {
                if(*(currentItem+row*4+col) || k ==1)
                        return col;
                }
        }
        case 'l' :  //���ش������ͼ�δӵڼ��п�ʼ
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

unsigned char* MyItem::itemChange(unsigned char *currentItem)//�ı�ͼ����״
{
    unsigned char* tempItem = new unsigned char[4*4];
     //��������ʱ�����飬���ܽ�����ȫ�ֱ�����������ܳ���
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            *(tempItem +(3-j)*4+i)=*(currentItem +i*4+j); //��ͼ����ʱ����ת90��,�ȷŵ���ʱ������
        }

    return tempItem;
}
