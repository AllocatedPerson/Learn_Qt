#include "supplementinfowidget.hpp"
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLayoutItem>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtCore/QString>

#include <QDebug>

/***********
 * Private
 */


class ScrollableListWidget : public QScrollArea
{
public:
    explicit ScrollableListWidget(bool hScroll = false, QWidget* parent = nullptr) noexcept
        : QScrollArea{parent}
        , _hScroll{hScroll}
    {
        setWidgetResizable(true);
        if (parent)
        {
            setMaximumHeight(parent->height());
        }

        auto scrollableWidget = new QWidget;
        setWidget(scrollableWidget);

        _listLayout = new QVBoxLayout;
        scrollableWidget->setLayout(_listLayout);
    };
    ~ScrollableListWidget() = default;

    auto addListedHBoxLayout(const QString& title, QHBoxLayout* contentLayout) noexcept -> void
    {
        _addListedContent(title, contentLayout);
    };
    auto addListedWidget(const QString& title, QWidget* widget) noexcept -> void
    {
        _addListedContent(title, widget);
    };

    auto activateHScroll(int width = -1) noexcept -> void
    {
        _hScroll = true;
        if (width >= 0)
        {
            resize(width, height());
        }
    };
    auto deactivateHScroll() noexcept -> void
    {
        _hScroll = false;

        for (int i = 0; i < _listLayout->count(); ++i)
        {
            auto titleLabel = dynamic_cast<QLabel*>(_listLayout->itemAt(i)->layout()->itemAt(0)->widget()); // title(QLabel)
            titleLabel->setMinimumWidth(_maxTitleWidth);
        }

        auto width = _listLayout->sizeHint().width() + _maxTitleWidth;
        setMinimumWidth(width);
    };

private:
    QVBoxLayout*    _listLayout = nullptr;
    int             _maxTitleWidth = 0;
    bool            _hScroll;

    template <typename T> // 컴파일러 지원시, concept 추가(매크로 넣어서 처리)
    auto _addListedContent(const QString& title, T* content) noexcept -> void
    {
        auto listElemLayout  = new QHBoxLayout;

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
                deactivateHScroll();
            }
        }
    };
};

/***********
 * Data
 */
/*
struct SupplementInfoWidget::Data
{
    int tmp;
};
*/

/***********
 * Interface
 */
SupplementInfoWidget::SupplementInfoWidget(QWidget *parent)
    : QWidget{parent}
    //, d{new Data}
{
    // test
    setMinimumSize(1000, 800);
    setFixedHeight(80);
    auto scrollableListWidget = new ScrollableListWidget(false, this);
    scrollableListWidget->addListedWidget(tr("test1"), new QLabel("aaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    scrollableListWidget->addListedWidget(tr("test1asdf"), new QLabel("aaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    scrollableListWidget->addListedWidget(tr("test1qewe"), new QLabel("aa"));
    scrollableListWidget->addListedWidget(tr("test1hsdfawefasdf"), new QLabel("aaaaaaaaaaaaaaa"));
    scrollableListWidget->addListedWidget(tr("teaaaaaa1aaaaaaaaaaaaaaaaaaa"), new QLabel("aaaas11"));

    auto labelLayout = new QHBoxLayout;
    labelLayout->addWidget(new QLabel("labelTest1"));
    labelLayout->addWidget(new QLabel("labelTest22"));
    labelLayout->addWidget(new QLabel("labelTest333"));
    scrollableListWidget->addListedHBoxLayout(tr("라벨레이아웃"), labelLayout);

}


