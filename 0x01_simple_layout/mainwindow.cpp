#include "mainwindow.hpp"
#include "supplementinfowidget.hpp"

/***********
 * Data
 */
struct MainWindow::Data
{
};

/***********
 * Interface
 */
MainWindow::MainWindow(QWidget *parent) noexcept
    : QMainWindow(parent)
    , d{new Data}
{    
    QWidget *centralWidget = new SupplementInfoWidget;
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() = default;
