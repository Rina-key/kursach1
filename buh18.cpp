#include "buh18.h"
#include "ui_buh18.h"

buh18::buh18(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buh18)
{
    ui->setupUi(this);
}

buh18::~buh18()
{
    delete ui;
}

void buh18::on_pushButton_3_clicked()
{
    this->close();
    emit closed();
}

