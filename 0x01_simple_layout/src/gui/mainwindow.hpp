#pragma once

#include <QtWidgets/QMainWindow>

namespace practice_0x01 {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr) noexcept;
    ~MainWindow();
};

}
