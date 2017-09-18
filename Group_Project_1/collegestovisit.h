#ifndef COLLEGESTOVISIT_H
#define COLLEGESTOVISIT_H

#include <QString>
#include <QVector>


class college
{
public:
    // Default Constructor
    college(QString start, QString end, bool boolean, int num)
    {
        startingCollege = start; // Assigns the starting college
        endingCollege = end;     // Assigns the ending college
        visited = boolean;       // Assigns false to visited
        distance = num;          // Assigns the distance from starting college to ending college
    }

    // VARIABLE DECLARATION
    QString startingCollege;
    QString endingCollege;
    bool visited;
    int distance;
};

#endif // COLLEGESTOVISIT_H
