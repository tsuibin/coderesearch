#include <QtGui/QApplication>
#include "mp3player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mp3Player w;
    w.show();

    return a.exec();
}
