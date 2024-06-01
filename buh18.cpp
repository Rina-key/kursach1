#include "buh18.h"
#include "ui_buh18.h"

buh18::buh18(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buh18)
{
    ui->setupUi(this);
    buhz19 = new BuhZ19(this);
    buhinst21 = new BuhInst21(this);
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


void buh18::on_pushButton_clicked()
{
    buhz19 -> show();
    buhz19 -> updateTable();
}


void buh18::on_pushButton_2_clicked()
{
    buhinst21 -> show();
}

