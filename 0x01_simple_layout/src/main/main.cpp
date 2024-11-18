#include "mainwindow.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    practice_0x01::MainWindow w;
    w.show();
    return a.exec();
}
