Firstly, connect to the database. I have commented the function(called connect in waterquery). Just connect once it will work successfully.
Remember add the library.

database.cpp and database.hpp are in the folder called compliance dashboard page.
They are using to convert the .csv file to the .db file
In this part, the connection to the database has been established.

this is an example.

    WaterDataset *wd = new WaterDataset("../Y-2024.csv");
    WaterQuery *wq = new WaterQuery();
    QString q = "SELECT * from waterdata WHERE result = 135;";
    wq->setquery(q);
    Water ww = (*wq)[0];
    std::cout<< ww << std::endl;
