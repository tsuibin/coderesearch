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

void Widget::timer_upDate() //定时器溢出处理
{
    this->gameArea->moveOneStep(); //先移动一步，这时并没有显示出来
    if(this->gameArea->isMoveEnd()) //如果无法移动，到底了或结束了
    {
        if(this->gameArea->isGame_Over()) //如果是结束了
        {
            this->timer->stop(); //停止计时
            QMessageBox::warning(this,tr("warning"),tr("Game Over!"),QMessageBox::Yes);
            //弹出对话框
            this->score =0; //清空分数
            this->gameArea->init_Game(); //重新开始游戏
            this->gameArea->gameStart();
            this->timer->start(500);
        }
        else  //如果是移动到底了
        {
            this->gameArea->nextItem(); //出现下一个图形
            int num = this->gameArea->getFullRowNum(); //获得已满的行数
            this->doScore(num); //显示分数
            this->gameArea->gameStart(); //继续游戏
        }
    }
    else //如果没有到底
    {
        this->gameArea->do_MoveNext(); //显示方块下移一步后的界面
    }
}

void Widget::on_pushButton_clicked() //开始按钮
{
    this->gameArea->init_Game(); //第一次进入游戏时进行的初始化
    this->gameArea->gameStart();  //开始游戏
    this->timer->start(500);  //开启定时器
    this->gameArea->setFocus();  //让游戏区域获得焦点，这样才能响应键盘
}

void Widget::doScore(int num)  //显示分数
{
    score += num*100;
    this->ui->label_2->setText(tr("%1").arg(score));
}

void Widget::on_pushButton_2_clicked() //暂停按钮
{
    if(this->ui->pushButton_2->isChecked())
    {
        this->timer->stop();
        this->ui->pushButton_2->setText(tr("取消暂停"));
    }
    else
    {
        this->timer->start(500);
        this->ui->pushButton_2->setText(tr("暂停游戏"));
        this->gameArea->setFocus();
    }
}

void Widget::on_pushButton_3_clicked() //重新开始
{
    this->timer->stop();
    this->on_pushButton_clicked();
}

void Widget::on_pushButton_4_clicked()  //改变颜色
{
    this->gameArea->setGameAreaColor(QColor(255,255,0,qrand()%255));
    //更改游戏区域背景颜色
    this->gameArea->setBoxBrushColor(QColor(0,255,0,qrand()%255));
    //更改小方块背景颜色
    this->gameArea->setBoxPenColor(QColor(0,0,0,qrand()%255));
    //更改小方块边框颜色
    this->gameArea->draw_gameArea();
    //更新游戏区域
    this->gameArea->setFocus();
}

void Widget::on_pushButton_5_clicked() //方块贴图
{
    this->gameArea->set_draw_box_picture(true);
    //确认使用方块背景图片
    this->gameArea->setBoxPicture("box.gif");
    //添加方块背景图片
    this->gameArea->draw_gameArea();
    //更新显示区域
    this->gameArea->setFocus();
}

void Widget::on_pushButton_6_clicked()  //网格显示
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

void Widget::on_pushButton_7_clicked()  //方块提示
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

void Widget::on_pushButton_8_clicked()  //声音开关
{
    if(this->ui->pushButton_8->isChecked())
    {
        this->gameArea->setPlaySound_itemChange("changeItem.wav",true);
        this->gameArea->setPlaySound_moveDown("moveDown.wav",true);
        this->gameArea->setPlaySound_moveLeft("moveLeft.wav",true);
        this->gameArea->setPlaySound_moveRight("moveLeft.wav",true);
        this->ui->pushButton_8->setText(tr("关闭声音"));
    }
    else
    {
        this->gameArea->setPlaySound(false); //关闭音乐
        this->ui->pushButton_8->setText(tr("打开声音"));
    }
    this->gameArea->setFocus();
}

void Widget::on_pushButton_9_clicked() //是否坠落
{
    if(this->ui->pushButton_9->isChecked())
    {
        this->gameArea->setKey_Down_Move_oneStep(true);
        //按一下向下方向键，下移一步
    }
    else
    {
        this->gameArea->setKey_Down_Move_oneStep(false);
        //按一下向下方向键，移动到底
    }
    this->gameArea->setFocus();
}

void Widget::on_pushButton_10_clicked() //添加方块
{
    this->gameArea->init_Game();
    //清空游戏区域
    this->gameArea->setbox(10,4);
    this->gameArea->setbox(10,5);
    this->gameArea->setbox(10,6);
    //在第10行第4，5，6列添加三个方块
    this->gameArea->gameStart();
    //重新开始游戏
    this->gameArea->draw_gameArea();
    this->gameArea->setFocus();
}

void Widget::on_pushButton_11_clicked() //旋转游戏
{
    this->gameArea->setRotate(true);
    //开启旋转
    this->gameArea->setGameAreaPixOrigin(100,200);
    //设置游戏区域新的坐标原点
    this->gameArea->setGameAreaPix(-100,-200);
    //设置游戏区域的位置
    this->gameArea->setRotateAngle(qrand()%360);
    //旋转度数
    this->gameArea->draw_gameArea();
     this->gameArea->setFocus();
}
