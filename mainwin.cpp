#include "mainwin.hpp"
#include <iostream>


static const int MIN_WIDTH = 1200;
static const int MIN_LENGTH = 600;

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
{
    createMainWidget();
    createLabel();
    createButtons();
    createGroupBox();
    createTopWidget();
    createLeftWidget();
    createRightWidget();
    createCroupContainer();

    createToolBar();

    setMinimumWidth(MIN_WIDTH);
    setMinimumHeight(MIN_LENGTH);
    setWindowTitle(tr("Water Quality Application"));

    QWidget *totalWidget = new QWidget(this);
    QVBoxLayout *totalLayout = new QVBoxLayout(totalWidget);

    QWidget *centralWidget = new QWidget(totalWidget);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    totalLayout->addWidget(topWidget);
    totalLayout->addWidget(centralWidget);
    totalLayout->addWidget(toolbar_footer);

    mainLayout->addWidget(leftWidget);
    // mainLayout->addWidget(table);
    mainLayout->addWidget(rightWidget);

    mainLayout->setStretchFactor(leftWidget, 1);
    mainLayout->setStretchFactor(rightWidget, 3);

    setCentralWidget(totalWidget);

    customdialog.resize(1000, 500);
}

void MainWin::createMainWidget()
{
    table = new QTableView();
    //table2 = new QTableView();
    QString q = ("SELECT sample_samplingPoint_label, sample_sampleDateTime,"
                "determinand_definition, result,determinand_unit_label,"
                "sample_isComplianceSample FROM waterdata WHERE sample_isComplianceSample = 'true' ORDER BY "
                "sample_samplingPoint_label, sample_sampleDateTime;");
    QFont tableFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    modeltest.updateData(q);

    table->setModel(&modeltest);
    table->resizeColumnsToContents();


    
    table->setFont(tableFont);

    // table2->setModel(&model);
    // table2->resizeColumnsToContents();
    // table2->setFont(tableFont);
}

void MainWin::createLeftWidget()
{
    leftWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);
    leftLayout->addWidget(gb1);
    leftLayout->addWidget(gb2);
}

void MainWin::createTopWidget()
{
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
    gb1 = new QGroupBox("");
    gb2 = new QGroupBox("");
    gbCommonPollutant = new QGroupBox("");
    gbPOPs = new QGroupBox("");
    gbPhysicalPolluant = new QGroupBox("");
    gbFluorinatedCompounds = new QGroupBox("");

    gb1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    gb2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

void MainWin::createCroupContainer()
{
    cbBox_pollutant = new QComboBox();
    cbBox_date = new QComboBox();
    cbBox_region = new QComboBox();
    cbBox_compliance = new QComboBox();

    QStringList pollutant, date, region, compliance;
    QString selectPollutant = "SELECT DISTINCT determinand_definition from waterdata ORDER BY determinand_label; ";
    QString selectRegion = "SELECT DISTINCT sample_samplingPoint_label from waterdata ORDER BY sample_samplingPoint_label;";

    pollutant << "ALL";
    region << "ALL";

    qsqlq.exec(selectPollutant);
    while (qsqlq.next())
    {
        pollutant << qsqlq.value("determinand_definition").toString();
    }

    date << "ALL" << "January" << "Febuary" << "March" << "April" << "May"
         << "June" << "July" << "August" << "September" << "October"
         << "November" << "December";
    qsqlq.exec(selectRegion);
    while (qsqlq.next())
    {
        region << qsqlq.value("sample_samplingPoint_label").toString();
    }
    compliance << "Compliance" << "Non-Compliance" << "ALL";
    cbBox_pollutant->addItems(pollutant);
    cbBox_date->addItems(date);
    cbBox_region->addItems(region);
    cbBox_compliance->addItems(compliance);

    cbBox_pollutant->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    cbBox_date->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    cbBox_region->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    cbBox_compliance->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    cbBox_region->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
    cbBox_pollutant->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);

    QVBoxLayout *layout_gb1 = new QVBoxLayout(gb1);
    QVBoxLayout *layout_gb2 = new QVBoxLayout(gb2);
    layout_gb1->addWidget(label_pollutant);
    layout_gb1->addWidget(cbBox_pollutant);
    layout_gb1->addWidget(label_compliance);
    layout_gb1->addWidget(cbBox_compliance);

    layout_gb1->addWidget(button_moreInformation);

    layout_gb2->addWidget(label_date);
    layout_gb2->addWidget(cbBox_date);
    layout_gb2->addWidget(label_region);
    layout_gb2->addWidget(cbBox_region);

    layout_gb2->addWidget(button_Load);
}

void MainWin::createButtons()
{
    button_Load = new QPushButton(tr("Load"));
    button_moreInformation = new QPushButton(tr("More Information"));
    button_Page_DB = new QPushButton(tr("Dash Board"));
    button_Page_PO = new QPushButton("Overview");
    button_Page_POP = new QPushButton("POP");
    button_Page_ELIP = new QPushButton("ELIP");
    button_Page_FCP = new QPushButton("FCP");
    button_Page_CD = new QPushButton("CD");
    button_Page_GHP = new QPushButton("GHP");

    connect(button_Load, SIGNAL(clicked()), this, SLOT(updateNewData()));
    connect(button_moreInformation, SIGNAL(clicked()), this, SLOT(getMoreInformation()));
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

    label_pollutant = new QLabel("Pollutant Category");
    label_compliance = new QLabel("Compliance");
    label_date = new QLabel("Date");
    label_region = new QLabel("Region");
}

void MainWin::createRightWidget()
{
    rightWidget = new QWidget(this);
    rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->addWidget(table);
}

void MainWin::updateNewData()
{
    std::string pollutantName = cbBox_pollutant->currentText().toStdString();
    std::string regionName = cbBox_region->currentText().toStdString();
    std::string date = cbBox_date->currentText().toStdString();
    std::string isCompliance = cbBox_compliance->currentText().toStdString();

    processDateCompliance(date, isCompliance);

    QString sqlUpdate = ("select sample_samplingPoint_label, sample_sampleDateTime, "
                         "determinand_definition, result, determinand_unit_label, sample_isComplianceSample "
                         "FROM waterdata WHERE 1=1");
    generateSqlQuery(pollutantName, regionName, isCompliance, sqlUpdate);

    if (date != "ALL")
    {
        sqlUpdate +=  " AND strftime('%m', sample_sampleDateTime) = '" + QString::fromStdString(date) + "'";
    }
    addOrderBy(sqlUpdate);

    // std::cout << sqlUpdate.toStdString() << std::endl;
    modeltest.updateData(sqlUpdate);

    table->setModel(&modeltest);
}

void MainWin::getMoreInformation(){
    std::string pollutantName = cbBox_pollutant->currentText().toStdString();
    std::string regionName = cbBox_region->currentText().toStdString();
    std::string date = cbBox_date->currentText().toStdString();
    std::string isCompliance = cbBox_compliance->currentText().toStdString();

    processDateCompliance(date, isCompliance);

    QString sqlMoreInfo = "SELECT sample_samplingPoint_label, "
                            "sample_sampleDateTime, determinand_definition, "
                            "resultQualifier_notation, result, "
                            "determinand_unit_label, sample_sampledMaterialType_label, "
                            "sample_isComplianceSample, sample_purpose_label, "
                            "sample_samplingPoint_easting, sample_samplingPoint_northing "
                            "FROM waterdata WHERE 1=1 ";

    generateSqlQuery(pollutantName, regionName, isCompliance, sqlMoreInfo);
    addOrderBy(sqlMoreInfo);

    customdialog.watermodel.updateData(sqlMoreInfo);
    customdialog.table->setModel(&customdialog.watermodel);
    customdialog.table->resizeColumnsToContents();
    //customdialog.adjustSize(); 
    customdialog.exec();
}


void MainWin::processDateCompliance(std::string &date, std::string &isCompliance){
    if (isCompliance == "Non-Compliance")
        isCompliance = "false";
    if (isCompliance == "Compliance")
        isCompliance = "true";
    if (date == "January")
        date = "01";
    else if (date == "Febuary")
        date = "02";
    else if (date == "March")
        date = "03";
    else if (date == "April")
        date = "04";
    else if (date == "May")
        date = "05";
    else if (date == "June")
        date = "06";
    else if (date == "July")
        date = "07";
    else if (date == "August")
        date = "08";
    else if (date == "September")
        date = "09";
    else if (date == "October")
        date = "10";
    else if (date == "November")
        date = "11";
    else if (date == "December")
        date = "12";

}

void MainWin::generateSqlQuery(const std::string &p, const std::string &r, const std::string &c, QString &q)
{
    if (p != "ALL")
    {q += " AND determinand_definition = '" + QString::fromStdString(p) + "'";}
    if (r != "ALL")
    {q += " AND sample_samplingPoint_label = '" + QString::fromStdString(r) + "'";}
    if (c != "ALL")
    {q += " AND sample_isComplianceSample = '" + QString::fromStdString(c) + "'";}
}

void MainWin::addOrderBy(QString &q){
    q += " ORDER BY sample_samplingPoint_label, sample_sampleDateTime";
}


MainWin::~MainWin()
{

    delete gb1;
    delete gb2;
    delete leftWidget;
}