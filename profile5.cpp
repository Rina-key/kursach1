#include "profile5.h"
#include "ui_profile5.h"

ProfileRis5::ProfileRis5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfileRis5)
{
    ui->setupUi(this);
}

ProfileRis5::~ProfileRis5()
{
    delete ui;
}
