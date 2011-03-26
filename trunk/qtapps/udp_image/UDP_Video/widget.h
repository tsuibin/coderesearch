#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int dataSize;

private slots:
    void readData();
private:
    Ui::Widget *ui;
    QUdpSocket m_udpSocket;
    QByteArray datagram;
};

#endif // WIDGET_H
