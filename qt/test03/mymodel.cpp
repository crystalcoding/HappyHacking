#include "mymodel.h"

MyModel::MyModel(QObject *parent): QAbstractListModel(parent)
{
    myList.append("1apple");
    myList.append("2orange");
    myList.append("3banana");
}

MyModel::~MyModel()
{

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role==Qt::DisplayRole) {
        return myList.at(index.column());
    }

    return QVariant();
}

