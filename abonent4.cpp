#include "deistvieabonentaris4.h"
#include "ui_deistvieabonentaris4.h"

DeistvieAbonentaRis4::DeistvieAbonentaRis4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeistvieAbonentaRis4)
{
    ui->setupUi(this);
}

DeistvieAbonentaRis4::~DeistvieAbonentaRis4()
{
    delete ui;
}
