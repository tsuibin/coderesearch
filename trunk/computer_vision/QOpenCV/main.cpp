/**************************************************************************
**   
**   Special keywords: tsuibin 11/5/2010 2010
**   Environment variables: %$VARIABLE%
**   To protect a percent sign, use '%'.
**
**************************************************************************/

#include <QtGui/QApplication>
#include "dialog.h"
#include "qcameradevice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
