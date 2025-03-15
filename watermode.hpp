#pragma once

#include <QAbstractTableModel>
#include <QtSql>
#include <QTranslator>

class WaterModelMain: public QAbstractTableModel
{
    public: 
        WaterModelMain(QObject *parent = nullptr): QAbstractTableModel(parent), rowCountBuffer(0) {}
        void updateData(const QString&);
        bool hasData() const { return rowCountBuffer > 0; }

        int rowCount(const QModelIndex& index) const {return rowCountBuffer;}
        int columnCount(const QModelIndex& index) const { return 6; }

        QVariant data(const QModelIndex&, int) const;
        QVariant headerData(int, Qt::Orientation, int) const;
        
        


    private:
        mutable QSqlQuery waterquery;
        int rowCountBuffer;
};