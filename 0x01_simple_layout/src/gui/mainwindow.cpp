#include "mainwindow.hpp"
#include "maincontentswidget.hpp"

namespace practice_0x01 {

/***********
 * Interface
 */
MainWindow::MainWindow(QWidget *parent) noexcept
    : QMainWindow(parent)
{
    auto mainContentsWidget = new MainContentsWidget;
    setCentralWidget(mainContentsWidget);
}

MainWindow::~MainWindow(){}

}
