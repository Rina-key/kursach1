#include "uslovia8.h"
#include "ui_uslovia8.h"

Uslovia8::Uslovia8(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uslovia8)
{
    ui->setupUi(this);
}

Uslovia8::~Uslovia8()
{
    delete ui;
}

void Uslovia8::on_pushButton_3_clicked()
{
    this->close();
}

