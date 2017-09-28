#ifndef COLLEGESTOVISIT_H
#define COLLEGESTOVISIT_H

#include <QString>
#include <QVector>

/*!
 * \class College Class
 */
class college
{
public:
    /*!    \fn Default Constructor*/
    /*!     * \fn college*/
    /*!     * \param start*/
    /*!     * \param end*/
    /*!     * \param boolean*/
    /*!     * \param int num*/
    college(QString start, QString end, bool boolean, int num)
    {
        startingCollege = start; /*! \brief Assigns the starting college*/
        endingCollege = end;     /*! \brief Assigns the ending college*/
        visited = boolean;       /*! \brief Assigns false to visited*/
        distance = num;          /*! \brief Assigns the distance from starting college to ending college*/
    }

    // VARIABLE DECLARATION
    QString startingCollege;//! \var QString of our starting college
    QString endingCollege;  //! \var QString of our ending college
    bool visited;           //! \var bool of whether the school has been visited
    int distance;           //! \var int of the distance between colleges
};

#endif // COLLEGESTOVISIT_H
