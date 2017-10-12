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

private:
    Ui::shoppingcart *ui;
};

#endif // SHOPPINGCART_H
