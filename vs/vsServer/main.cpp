#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <assert.h>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include "QOpenCVWidget.h"
#include "MyCameraWindow.h"

int main(int argc, char **argv) {
    CvCapture * camera = cvCreateCameraCapture(0);
    assert(camera);
    IplImage * image=cvQueryFrame(camera);
    assert(image);

    printf("Image depth=%i \n", image->depth);//8
    printf("Image nChannels=%i \n", image->nChannels);//3

    QApplication app(argc, argv);
    MyCameraWindow *mainWin = new MyCameraWindow(camera);
    mainWin->setWindowTitle("AKA Loco Team");
    mainWin->show();    
    int retval = app.exec();
    
    cvReleaseCapture(&camera);
    
    return retval;
}

