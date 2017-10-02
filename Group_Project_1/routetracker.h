#ifndef RECURSION_H
#define RECURSION_H

#include "database.h"

/*!
 * \fn routeTracker
 * \param schoolName
 * \param numOfSchoolsVisiting
 * \param totalMiles
 * \param collegesToVisit
 */
void routeTracker(QString schoolName,           // Name of school that gets passed in
                  int numOfSchoolsVisiting,     // Total number of schools visiting
                  int &totalMiles,              // Total mileage of the trip
                  QVector<college*> collegesToVisit);// Vector of schools we are visiting

#endif // RECURSION_H
