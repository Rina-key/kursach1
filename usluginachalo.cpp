#include "usluginachalo.h"
#include "ui_usluginachalo.h"

UslugiNachalo::UslugiNachalo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UslugiNachalo)
{
    ui->setupUi(this);
}

UslugiNachalo::~UslugiNachalo()
{
    delete ui;
}
//void UslugiNachalo::on_pushButton_2_clicked()
//{
//    this->close(); //HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//}
