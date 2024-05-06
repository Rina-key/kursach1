#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);//HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

    adminzayavki15=new AdminZayavki15(this);
    registrrab17=new RegistrRab17(this);

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_3_clicked()
{
    this->close();
    emit closed();
}


void Admin::on_pushButton_clicked()
{
    adminzayavki15->show();
}


void Admin::on_pushButton_2_clicked()
{
    registrrab17->show();
}

