#pragma once

#include<QMainWindow>
#include "model.hpp"

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

    
        QWidget *leftWidget;
        QWidget *topWidget;
        QWidget *rightWidget;

        QuakeModel model;
        QGroupBox *gb1;
        QGroupBox *gb2;
        
        QTableView *table;
        QTableView *table2;

        QComboBox *cbBox_pollutant;
        QComboBox *cbBox_region;
        QComboBox *cbBox_date;
        QComboBox *cbBox_compliance;

        QPushButton *button_Load;
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



};

