/**************************************************************************
**   
**   Special keywords: tsuibin 10/28/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>
//#include "cv.h"
//#include "highgui.h"
#include <stdio.h>
#include <ctype.h>

class video : public QObject
{
    Q_OBJECT
public:
    explicit video(QObject *parent = 0);
   // CvCapture* capture;

signals:

public slots:

};

#endif // VIDEO_H
