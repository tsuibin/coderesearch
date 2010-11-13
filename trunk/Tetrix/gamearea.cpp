//�������ʵ������Ϸ�����й���
#include "gamearea.h"
#include <QKeyEvent>
#include <QSound>
#include <QMessageBox>

/****************************�����ǹ��캯������������*********************************************************/

GameArea::GameArea(QWidget *parent) :
    QFrame(parent)
{

    this->init_gameArea(6,6,430,430,200,400,20,60,0);
    this->init_Game();
}

GameArea::GameArea(int speed,QWidget *parent) :
    QFrame(parent)
{
    this->init_gameArea(6,6,430,430,200,400,20,60,0);
    this->init_Game();
    this->moveTimer = new QTimer(this);
    connect(this->moveTimer,SIGNAL(timeout()),this,SLOT(moveTimer_upDate()));
    this->moveSpeed = speed;
    this->gameStart();
    this->moveTimer->start(moveSpeed);
}

GameArea::~GameArea()
{

}

/****************************��������Ҫ���ܺ���*********************************************************/

//��������һ��
void GameArea::moveOneStep()
{
     startY += step;
}
//��ʾ����һ����Ľ���
void GameArea::do_MoveNext()
{
    this->currentItem_to_currentMap();
    this->draw_gameArea();
}

void GameArea::nextItem()
{//�Ƚ����ڵ���Ϸ���򱸷�������
    copy_Map(currentMap,copyMap,map_row,map_col);
    this->clearRow();
}

//��Ϸ�Ƿ��Ѿ�����
bool GameArea::isGame_Over()
{
    if(this->isGameOver) return true;
    else return false;
}

//��ȡ����������
int GameArea::getFullRowNum()
{
    return fullRowNum;
}

//���÷�����ɫ����ͼ
void GameArea::setGameAreaColor(QColor color)
{
    gameAreaColor = color;
}

void GameArea::setBoxBrushColor(QColor color)
{
    boxBrushColor = color;
}

void GameArea::setBoxPenColor(QColor color)
{
    boxPenColor = color;
}

void GameArea::set_draw_box_picture(bool Bool)
{
    this->is_draw_box_picture = Bool;
}

void GameArea::setBoxPicture(QString fileName)
{
    this->boxPicture = fileName;
}
//���÷�����ɫ����ͼ


//�Ƿ�����һ��,���������һ�����Ƶ���
void GameArea::setKey_Down_Move_oneStep(bool Bool)
{
    this->isKey_Down_Move_OneStep = Bool;
}



//�Ƿ���ʾ����
void GameArea::setDrawGrid(bool Bool)
{
    isDrawGrid = Bool;
}

//�Ƿ���ʾ��һ��Ҫ���ֵ�ͼ��
void GameArea::setDrawNextItem(bool Bool)
{
    isDrawNextItem = Bool;
}

//�Լ�����Ϸ����ӷ���
void GameArea::setbox(int row,int col)
{
    *(copyMap+row*map_col+col) = 1;
}


//�Ƿ񲥷�����
void GameArea::setPlaySound_moveLeft(QString fileName,bool Bool)
{
    this->isPlaySound_moveLeft = Bool;
    this->sound_moveLeft = fileName;
}

void GameArea::setPlaySound_moveRight(QString fileName,bool Bool)
{
    this->isPlaySound_moveRight = Bool;
    this->sound_moveRight = fileName;
}

void GameArea::setPlaySound_moveDown(QString fileName,bool Bool)
{
    this->isPlaySound_moveDown = Bool;
    this->sound_moveDown = fileName;
}

void GameArea::setPlaySound_itemChange(QString fileName,bool Bool)
{
    this->isPlaySound_itemChange = Bool;
    this->sound_itemChange = fileName;
}

void GameArea::setPlaySound(bool Bool)
{
    this->isPlaySound_moveLeft = Bool;
    this->isPlaySound_moveRight = Bool;
    this->isPlaySound_moveDown = Bool;
    this->isPlaySound_itemChange = Bool;
}
//�Ƿ񲥷�����



/***������Ϸ������ת****/

void GameArea::setRotate(bool Bool) //������ת
{
    this->isRotate = Bool;
}

void GameArea::setRotateAngle(int angle) //˳ʱ����ת�Ƕ�
{
    this->theAngle = angle;
}

void GameArea::setGameAreaPixOrigin(int x,int y) //�µ�����ԭ��
{
    this->gameArea_X = x;
    this->gameArea_Y = y;
}

void GameArea::setGameAreaPix(int x,int y) //��Ϸ�����λ��
{
    this->pix_X = x;
    this->pix_Y = y;
}

/*****������ת******/


/****************************��������Ҫ���ܺ���*********************************************************/



/****************************�����Ǻ��Ĺ��ܺ���*********************************************************/


void GameArea::init_gameArea(int X,int Y,int frame_width,int frame_height,int width,int height,int boxStep,int start_x,int start_y)
        //��ʼ����Ϸ����,��ʼλ�ã����ߣ�С����߳�,ͼ�γ���λ��
{
    this->gameArea_width = width;
    this->gameArea_height = height;
    this->step = boxStep;
    this->init_startX = start_x;
    this->init_startY = start_y;
    this->map_row = gameArea_height / step;
    this->map_col = gameArea_width /step;

    this->resize(frame_width,frame_height);
    //����Ϸ��������Ϊ�ϴ��������
    this->move(X,Y);

    pix_gameArea = new QPixmap(this->gameArea_width,this->gameArea_height);

    this->isKey_Down_Move_OneStep =false;

    //Ĭ��״̬����
    this->isDrawGrid = true;
    this->isDrawNextItem=true;
    this->isPlaySound_moveLeft = false;
    this->isPlaySound_moveRight = false;
    this->isPlaySound_moveDown = false;
    this->isPlaySound_itemChange =false;
    this->is_draw_box_picture = false;

    //Ĭ����ɫ����
    this->gameAreaColor = Qt::white;
    this->boxBrushColor = Qt::green;
    this->boxPenColor = Qt::black;

    this->isRotate = false;
    this->theAngle = 0;
    this->gameArea_X = 0;
    this->gameArea_Y = 0;
    this->pix_X = 10;
    this->pix_Y = 10;

    myItem = new MyItem();

    this->currentMap = new unsigned char[map_row*map_col];
    this->copyMap = new unsigned char[map_row*map_col];   

}

void GameArea::init_Game() //��һ�ν�����Ϸʱ��һЩ�������г�ʼ��
{
    this->init_Map(currentMap,map_row,map_col);
    this->init_Map(copyMap,map_row,map_col);

    this->currentItem = this->currentMap;   //������ָ����г�ʼ��
    this->theNextItem = this->currentMap;   //������ָ���ָ����յ�����

    isFirstItem = true;
    isGameOver = false;
    fullRowNum = 0;

    this->draw_gameArea();
}

void GameArea::gameStart() //��Ϸ��ʼ���У�����ÿ�γ����µķ��鶼����һ���������
{
    this->startX = this->init_startX;
    this->startY = this->init_startY;
    fullRowNum = 0; //ÿ�γ���һ���µ�ͼ�ζ����ϴ�����������0
    if(isFirstItem)
    {
        this->currentItem = myItem->getItem();
        isFirstItem = false;
    }
    else this->currentItem = this->theNextItem;
    this->theNextItem = myItem->getItem();
    this->currentItem_to_currentMap();
    this->draw_gameArea();
}

void GameArea::init_Map(unsigned char *initMap,int row,int col)
        //������һ�������е���ȫ��Ϊ0
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(initMap+i*col+j)= 0;
        }
    }
}

void GameArea::draw_gameArea()  //������Ϸ���򣬰����������Ϸ���ķ���
{
    this->pix_gameArea->fill(gameAreaColor);
    if(this->isDrawGrid)
    {
        draw_Grid();
    }
    draw_currentMap();
    update();
}

void GameArea::draw_Grid()   //������Ϸ���򱳾�������
{
    QPainter painter(this->pix_gameArea);
    painter.setPen(Qt::DotLine);
    for(int i=0; i<map_row; i++)
    {
        painter.drawLine(QPoint(0,i*step),QPoint(this->gameArea_width,i*step));
    }
    for(int j=0; j<map_col; j++)
    {
        painter.drawLine(QPoint(j*step,0),QPoint(j*step,this->gameArea_height));
    }
}

void GameArea::draw_currentMap()
        //������Ϸ�����������еķ���
{
    QPainter painter(this->pix_gameArea);
    painter.setPen(this->boxPenColor);
    painter.setBrush(this->boxBrushColor);
    for(int i=0;i<map_row;i++)    //�������ϵ�ͼ����ʾ��������
    {
        for(int j=0;j<map_col;j++)
       {
             if(*(currentMap+i*map_col+j)==1)
             {
                 if(this->is_draw_box_picture)
                 {
                    QPixmap pix;
                    pix.load(this->boxPicture);
                    painter.drawPixmap(j*step,i*step,step,step,pix);
                 }

                    painter.drawRect(j*step,i*step,step,step);
             }
        }
    }
}

void GameArea::currentItem_to_currentMap()
        //����ǰͼ�μ��뵽��Ϸ����������
{
    copy_Map(copyMap,currentMap,map_row,map_col);//ʹ�ñ��ݵ��������飬��Ϊ��ǰ���飬�����ͱ�������ʾ��ͼ����ǰ��λ��
    int m_row = startY/step;
    int m_col = startX/step;
    for(int i=m_row;i<m_row+4;i++)
    {
        for(int j=m_col;j<m_col+4;j++)
        {
            *(currentMap+i*map_col+j)|=*(currentItem+(i-m_row)*4+(j-m_col));//����ת��
        }
    }
}

void GameArea::copy_Map(unsigned char *theMap,unsigned char *toMap,int row,int col)
        //��Ϸ���򱸷�
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(toMap+i*col+j)= *(theMap+i*col+j);
        }
    }
}

void GameArea::draw_nextItem() //��ʾ��һ��Ҫ���ֵ�ͼ��
{
    QPainter painter(this);
    painter.drawRect(gameArea_width+20,10,4*step,4*step);
    painter.setBrush(this->boxBrushColor);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(*(theNextItem + i*4 +j)==1)
            {
                if(this->is_draw_box_picture)
                 {
                    QPixmap pix;
                    pix.load(this->boxPicture);
                    painter.drawPixmap(gameArea_width+20+j*step,10+i*step,step,step,pix);
                 }
                painter.drawRect(gameArea_width+20+j*step,10+i*step,step,step);
            }
        }
}

void GameArea::paintEvent(QPaintEvent *e)  //�ػ��¼�
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);//�������Է����
    if(this->isRotate)  //�����ת��Ϸ����
    {
        painter.translate(gameArea_X,gameArea_Y);
        painter.rotate(this->theAngle);
        painter.drawPixmap(QPoint(pix_X,pix_Y),*pix_gameArea);
    }
    else
    {
        painter.drawPixmap(QPoint(pix_X,pix_Y),*pix_gameArea);
    }
    if(this->isDrawNextItem)  //�Ƿ���ʾ��һ��ͼ��
    {
        draw_nextItem();
    }
}


void GameArea::keyPressEvent(QKeyEvent *event)  //���̴���
{
    switch(event->key())
    {
        case Qt::Key_Left :   //����İ���
        {
            startX=startX - step;
            if(isMoveLeft()) startX = startX+step;
            else
            {
                currentItem_to_currentMap();
                this->draw_gameArea();
                if(isPlaySound_moveLeft)
                {
                    playSound(sound_moveLeft);
                }
            }
            break;
        }
        case Qt::Key_Right :    //���ҵİ���
        {
            startX=startX + step;
            if(isMoveRight()) startX = startX-step;
            else
            {
                currentItem_to_currentMap();
                this->draw_gameArea();

                if(isPlaySound_moveRight)
                {
                    playSound(sound_moveRight);
                }
            }

            break;
        }
        case Qt::Key_Up :     //���ϵİ���
        {
            do_itemChange();
            currentItem_to_currentMap();
            this->draw_gameArea();
            if(isPlaySound_itemChange)
            {
                playSound(sound_itemChange);
            }
           break;
        }
        case Qt::Key_Down :    //���µİ���
        {
            if(this->isKey_Down_Move_OneStep)   //Ĭ��һ������һ��
            {  
                startY+=step;
                if(this->isMoveEnd()) startY-=step; //������ֻ������һ���Ĳ�����������������
                else
                {
                    currentItem_to_currentMap();
                    this->draw_gameArea();
                    if(isPlaySound_moveDown)
                    {
                        playSound(sound_moveDown);
                    }
                }
            }
            else            //һ�����Ƶ���
            {
                int i=0;
                while(!this->isMoveEnd())
                {
                    startY +=step;
                    i++;
                }
                startY -=step;
                if(i>0)
                {
                    currentItem_to_currentMap();
                    this->draw_gameArea();
                    if(isPlaySound_moveDown)
                    {
                        playSound(sound_moveDown);
                    }
                }
            }

            break;
        }
        default: QFrame::keyPressEvent(event);    //������������
    }

}


bool GameArea::isMoveEnd()
        //�ж�ͼ���Ƿ��ƶ������������ͱ��ͼ���غ���
{
    int item_endRow = myItem->currentItem_endPos(currentItem,'d');

    int itemRow = startY/step;  //ͼ�������������λ��
    int itemCol = startX/step;

/*��ע��������ж�����Ϊ�����������Ѿ���ͼ������һ����Ȼ�󾭹�������жϣ�����ʱ��ͼ�ε�λ�û�û�ڴ�������ʾ��*/
    if(itemRow+item_endRow>=map_row)//���ͼ�ε�������ײ�
    {
        return true;
    }
    for(int i=item_endRow;i>=0;i--) //�Ƿ�����е�ͼ���غ�
    {
        for(int j=3;j>=0;j--)
        {
           if(*(copyMap+(itemRow+i)*map_col+itemCol+j) && *(currentItem+i*4+j)==1)
            {

               if(startX==init_startX&&startY<=20) isGameOver = true;
               //���ͼ��һ�����ͺͱ��ͼ���غ��ˣ���ô��Ϸ����

               return true;
            }
        }
    }
    return false;
}

bool GameArea::isMoveLeft()
        //�Ƿ�����߻�ͱ��ͼ���غ���
{
    int item_endLeft = myItem->currentItem_endPos(currentItem,'l');
    int item_Col = startX/step;
    if(item_Col+item_endLeft<0)
        return true;

     if(isMoveEnd())
    {
        return true;
    }
    return false;
}

bool GameArea::isMoveRight()
        //�Ƿ����ұ߻�ͱ��ͼ���غ���
{
    int item_endRight = myItem->currentItem_endPos(currentItem,'r');
    int item_Col = startX/step;
    if(item_Col+item_endRight >= map_col)
        return true;
    if(isMoveEnd())
    {
        return true;
    }
    return false;
}

void GameArea::do_itemChange()//�Ըı�ͼ�κ󳬳����ڻ�ͱ��ͼ���غϽ��д���
{
    unsigned char *tempItem;
    tempItem = currentItem; //�ȱ������ڵ�ͼ��
    currentItem = myItem->itemChange(currentItem); //����ͼ�α仯
    if(startX<0) startX = 0; //�󳬽磬�����俿��
    if((startX + 4*step)> gameArea_width) startX = gameArea_width - 4*step;
    //�ҳ��磬�������ұ߿���
    if(isMoveEnd())
    //����ͱ��ͼ���غϣ�������ı�
    {
        currentItem = tempItem;
    }
}

void GameArea::clearRow() //�����������
{
    int temp1 = 1;
    for(int i=map_row-1;i>0;i--) //��������ɨ����������
    {
        for(int j=0;j<map_col;j++)
        {
            temp1 = *(copyMap+i*map_col+j) && temp1;
        }
        if(temp1) //�����һ��ȫΪ1��˵�������������
        {
            fullRowNum++;
            for(int row = i;row>0;row--)   //���������м�������ĸ��о���������һ��
            for(int col = 0;col<map_col;col++)
            {
                *(copyMap+row*map_col+col)=*(copyMap+(row-1)*map_col+col);
            }
            i=i+1; //���¿�ʼɨ������ͼ
        }
        temp1 =1;
    }
}

void GameArea::playSound(QString fileName) //ʵ�������Ĳ���
{
    QSound sound(fileName);
    sound.play();
}

void GameArea::moveTimer_upDate() //��ʱ���������
{
    this->moveOneStep();
    if(this->isMoveEnd())
    {
        if(this->isGameOver)
        {
            this->moveTimer->stop();
            QMessageBox::warning(this,tr("warning"),tr("Game Over!"),QMessageBox::Yes);
            this->init_Game();
            this->gameStart();
            this->moveTimer->start(moveSpeed);
        }
        else
        {
            this->nextItem();
            this->gameStart();
        }
    }
    else
    {
        this->do_MoveNext();
    }
}
