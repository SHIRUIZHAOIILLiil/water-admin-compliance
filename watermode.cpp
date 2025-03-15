#include "watermode.hpp"


void WaterModelMain::updateData(const QString &q)
{
    beginResetModel();
    waterquery.exec(q);
    rowCountBuffer = 0;
    while (waterquery.next()) {
        ++rowCountBuffer;
    }
    waterquery.first();
    endResetModel();
}

QVariant WaterModelMain::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) 
    {
        return QVariant();
    }
    if (!waterquery.seek(index.row())) {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole) 
    {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0: return QVariant(waterquery.value(0).toString());
            case 1: return QVariant(waterquery.value(1).toString());
            case 2: return QVariant(waterquery.value(2).toString());
            case 3: return QVariant(waterquery.value(3).toString());
            case 4: return QVariant(waterquery.value(4).toString());
            case 5: return QVariant(waterquery.value(5).toString());
        }
        
    }
    else if (role == Qt::ForegroundRole)
    {
        bool compliance = waterquery.value(5).toBool();
        if (index.column() == 3 || index.column() == 5)
        {
            return compliance ? QColor(Qt::green) : QColor(Qt::red);
        }
    }

    return QVariant();
}

QVariant WaterModelMain::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Vertical)
    {
        return QVariant(section + 1);
    }

    switch (section)
    {
    case 0:
        return QString("Region");
    case 1:
        return QString("Time");
    case 2:
        return QString("Pollutant");
    case 3:
        return QString("Result");
    case 4:
        return QString("Unit"); 
    case 5:
        return QString("Compliance");
    default:
        return QVariant();
    }
}