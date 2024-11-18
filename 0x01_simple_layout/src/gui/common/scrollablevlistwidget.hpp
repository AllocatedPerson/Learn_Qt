#pragma once

#include <QtWidgets/QScrollArea>
#include <QtWidgets/QHBoxLayout>

namespace practice_0x01 {

class ScrollableVListWidget : public QScrollArea
{
    Q_OBJECT
public:
    explicit ScrollableVListWidget(bool hScroll = false, QWidget *parent = nullptr) noexcept;
    ~ScrollableVListWidget();

    auto addListedWidget(const QString& title, QWidget* widget) noexcept -> void;
    auto addListedHBoxLayout(const QString& title, QHBoxLayout* contentLayout) noexcept -> void;
    auto activateHScroll(int width = -1) noexcept -> void;
    auto deactivateHScroll() noexcept -> void;

signals:

private:
    struct Data;
    std::unique_ptr<Data> d;
};

}
