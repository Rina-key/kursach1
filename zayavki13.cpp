#include "zayavki13.h"
#include "ui_zayavki13.h"

Zayavki13::Zayavki13(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zayavki13)
{
    ui->setupUi(this);
}

Zayavki13::~Zayavki13()
{
    delete ui;
}
