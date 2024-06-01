#include "uslugiris7.h"
#include "ui_uslugiris7.h"
#include "uslovia8.h"
#include <QMessageBox>

UslugiRis7::UslugiRis7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UslugiRis7)
{
    ui->setupUi(this);
    uslovia8 = new Uslovia8();
    uslugi9 = new Uslugi9(this);
//    connect(UslugiRis7, &UslugiRis7::on_pushButton_2_clicked, this, &UslugiRis7:: on_pushButton_2_clicked);
//    connect(abonent, &Abonent::closed, this, [this]() { returnToMain(ui->centralwidget); });
}

UslugiRis7::~UslugiRis7()
{
    delete ui;
}

void UslugiRis7::on_pushButton_3_clicked()
{
    this->close();
}


void UslugiRis7::on_pushButton_clicked()
{
    uslovia8-> show();
}


void UslugiRis7::on_pushButton_2_clicked()
{
    txtWorker -> addToZayavki(currentAbonent);
    this->close();
    uslugi9->show();
}

