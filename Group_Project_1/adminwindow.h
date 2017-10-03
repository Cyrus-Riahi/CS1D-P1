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

    void hideGroupBoxes();

    void populateAddSouvenirCB();

    void populateSchoolNameDeleteDB();

    void populateSchoolNameModifyCB();


private slots:
    /*!
     * \fn on_backToLoginButton_clicked()
     *  Allows the user to go back to the login screen
     */
    void on_backToLoginButton_clicked();

    void on_backToLoginButton_2_clicked();

    void on_addSouvenirButton_clicked();

    void on_deleteSouvenirButton_clicked();

    void on_modifySouvenirButton_clicked();

    void on_schoolNameDeleteComboBox_currentTextChanged(const QString &arg1);

    void on_schoolSouvenirComboBox_currentIndexChanged(const QString &arg1);

    void on_cancelAddButton_clicked();

    void on_cancelDeleteButton_clicked();

    void on_cancelModifyButton_clicked();

    void on_modifySchoolNameComboBox_currentIndexChanged(const QString &arg1);

    void on_modifySouvenirComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::adminWindow *ui; /*! \brief \var ui for admin window*/
};

#endif // ADMINWINDOW_H
