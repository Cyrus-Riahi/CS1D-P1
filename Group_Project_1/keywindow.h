#ifndef KEYWINDOW_H
#define KEYWINDOW_H

#include <QMainWindow>

namespace Ui {
class keyWindow;
}

class keyWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \fn keyWindow
     * \param parent
     */
    explicit keyWindow(QWidget *parent = 0);

    /*! \fn ~keyWindow*/
    ~keyWindow();

private:
    Ui::keyWindow *ui;      /*! \var ui*/
    int numOfSchools;       /*! \var numOfSchools*/
};

#endif // KEYWINDOW_H
