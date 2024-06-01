#include "usluginachalo.h"
#include "ui_usluginachalo.h"
#include "uslovia8.h"

UslugiNachalo::UslugiNachalo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UslugiNachalo)
{
    ui->setupUi(this);
    uslovia8 = new Uslovia8();
    this->setWindowTitle("Услуги");
}

UslugiNachalo::~UslugiNachalo()
{
    delete ui;
}

void UslugiNachalo::on_pushButton_3_clicked()
{
    this->close();
}


void UslugiNachalo::on_pushButton_clicked()
{
    uslovia8 -> show();
}

