#pragma once

#include <QWidget>

namespace practice_0x01 {

class MainContentsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainContentsWidget(QWidget *parent = nullptr) noexcept;
    ~MainContentsWidget();

signals:
};

}
