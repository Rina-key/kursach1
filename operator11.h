#ifndef OPERATOR11_H
#define OPERATOR11_H

#include <QDialog>
#include "zayavki12.h"

namespace Ui {
class Operator11;
}

class Operator11 : public QDialog
{
    Q_OBJECT

public:
    explicit Operator11(QWidget *parent = nullptr);
    ~Operator11();
signals:
    void closed();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Operator11 *ui;
    Zayavki12* zayavki12;
};

#endif // OPERATOR11_H
