#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    QVector<college*> collegesToVisit;
    QSqlQuery query;
    query.prepare("PRAGMA foreign_keys = ON");


    if (query.exec("SELECT * FROM College_Campus_Distances"))
    {
        while(query.next())
        {
            collegesToVisit.push_back(new college(query.value(0).toString(), query.value(1).toString(), false, query.value(2).toInt()));
        }
    }

    int totalMiles = 0;
//    routeTracker("University of the Pacific", 10, totalMiles, collegesToVisit);

    return a.exec();
}
