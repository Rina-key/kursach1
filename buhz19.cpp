#include "buhz19.h"
#include "ui_buhz19.h"

BuhZ19::BuhZ19(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuhZ19)
{
    ui->setupUi(this);
}

BuhZ19::~BuhZ19()
{
    delete ui;
}
