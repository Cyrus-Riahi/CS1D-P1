#ifndef RECURSION_H
#define RECURSION_H

#include "database.h"


void routeTracker(QString schoolName,           // Name of school that gets passed in
                  int numOfSchoolsVisiting,     // Total number of schools visiting
                  int & totalMiles,              // Total mileage of the trip
                  QVector<college*> collegesToVisit);// Vector of schools we are visiting

#endif // RECURSION_H
