/**************************************************************************
**   
**   Special keywords: tsuibin 11/5/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    m_camera = new QCameraDevice(this);
    connect(m_camera, SIGNAL(imageReady(QImage)), this, SLOT(onImageArrival(QImage)));
    connect(ui->startButton, SIGNAL(clicked()), m_camera, SLOT(start()));
    connect(ui->stopButton, SIGNAL(clicked()), m_camera, SLOT(stop()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onImageArrival(const QImage &image)
{
    ui->view->setPixmap(QPixmap::fromImage(image));
}
