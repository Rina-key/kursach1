#include "adminzayavki15.h"
#include "ui_adminzayavki15.h"

AdminZayavki15::AdminZayavki15(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminZayavki15)
{
    ui->setupUi(this);
    this->setWindowTitle("Заявки");
}

AdminZayavki15::~AdminZayavki15()
{
    delete ui;
}

void AdminZayavki15::on_pushButton_2_clicked()
{
    this->close();
}

