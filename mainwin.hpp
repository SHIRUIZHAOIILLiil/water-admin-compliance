#pragma once

#include<QMainWindow>
#include <QtWidgets>
#include <QTranslator>
#include "waterModelHistory.hpp"
#include "customdialog.hpp"
#include "watermode.hpp"

class QString;
class QComboBox;
class QLabel;
class QPushButton;
class QTableView;
class StatsDialog;
class QGroupBox;
class QWidget;
class QToolBar;






class MainWin:public QMainWindow{
    Q_OBJECT
    public:
        MainWin(QWidget * parent = nullptr);
        ~MainWin();
    
    private:
        void createMainWidget();
        // void createFileSelectors();
        void createButtons();
        void createToolBar();
        // void createStatusBar();
        // void addFileMenu();
        // void addHelpMenu();
        void createGroupBox();
        void createLeftWidget();
        void createCroupContainer();
        void createLabel();
        void createTopWidget();
        void createRightWidget();
        void processDateCompliance(std::string &, std::string &);
        void generateSqlQuery(const std::string &, 
                                 const std::string &, 
                                 const std::string &, 
                                 QString &);
        void addOrderBy(QString &);
        void updateTranslations();


        QVBoxLayout *rightLayout;
    
        QWidget *leftWidget;
        QWidget *topWidget;
        QWidget *rightWidget;

        WaterModel model;
        WaterModel modelHistory;
        WaterModelMain modeltest;
        QGroupBox *gb1;
        QGroupBox *gb2;

        QGroupBox *gbCommonPollutant;
        QGroupBox *gbPOPs;
        QGroupBox *gbPhysicalPolluant;
        QGroupBox *gbFluorinatedCompounds;
        
        QTableView *table;
        //QTableView *table2;

        QComboBox *cbBox_pollutant;
        QComboBox *cbBox_region;
        QComboBox *cbBox_date;
        QComboBox *cbBox_compliance;

        QPushButton *button_Load;
        QPushButton *button_moreInformation;
        QPushButton *button_Page_DB;
        QPushButton *button_Page_PO;
        QPushButton *button_Page_POP;
        QPushButton *button_Page_ELIP;
        QPushButton *button_Page_FCP;
        QPushButton *button_Page_CD;
        QPushButton *button_Page_GHP;

        QToolBar *toolbar_footer;

        QLabel *label_guide;
        QLabel *label_data_resource;
        QLabel *label_help;
        QLabel *label_credit;
        QLabel *label_pollutant;
        QLabel *label_region;
        QLabel *label_date;
        QLabel *label_compliance;
        CustomDialog customdialog;

        QSqlQuery qsqlq;

        QTranslator translator;

    private slots:
        void updateNewData();
        void getMoreInformation();

};



