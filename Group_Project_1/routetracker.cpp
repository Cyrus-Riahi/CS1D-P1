#include "routetracker.h"

void routeTracker(QString schoolName,           // Name of school that gets passed in
                  int numOfSchoolsVisiting,     // Total number of schools visiting
                  int &totalMiles,              // Total mileage of the trip
                  QVector<college*> collegesToVisit){// Vector of schools we are visiting
    // Our database
    Database *DB = Database::getInstance();

    // Closest school in comparison to schoolName
    college* closestSchool = DB->getClosestSchool(schoolName, collegesToVisit);

    qDebug() << "From " << closestSchool->startingCollege << " to " << closestSchool->endingCollege << " is " << closestSchool->distance;

    QString closestSchoolName = closestSchool->endingCollege;
    // Base Case
    if(numOfSchoolsVisiting == 0)
    {
        return; // This will leave the program if out number of schools to visit is 0
                // and not return anything since the function is void
    } else
    {
        totalMiles += closestSchool->distance;

        // Calls the function again
        routeTracker(closestSchoolName, --numOfSchoolsVisiting, totalMiles, collegesToVisit);
    }
}
