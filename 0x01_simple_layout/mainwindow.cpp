#include "mainwindow.hpp"
#include "supplementinfowidget.hpp"

MainWindow::MainWindow(QWidget *parent) noexcept
    : QMainWindow(parent)
{    
    QWidget *centralWidget = new SupplementInfoWidget;
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);



    // QFrame을 컨테이너로 사용
    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Sunken);
    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    // QFrame 내부에 위젯 추가
    QLabel *label1 = new QLabel("Label inside QFrame");
    QLabel *label2 = new QLabel("Another label inside QFrame");
    frameLayout->addWidget(label1);
    frameLayout->addWidget(label2);

    // QFrame을 메인 레이아웃에 추가
    mainLayout->addWidget(frame);

    // QFrame 외부에 다른 위젯 추가
    QLabel *externalLabel = new QLabel("Label outside QFrame");
    mainLayout->addWidget(externalLabel);

    centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow() = default;
