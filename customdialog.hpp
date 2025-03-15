#pragma once

#include "waterModelHistory.hpp"
#include <QtWidgets>


class CustomDialog : public QDialog {
public:
    QTableView *table;
    WaterModel watermodel;
    CustomDialog(QWidget *parent = nullptr);
private:
    QPushButton *okButton;
    QVBoxLayout *layout;
};