#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QVariant>
#include <QModelIndex>
#include <QStringList>

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent);
    ~MyModel();
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    QStringList myList;
signals:

public slots:
};

#endif // MYMODEL_H
