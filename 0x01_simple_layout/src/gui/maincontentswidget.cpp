#include "maincontentswidget.hpp"
#include "common/scrollablevlistwidget.hpp"
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

namespace practice_0x01 {

MainContentsWidget::MainContentsWidget(QWidget *parent) noexcept
    : QWidget{parent}
{
    // test
    setMinimumSize(1000, 800);
    setFixedHeight(80);
    auto scrollableVListWidget = new ScrollableVListWidget(false, this);
    scrollableVListWidget->addListedWidget(tr("test1"), new QLabel("aaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    scrollableVListWidget->addListedWidget(tr("test1asdf"), new QLabel("aaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    scrollableVListWidget->addListedWidget(tr("test1qewe"), new QLabel("aa"));
    scrollableVListWidget->addListedWidget(tr("test1hsdfawefasdf"), new QLabel("aaaaaaaaaaaaaaa"));
    scrollableVListWidget->addListedWidget(tr("teaaaaaa1aaaaaaaaaaaaaaaaaaa"), new QLabel("aaaas11"));

    auto labelLayout = new QHBoxLayout;
    labelLayout->addWidget(new QLabel("labelTest1"));
    labelLayout->addWidget(new QLabel("labelTest22"));
    labelLayout->addWidget(new QLabel("labelTest333"));
    scrollableVListWidget->addListedHBoxLayout(tr("라벨레이아웃"), labelLayout);

}

MainContentsWidget::~MainContentsWidget() = default;

}
