#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,500);
    this->gameArea = new GameArea(this);
    this->timer = new QTimer(this);
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timer_upDate()));
    score =0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::timer_upDate() //��ʱ���������
{
    this->gameArea->moveOneStep(); //���ƶ�һ������ʱ��û����ʾ����
    if(this->gameArea->isMoveEnd()) //����޷��ƶ��������˻������
    {
        if(this->gameArea->isGame_Over()) //����ǽ�����
        {
            this->timer->stop(); //ֹͣ��ʱ
            QMessageBox::warning(this,tr("warning"),tr("Game Over!"),QMessageBox::Yes);
            //�����Ի���
            this->score =0; //��շ���
            this->gameArea->init_Game(); //���¿�ʼ��Ϸ
            this->gameArea->gameStart();
            this->timer->start(500);
        }
        else  //������ƶ�������
        {
            this->gameArea->nextItem(); //������һ��ͼ��
            int num = this->gameArea->getFullRowNum(); //�������������
            this->doScore(num); //��ʾ����
            this->gameArea->gameStart(); //������Ϸ
        }
    }
    else //���û�е���
    {
        this->gameArea->do_MoveNext(); //��ʾ��������һ����Ľ���
    }
}

void Widget::on_pushButton_clicked() //��ʼ��ť
{
    this->gameArea->init_Game(); //��һ�ν�����Ϸʱ���еĳ�ʼ��
    this->gameArea->gameStart();  //��ʼ��Ϸ
    this->timer->start(500);  //������ʱ��
    this->gameArea->setFocus();  //����Ϸ�����ý��㣬����������Ӧ����
}

void Widget::doScore(int num)  //��ʾ����
{
    score += num*100;
    this->ui->label_2->setText(tr("%1").arg(score));
}

void Widget::on_pushButton_2_clicked() //��ͣ��ť
{
    if(this->ui->pushButton_2->isChecked())
    {
        this->timer->stop();
        this->ui->pushButton_2->setText(tr("ȡ����ͣ"));
    }
    else
    {
        this->timer->start(500);
        this->ui->pushButton_2->setText(tr("��ͣ��Ϸ"));
        this->gameArea->setFocus();
    }
}

void Widget::on_pushButton_3_clicked() //���¿�ʼ
{
    this->timer->stop();
    this->on_pushButton_clicked();
}

void Widget::on_pushButton_4_clicked()  //�ı���ɫ
{
    this->gameArea->setGameAreaColor(QColor(255,255,0,qrand()%255));
    //������Ϸ���򱳾���ɫ
    this->gameArea->setBoxBrushColor(QColor(0,255,0,qrand()%255));
    //����С���鱳����ɫ
    this->gameArea->setBoxPenColor(QColor(0,0,0,qrand()%255));
    //����С����߿���ɫ
    this->gameArea->draw_gameArea();
    //������Ϸ����
    this->gameArea->setFocus();
}

void Widget::on_pushButton_5_clicked() //������ͼ
{
    this->gameArea->set_draw_box_picture(true);
    //ȷ��ʹ�÷��鱳��ͼƬ
    this->gameArea->setBoxPicture("box.gif");
    //��ӷ��鱳��ͼƬ
    this->gameArea->draw_gameArea();
    //������ʾ����
    this->gameArea->setFocus();
}

void Widget::on_pushButton_6_clicked()  //������ʾ
{
    if(this->ui->pushButton_6->isChecked())
    {
        this->gameArea->setDrawGrid(false);
    }
    else
    {
        this->gameArea->setDrawGrid(true);
    }
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
}

void Widget::on_pushButton_7_clicked()  //������ʾ
{
    if(this->ui->pushButton_7->isChecked())
    {
        this->gameArea->setDrawNextItem(false);
    }
    else
    {
        this->gameArea->setDrawNextItem(true);
    }
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
}

void Widget::on_pushButton_8_clicked()  //��������
{
    if(this->ui->pushButton_8->isChecked())
    {
        this->gameArea->setPlaySound_itemChange("changeItem.wav",true);
        this->gameArea->setPlaySound_moveDown("moveDown.wav",true);
        this->gameArea->setPlaySound_moveLeft("moveLeft.wav",true);
        this->gameArea->setPlaySound_moveRight("moveLeft.wav",true);
        this->ui->pushButton_8->setText(tr("�ر�����"));
    }
    else
    {
        this->gameArea->setPlaySound(false); //�ر�����
        this->ui->pushButton_8->setText(tr("������"));
    }
    this->gameArea->setFocus();
}

void Widget::on_pushButton_9_clicked() //�Ƿ�׹��
{
    if(this->ui->pushButton_9->isChecked())
    {
        this->gameArea->setKey_Down_Move_oneStep(true);
        //��һ�����·����������һ��
    }
    else
    {
        this->gameArea->setKey_Down_Move_oneStep(false);
        //��һ�����·�������ƶ�����
    }
    this->gameArea->setFocus();
}

void Widget::on_pushButton_10_clicked() //��ӷ���
{
    this->gameArea->init_Game();
    //�����Ϸ����
    this->gameArea->setbox(10,4);
    this->gameArea->setbox(10,5);
    this->gameArea->setbox(10,6);
    //�ڵ�10�е�4��5��6�������������
    this->gameArea->gameStart();
    //���¿�ʼ��Ϸ
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
}

void Widget::on_pushButton_11_clicked() //��ת��Ϸ
{
    this->gameArea->setRotate(true);
    //������ת
    this->gameArea->setGameAreaPixOrigin(100,200);
    //������Ϸ�����µ�����ԭ��
    this->gameArea->setGameAreaPix(-100,-200);
    //������Ϸ�����λ��
    this->gameArea->setRotateAngle(qrand()%360);
    //��ת����
    this->gameArea->draw_gameArea();
     this->gameArea->setFocus();
}
