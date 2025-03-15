#include "mainwin.hpp"
#include <iostream>
#include <QtWidgets>



static const int MIN_WIDTH = 1200;
static const int MIN_LENGTH = 600;


MainWin::MainWin(QWidget *parent)
:QMainWindow(parent)
{
    createMainWidget();
    createButtons();
    createGroupBox();
    createTopWidget();
    createLeftWidget();
    createRightWidget();
    createCroupContainer();

    createLabel();
    createToolBar();
    

    setMinimumWidth(MIN_WIDTH);
    setMinimumHeight(MIN_LENGTH);
    setWindowTitle("Water Quality Application");

    QWidget *totalWidget = new QWidget(this);
    QVBoxLayout *totalLayout = new QVBoxLayout(totalWidget);

    QWidget *centralWidget = new QWidget(totalWidget);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    totalLayout->addWidget(topWidget);
    totalLayout->addWidget(centralWidget);
    totalLayout->addWidget(toolbar_footer);

    mainLayout->addWidget(leftWidget);
    //mainLayout->addWidget(table);
    mainLayout->addWidget(rightWidget);

    mainLayout->setStretchFactor(leftWidget, 1); 
    mainLayout->setStretchFactor(rightWidget, 2); 
    
    setCentralWidget(totalWidget);
    

}

void MainWin::createMainWidget(){
    table = new QTableView();
    table->setModel(&model);
    QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    table->setFont(tableFont);

    table2 = new QTableView();
    table2->setModel(&model);
    table2->setFont(tableFont);
}


void MainWin::createLeftWidget(){
    leftWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);
    leftLayout->addWidget(gb1);
    leftLayout->addWidget(gb2);
}

void MainWin::createTopWidget(){
    topWidget = new QWidget(this);
    QHBoxLayout *topLayout = new QHBoxLayout(topWidget);
    topLayout->addWidget(button_Page_DB);
    topLayout->addWidget(button_Page_PO);
    topLayout->addWidget(button_Page_POP);
    topLayout->addWidget(button_Page_ELIP);
    topLayout->addWidget(button_Page_FCP);
    topLayout->addWidget(button_Page_CD);
    topLayout->addWidget(button_Page_GHP);
}

void MainWin::createGroupBox()
{
    gb1 = new QGroupBox("gpb1");
    gb2 = new QGroupBox("gpb2");

    gb1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    gb2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

}

void MainWin::createCroupContainer(){
    cbBox_pollutant = new QComboBox();
    cbBox_date = new QComboBox();
    cbBox_region = new QComboBox();
    cbBox_compliance = new QComboBox();

    QStringList pollutant, date, region, compliance;
    pollutant << "Pollutant Category" << "Endrin"
              <<"PhenoxytcAcd"<< "MCPB" << "all";
    date << "hour" << "day" << "week" << "month";
    region <<"MALHAM TARN" << "SORREL SYKES FARM FREMINGTON 4465";
    compliance << "comp" <<"uncomp";
    cbBox_pollutant->addItems(pollutant);
    cbBox_date->addItems(date);
    cbBox_region->addItems(region);
    cbBox_compliance->addItems(compliance);

    cbBox_pollutant->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    cbBox_date->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    cbBox_region->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    cbBox_compliance->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    cbBox_region->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);

    QVBoxLayout *layout_gb1 = new QVBoxLayout(gb1);
    QVBoxLayout *layout_gb2 = new QVBoxLayout(gb2);
    layout_gb1->addWidget(cbBox_pollutant);
    layout_gb1->addWidget(cbBox_compliance);
    layout_gb2->addWidget(cbBox_date);
    layout_gb2->addWidget(cbBox_region);

    layout_gb2->addWidget(button_Load);

}

void MainWin::createButtons()
{
    button_Load = new QPushButton("Load");
    button_Page_DB = new QPushButton("Dash Board");
    button_Page_PO = new QPushButton("Overview");
    button_Page_POP = new QPushButton("POP");
    button_Page_ELIP = new QPushButton("ELIP");
    button_Page_FCP = new QPushButton("FCP");
    button_Page_CD = new QPushButton("CD");
    button_Page_GHP = new QPushButton("GHP");
}

void MainWin::createToolBar()
{
    toolbar_footer = new QToolBar();
    toolbar_footer->addWidget(label_guide);
    toolbar_footer->addSeparator();
    toolbar_footer->addWidget(label_data_resource);
    toolbar_footer->addSeparator();
    toolbar_footer->addWidget(label_help);
    toolbar_footer->addSeparator();
    toolbar_footer->addWidget(label_credit);

}

void MainWin::createLabel()
{
    label_guide = new QLabel("User Guide");
    label_data_resource = new QLabel("Data Resource");
    label_help = new QLabel("Help");
    label_credit = new QLabel("Credit");
}

void MainWin::createRightWidget(){
    rightWidget = new QWidget(this);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->addWidget(table);
    rightLayout->addWidget(table2);
}

MainWin::~MainWin(){

    delete gb1;
    delete gb2;
    delete leftWidget;
}