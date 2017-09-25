#include "windowHolder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    windowHolder* WH = windowHolder::getInstance();

    WH->LoginWindowShow();


//    loginWindow l;
//    l.show();

//    MainWindow w;
//    w.hide();
//    if(!l.isAdmin())
//    {
//        l.hide();
//        w.show();
//    }




    //    QVector<college*> collegesToVisit;
    //    QSqlQuery query;
    //    query.prepare("PRAGMA foreign_keys = ON");


    //    if (query.exec("SELECT * FROM College_Campus_Distances"))
    //    {
    //        while(query.next())
    //        {
    //            collegesToVisit.push_back(new college(query.value(0).toString(), query.value(1).toString(), false, query.value(2).toInt()));
    //        }
    //    }

    //    int totalMiles;
    //    totalMiles= 0;
    //    QString testString = "Saddleback College";
    //    int numOfTrips = 10;
    //    routeTracker(testString, numOfTrips, totalMiles, collegesToVisit);

    return a.exec();
}
