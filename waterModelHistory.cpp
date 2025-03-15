#include "waterModelHistory.hpp"

void::WaterModel::updateData(const QString& q){
    beginResetModel();
    waterquery.exec(q);
    rowCountBuffer = 0;
    while (waterquery.next()) {
        ++rowCountBuffer;
    }
    waterquery.first();
    endResetModel();
}


QVariant WaterModel::data(const QModelIndex& index, int role) const
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
            case 6: return QVariant(waterquery.value(6).toString());
            case 7: return QVariant(waterquery.value(7).toString());
            case 8: return QVariant(waterquery.value(8).toString());
            case 9: return QVariant(waterquery.value(9).toString());
            case 10: return QVariant(waterquery.value(10).toString());
        }
    }
    else if (role == Qt::ForegroundRole)
    {

        bool compliance = waterquery.value(8).toBool();
        if (index.column() == 4 || index.column() == 8)
        {
            return compliance ? QColor(Qt::green) : QColor(Qt::red);
        }
    }

    return QVariant();
}


QVariant WaterModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role != Qt::DisplayRole) {
    return QVariant();
  }

  if (orientation == Qt::Vertical) {
    return QVariant(section + 1);
  }

  switch (section) {
    case 0: return QString("Region");
    case 1: return QString("Time");
    case 2: return QString("Pollutant Name");
    case 3: return QString("ResultNotation");
    case 4: return QString("Result");
    case 5: return QString("Unit");
    case 6: return QString("SampleMaterial");
    case 7: return QString("Law");
    case 8: return QString("IsCompliance");
    case 9: return QString("Easting");
    case 10: return QString("Northing");
    default: return QVariant();
  }
}


