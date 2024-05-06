#include "formaregistracii.h"
#include "ui_formaregistracii.h"

formaRegistracii::formaRegistracii(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formaRegistracii)
{
    ui->setupUi(this);
}

formaRegistracii::~formaRegistracii()
{
    delete ui;
}

void formaRegistracii::on_pushButton_2_clicked()
{
    this->close(); //HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
}

