#include "radio.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Radio w;
    w.show();

    return a.exec();
}
