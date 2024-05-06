#include "zayavki12.h"
#include "ui_zayavki12.h"

Zayavki12::Zayavki12(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zayavki12)
{
    ui->setupUi(this);
}

Zayavki12::~Zayavki12()
{
    delete ui;
}
