#include "operator11.h"
#include "ui_operator11.h"

Operator11::Operator11(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Operator11)
{
    ui->setupUi(this);
    zayavki12= new Zayavki12(this);
}

Operator11::~Operator11()
{
    delete ui;
}

void Operator11::on_pushButton_3_clicked()
{
    this->close();
    emit closed();
}


void Operator11::on_pushButton_clicked()
{
    zayavki12 -> updateTable();
    zayavki12 -> show();
}


