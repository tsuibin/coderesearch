#include <QtGui/QApplication>
#include "imageclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageClient w;
    w.show();

    return a.exec();
}
