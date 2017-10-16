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

    void setButtonSchool(QString);

    void showNextSchoolButton();

    void hideNextSchoolButton();

private slots:
    void on_addToCartPushButton_clicked();

    void on_toTheNextButton_clicked();

    void on_deleteFromCartPushButton_clicked();

private:
    Ui::shoppingcart *ui;
};

#endif // SHOPPINGCART_H
