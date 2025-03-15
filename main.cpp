#include <QApplication>
#include <QTranslator>
#include "mainwin.hpp"
#include "database.hpp"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    
    // QSqlQuery query;
    // query.exec("CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT)");
    // query.prepare("INSERT INTO person (id, name) VALUES (:id, :name)");
    // query.bindValue(":id", 1); // 手动指定id值
    // query.bindValue(":name", "John Doe");
    // query.exec();

    // WaterDataset wd;

    WaterDataset *wd = new WaterDataset("../Y-2024.csv");
    
    // WaterQuery *wq = new WaterQuery();
    // QString q = "SELECT * from waterdata WHERE result = 135;";
    // wq->setquery(q);
    // Water ww = (*wq)[0];
    // std::cout<< ww << std::endl;

    MainWin w;
    w.show();
    return a.exec();
}
