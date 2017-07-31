#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>

class Delegate: public QStyledItemDelegate
{
public:
    Delegate(QObject * parent = 0);

    virtual void paint(QPainter * painter,
                       const QStyleOptionViewItem & option,
                       const QModelIndex & index) const;
};

#endif // DELEGATE_H
