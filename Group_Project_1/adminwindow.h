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

    /*!
     * \fn hideGroupBoxes
     */
    void hideGroupBoxes();

    /*!
     * \fn populateAddSouvenirCB
     */
    void populateAddSouvenirCB();

    /*!
     * \fn populateSchoolNameDeleteDB
     */
    void populateSchoolNameDeleteDB();

    /*!
     * \fn populateSchoolNameModifyCB
     */
    void populateSchoolNameModifyCB();

    /*!
     * \fn populateDeleteCollegeCB
     */
    void populateDeleteCollegeCB();

private slots:
    /*!
     * \fn on_backToLoginButton_clicked()
     *  Allows the user to go back to the login screen
     */
    void on_backToLoginButton_clicked();

    /*!
     * \fn on_addSouvenirButton_clicked
     */
    void on_addSouvenirButton_clicked();

    /*!
     * \fn on_deleteSouvenirButton_clicked
     */
    void on_deleteSouvenirButton_clicked();

    /*!
     * \fn on_modifySouvenirButton_clicked
     */
    void on_modifySouvenirButton_clicked();

    /*!
     * \fn on_schoolNameDeleteComboBox_currentTextChanged
     * \param arg1
     */
    void on_schoolNameDeleteComboBox_currentTextChanged(const QString &arg1);

    /*!
     * \fn on_schoolSouvenirComboBox_currentIndexChanged
     * \param arg1
     */
    void on_schoolSouvenirComboBox_currentIndexChanged(const QString &arg1);

    /*!
     * \fn on_cancelAddButton_clicked
     */
    void on_cancelAddButton_clicked();

    /*!
     * \fn on_cancelDeleteButton_clicked
     */
    void on_cancelDeleteButton_clicked();

    /*!
     * \fn on_cancelModifyButton_clicked
     */
    void on_cancelModifyButton_clicked();

    /*!
     * \fn on_modifySchoolNameComboBox_currentIndexChanged
     * \param arg1
     */
    void on_modifySchoolNameComboBox_currentIndexChanged(const QString &arg1);

    /*!
     * \fn on_modifySouvenirComboBox_currentIndexChanged
     * \param arg1
     */
    void on_modifySouvenirComboBox_currentIndexChanged(const QString &arg1);

    /*!
     * \fn on_addToDatabaseButton_clicked
     */
    void on_addToDatabaseButton_clicked();

    /*!
     * \fn on_deleteFromDatabaseButton_clicked
     */
    void on_deleteFromDatabaseButton_clicked();

    /*!
     * \fn on_modifyButton_clicked
     */
    void on_modifyButton_clicked();

    /*!
     * \fn on_deleteCollegeButton_clicked
     */
    void on_deleteCollegeButton_clicked();

    /*!
     * \fn on_AddFromFileButton_clicked
     */
    void on_AddFromFileButton_clicked();

    /*!
     * \fn on_deleteCollegeCancelButton_clicked
     */
    void on_deleteCollegeCancelButton_clicked();

    /*!
     * \fn on_addFromFileCancelButton_clicked
     */
    void on_addFromFileCancelButton_clicked();

    /*!
     * \fn on_addToDbFromFileButton_clicked
     */
    void on_addToDbFromFileButton_clicked();

    /*!
     * \fn on_deleteFromDbButton_clicked
     */
    void on_deleteFromDbButton_clicked();

private:
    Ui::adminWindow *ui; /*! \brief \var ui for admin window*/
};

#endif // ADMINWINDOW_H
