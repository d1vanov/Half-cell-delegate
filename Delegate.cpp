#include "Delegate.h"
#include <QPainter>

Delegate::Delegate(QObject * parent) :
    QStyledItemDelegate(parent)
{}

void Delegate::paint(QPainter * painter, const QStyleOptionViewItem & option,
                     const QModelIndex & index) const
{
    painter->save();

    QRect leftRect = QRect(option.rect.left(), option.rect.top(),
                           option.rect.width() / 2, option.rect.height());
    QBrush leftBrush = QBrush(Qt::red);
    painter->fillRect(leftRect, leftBrush);

    QRect rightRect = QRect(option.rect.left() + option.rect.width() / 2,
                            option.rect.top(), option.rect.width() / 2,
                            option.rect.height());
    QBrush rightBrush = QBrush(Qt::blue);
    painter->fillRect(rightRect, rightBrush);

    painter->restore();

    QStyleOptionViewItem adjustedOption(option);
    adjustedOption.backgroundBrush = QBrush(Qt::NoBrush);
    QStyledItemDelegate::paint(painter, adjustedOption, index);
}
