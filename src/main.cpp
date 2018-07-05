#include "inc/mainwindow.h"
#include <QApplication>
#include "libary/inc/lib_visa.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    test();
    w.show();

    return a.exec();
}
