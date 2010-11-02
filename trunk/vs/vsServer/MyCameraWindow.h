#ifndef MYCAMERAWINDOW_H_
#define MYCAMERAWINDOW_H_

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>


class MyCameraWindow : public QWidget
{
    Q_OBJECT
    private:
        QOpenCVWidget *cvwidget;
        CvCapture *camera;
        
    public:
        MyCameraWindow(CvCapture *cam, QWidget *parent=0);
public slots:
        void saveCapture();
         
    protected:
        void timerEvent(QTimerEvent*);        
};


#endif /*MYCAMERAWINDOW_H_*/
