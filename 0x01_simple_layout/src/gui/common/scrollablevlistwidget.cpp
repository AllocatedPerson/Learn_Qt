#include "scrollablevlistwidget.hpp"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLayoutItem>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QString>

#include <QtCore/QDebug>

namespace practice_0x01 {

/***********
 * Implementation
 */
struct ScrollableVListWidget::Data
{
    QVBoxLayout*    _listLayout = nullptr;
    int             _maxTitleWidth = 0;
    bool            _hScroll;

    template <typename T> // + concept
    auto _addListedContent(ScrollableVListWidget* wrapper, const QString& title, T* content) noexcept -> void
    {
        auto listElemLayout = new QHBoxLayout;

        auto label = new QLabel(title);
        auto labelWidth = int{(label->font().pointSize() / 2 + 1) * static_cast<int>(title.length())};
        label->setMinimumWidth(labelWidth);
        label->setAlignment(Qt::AlignLeft);
        listElemLayout->addWidget(label);

        if constexpr (std::is_base_of<QWidget, T>::value)
        {
            listElemLayout->addWidget(content);
        }
        else if constexpr (std::is_base_of<QHBoxLayout, T>::value)
        {
            listElemLayout->addLayout(content);
        }

        _listLayout->addLayout(listElemLayout);

        if (labelWidth >= _maxTitleWidth)
        {
            _maxTitleWidth = labelWidth;

            if (_hScroll == false)
            {
                wrapper->deactivateHScroll();
            }
        }
    }

    /* 2번
    auto _activateHScroll(ScrollableVListWidget* wrapper, int width) noexcept -> void
    {
        _hScroll = true;
        if (width >= 0)
        {
            wrapper->resize(width, wrapper->height());
        }
    }

    auto _deactivateHScroll(ScrollableVListWidget* wrapper) noexcept -> void
    {
        _hScroll = false;

        for (int i = 0; i < _listLayout->count(); ++i)
        {
            auto titleLabel = dynamic_cast<QLabel *>(_listLayout->itemAt(i)->layout()->itemAt(0)->widget()); // title(QLabel)
            titleLabel->setMinimumWidth(_maxTitleWidth);
        }

        auto width = _listLayout->sizeHint().width() + _maxTitleWidth;
        wrapper->setMinimumWidth(width);
    }
    */
};


/***********
 * Interface
 */
ScrollableVListWidget::ScrollableVListWidget(bool hScroll, QWidget *parent) noexcept
    : QScrollArea{parent}
    , d{new Data}
{
    setWidgetResizable(true);
    if (parent)
    {
        setMaximumHeight(parent->height());
    }

    auto scrollableWidget = new QWidget;
    setWidget(scrollableWidget);

    d->_listLayout = new QVBoxLayout;
    scrollableWidget->setLayout(d->_listLayout);
}

ScrollableVListWidget::~ScrollableVListWidget() = default;

auto ScrollableVListWidget::addListedWidget(const QString& title, QWidget* widget) noexcept -> void
{
    d->_addListedContent(this, title, widget);
}

auto ScrollableVListWidget::addListedHBoxLayout(const QString& title, QHBoxLayout* layout) noexcept -> void
{
    d->_addListedContent(this, title, layout);
}

// 1번
auto ScrollableVListWidget::activateHScroll(int width) noexcept -> void
{
    d->_hScroll = true;
    if (width >= 0)
    {
        resize(width, height());
    }
}

auto ScrollableVListWidget::deactivateHScroll() noexcept -> void
{
    d->_hScroll = false;

    for (int i = 0; i < d->_listLayout->count(); ++i)
    {
        auto titleLabel = dynamic_cast<QLabel *>(d->_listLayout->itemAt(i)->layout()->itemAt(0)->widget()); // title(QLabel)
        titleLabel->setMinimumWidth(d->_maxTitleWidth);
    }

    auto width = d->_listLayout->sizeHint().width() + d->_maxTitleWidth;
    setMinimumWidth(width);
}

/* 2번
auto ScrollableVListWidget::activateHScroll(int width) noexcept -> void
{
    d->_activateHScroll(this, width);
}

auto ScrollableVListWidget::deactivateHScroll() noexcept -> void
{
    d->_deactivateHScroll(this);
}
*/

}
