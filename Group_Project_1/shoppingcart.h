#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>

namespace Ui {
class shoppingcart;
}

class shoppingcart : public QMainWindow
{
    Q_OBJECT

public:
    explicit shoppingcart(QWidget *parent = 0);
    ~shoppingcart();

    /*!
     * \fn setButtonSchool
     */
    void setButtonSchool(QString);

    /*!
     * \fn showNextSchoolButton
     */
    void showNextSchoolButton();

    /*!
     * \fn hideNextSchoolButton
     */
    void hideNextSchoolButton();

    /*!
     * \fn clearShoppingCart
     */
    void clearShoppingCart();

    /*!
     * \fn setShoppingCartTable
     */
    void setShoppingCartTable();

private slots:
    /*!
     * \fn on_addToCartPushButton_clicked
     */
    void on_addToCartPushButton_clicked();

    /*!
     * \fn on_toTheNextButton_clicked
     */
    void on_toTheNextButton_clicked();

    /*!
     * \fn on_deleteFromCartPushButton_clicked
     */
    void on_deleteFromCartPushButton_clicked();

    /*!
     * \fn on_checkoutButton_clicked
     */
    void on_checkoutButton_clicked();

private:
    /*!
     * \var ui
     */
    Ui::shoppingcart *ui;
};

#endif // SHOPPINGCART_H
