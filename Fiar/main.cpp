#include "fiar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fiar w;
    w.show();

    return a.exec();
}
