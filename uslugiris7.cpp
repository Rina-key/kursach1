#include "uslugiris7.h"
#include "ui_uslugiris7.h"

UslugiRis7::UslugiRis7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UslugiRis7)
{
    ui->setupUi(this);
}

UslugiRis7::~UslugiRis7()
{
    delete ui;
}
