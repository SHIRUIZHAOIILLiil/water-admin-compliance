#include "customdialog.hpp"

    CustomDialog::CustomDialog(QWidget *parent) : QDialog(parent) {
        okButton = new QPushButton("OK", this);
        layout = new QVBoxLayout(this);
        
        table = new QTableView();
        table->setModel(&watermodel);

        layout->addWidget(table);
        layout->addWidget(okButton);
        
        connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
        
    }