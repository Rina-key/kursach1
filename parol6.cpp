#include "parol6.h"
#include "ui_parol6.h"

ParolRis6::ParolRis6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParolRis6)
{
    ui->setupUi(this);
}

ParolRis6::~ParolRis6()
{
    delete ui;
}
