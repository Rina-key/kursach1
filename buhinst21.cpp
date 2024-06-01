#include "buhinst21.h"
#include "ui_buhinst21.h"

BuhInst21::BuhInst21(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuhInst21)
{
    ui->setupUi(this);
}

BuhInst21::~BuhInst21()
{
    delete ui;
}

void BuhInst21::on_pushButton_3_clicked()
{
    this->close();
}

