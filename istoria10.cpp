#include "istoria10.h"
#include "ui_istoria10.h"

Istoria10::Istoria10(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Istoria10)
{
    ui->setupUi(this);
}

Istoria10::~Istoria10()
{
    delete ui;
}
