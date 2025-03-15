#pragma once

#include <QAbstractTableModel>
#include <QtSql>


class WaterModel: public QAbstractTableModel
{
    public: 
        WaterModel(QObject *parent = nullptr): QAbstractTableModel(parent), rowCountBuffer(0) {}
        void updateData(const QString&);
        bool hasData() const { return rowCountBuffer > 0; }

        int rowCount(const QModelIndex& index) const {return rowCountBuffer;}
        int columnCount(const QModelIndex& index) const { return 11; }

        QVariant data(const QModelIndex&, int) const;
        QVariant headerData(int, Qt::Orientation, int) const;
        
        


    private:
        mutable QSqlQuery waterquery;
        int rowCountBuffer;
};