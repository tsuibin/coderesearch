
#include "MyCameraWindow.h"

MyCameraWindow::MyCameraWindow(CvCapture *cam, QWidget *parent) : QWidget(parent) {
    camera = cam;
    QVBoxLayout *layout = new QVBoxLayout;
    cvwidget = new QOpenCVWidget(this);
    layout->addWidget(cvwidget);
    setLayout(layout);
    resize(500, 400);

    QPushButton *pushButton = new QPushButton(this);
    pushButton->setText("Take a Photo");
    pushButton->setGeometry(250,0,100,20);
    pushButton->show();

    connect(pushButton,SIGNAL(clicked()),this,SLOT(saveCapture()));

    startTimer(30);  // 0.1-second timer
 }

void MyCameraWindow::timerEvent(QTimerEvent*) {
    IplImage *image=cvQueryFrame(camera);
    cvwidget->putImage(image,1);
}

void MyCameraWindow::saveCapture() {
    IplImage *image=cvQueryFrame(camera);
    cvwidget->putImage(image,1);
}
