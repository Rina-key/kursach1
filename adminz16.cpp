#include "adminz16.h"
#include "ui_adminz16.h"

AdminZ16::AdminZ16(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminZ16)
{
    ui->setupUi(this);
}

AdminZ16::~AdminZ16()
{
    delete ui;
}
