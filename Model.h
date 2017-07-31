#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>

class Model: public QAbstractTableModel
{
public:
    Model(QObject * parent = 0);

    virtual int rowCount(const QModelIndex & parent) const;
    virtual int columnCount(const QModelIndex & parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QString generateRandomString(const int len) const;

private:
    QStringList                 m_columnNames;
    QVector<QVector<QString> >  m_data;
};

#endif // MODEL_H
