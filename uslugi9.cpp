#include "uslugi9.h"
#include "ui_uslugi9.h"

Uslugi9::Uslugi9(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uslugi9)
{
    ui->setupUi(this);
}

Uslugi9::~Uslugi9()
{
    delete ui;
}
