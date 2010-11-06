/**************************************************************************
**   
**   Special keywords: tsuibin 11/5/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qcameradevice.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void onImageArrival(const QImage & image);

private:
    Ui::Dialog *ui;
    QCameraDevice * m_camera;

};

#endif // DIALOG_H
