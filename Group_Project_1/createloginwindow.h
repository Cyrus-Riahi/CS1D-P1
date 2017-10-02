#ifndef CREATELOGINWINDOW_H
#define CREATELOGINWINDOW_H

#include <QMainWindow>

/*!
 * \namespace UI namespace for the Create Login Window Class
 */
namespace Ui {
class CreateLoginWindow;
}

/*! * \class CreateLoginWindow class*/
class CreateLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! * \fn CreateLoginWindow*/
    /*! * \param parent*/
    explicit CreateLoginWindow(QWidget *parent = 0);
    /*!
      *   \fn  Destructor
      * */
    ~CreateLoginWindow();

private slots:
    /*! * \fn on_pushButton_clicked*/
    void on_pushButton_clicked();

    void on_Enter_clicked();


    void on_Enter_pressed();

private:
    Ui::CreateLoginWindow *ui; /*! \var UI for the create login window*/
};

#endif // CREATELOGINWINDOW_H
