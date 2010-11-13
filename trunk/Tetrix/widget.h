#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamearea.h"
namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void doScore(int);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;
    GameArea *gameArea;
    QTimer *timer;
    int score;
private slots:
    void on_pushButton_11_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void timer_upDate();
    void on_pushButton_clicked();


};

#endif // WIDGET_H
