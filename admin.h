#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "adminzayavki15.h"
#include "registrrab17.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
signals:
    void adminWindow();
    void closed();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Admin *ui;
    AdminZayavki15* adminzayavki15;
    RegistrRab17* registrrab17;
};

#endif // ADMIN_H
