#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

/*!
 *  \namespace Admin Window UI
 */
namespace Ui {
class adminWindow;
}

/*!
 * \class Admin Window Class
 */
class adminWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \fn Admin Window Constructor
     */
    explicit adminWindow(QWidget *parent = 0);
    /*!
     *  \fn Admin Window Destructor
     */
    ~adminWindow();

private slots:
    /*!
     * \fn on_backToLoginButton_clicked()
     *  Allows the user to go back to the login screen
     */
    void on_backToLoginButton_clicked();

private:
    Ui::adminWindow *ui; /*! \brief \var ui for admin window*/
};

#endif // ADMINWINDOW_H
