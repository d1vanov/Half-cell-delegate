#include "Model.h"

Model::Model(QObject * parent) :
    QAbstractTableModel(parent),
    m_columnNames(QStringList() << "First" << "Second" << "Third" << "Fourth"),
    m_data()
{
    m_data.resize(10);
    int numColumns = m_columnNames.size();
    for(int i = 0, numRows = m_data.size(); i < numRows; ++i)
    {
        QVector<QString> & rowData = m_data[i];
        rowData.resize(numColumns);
        for(int j = 0; j < numColumns; ++j) {
            rowData[j] = generateRandomString(6);
        }
    }
}

int Model::rowCount(const QModelIndex & parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

int Model::columnCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent)
    return m_columnNames.size();
}

QVariant Model::data(const QModelIndex & index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    int row = index.row();
    if (row < 0 || row >= m_data.size()) {
        return QVariant();
    }

    int column = index.column();
    if (column < 0 || column >= m_columnNames.size()) {
        return QVariant();
    }

    return m_data[row][column];
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation != Qt::Horizontal) {
        return QVariant();
    }

    if (section < 0 || section >= m_columnNames.size()) {
        return QVariant();
    }

    return m_columnNames[section];
}

QString Model::generateRandomString(const int len) const
{
    QString string;
    string.resize(len);

    for(int i = 0; i < len; ++i)
    {
        int randomChar = rand()%(26+26+10);
        if (randomChar < 26) {
            string[i] = 'a' + randomChar;
        }
        else if (randomChar < 26+26) {
            string[i] = 'A' + randomChar - 26;
        }
        else {
            string[i] = '0' + randomChar - 26 - 26;
        }
    }

    return string.toUpper();
}


