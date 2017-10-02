#include "windowHolder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    windowHolder* WH = windowHolder::getInstance();

    WH->LoginWindowShow();

    return a.exec();
}
