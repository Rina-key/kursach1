#include "abonent.h"
#include "ui_abonent.h"

Abonent::Abonent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Abonent)
{
    ui->setupUi(this);
}

Abonent::~Abonent()
{
    delete ui;
}

void Abonent::on_pushButton_4_clicked()
{
    this->close();
    emit closed();
}

