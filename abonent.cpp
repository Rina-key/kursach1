#include "abonent.h"
#include "ui_abonent.h"

Abonent::Abonent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Abonent)
{
    ui->setupUi(this);
    istoria10 = new Istoria10();
    uslugiris7 = new UslugiRis7();
    profile5 = new Profile5();
    connect(profile5, &Profile5::closedForSaving, this, &Abonent:: closed); //закрываем, чтобы данные обновились и человек
    //перезашел с новыми данными

}

Abonent::~Abonent()
{
    delete ui;
}

void Abonent::on_pushButton_4_clicked()
{
    this->close();
    emit closed();
}


void Abonent::on_pushButton_3_clicked()
{
    istoria10 -> currentAbonent = currentAbonent; //передаем информацию о текущем клиенте, чей сеанс
    istoria10 -> updateTable();
    istoria10 -> show();
}


void Abonent::on_pushButton_2_clicked()
{
    uslugiris7 -> currentAbonent = currentAbonent; //передаем информацию о текущем клиенте, чей сеанс
    uslugiris7->show();
}


void Abonent::on_pushButton_clicked()
{
    profile5 -> currentAbonent = currentAbonent; //передаем информацию о текущем клиенте, чей сеанс
    profile5 -> updateLines(); //обновляем записи в ячейках
    profile5 -> show();
}

