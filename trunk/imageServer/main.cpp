#include <QtGui/QApplication>
#include "imageserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageServer w;
    w.show();

    return a.exec();
}
