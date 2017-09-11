#ifndef COLLEGESTOVISIT_H
#define COLLEGESTOVISIT_H

#include <QString>
#include <QVector>


class college
{
public:
    college(QString start, QString end, bool boolean, int num)
    {
        startingCollege = start;
        endingCollege = end;
        visited = boolean;
        distance = num;
    }
    QString startingCollege;
    QString endingCollege;
    bool visited;
    int distance;
};

#endif // COLLEGESTOVISIT_H
