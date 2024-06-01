#include "profile5.h"
#include "qmessagebox.h"
#include "ui_profile5.h"

Profile5::Profile5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile5)
{
    ui->setupUi(this);
    parol6 = new Parol6(this);
}

Profile5::~Profile5()
{
    delete ui;
}

void Profile5::on_pushButton_3_clicked()
{
    this -> close();
}


void Profile5::on_pushButton_2_clicked()
{
    parol6->currentAbonent=currentAbonent; //передаем данные о текущем пользователе
    parol6 -> show();
}


void Profile5::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty() or ui->lineEdit_2->text().isEmpty()
            or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty()
            or ui->lineEdit_5->text().isEmpty() or ui->lineEdit_6->text().isEmpty()){
        QMessageBox::warning(this,"Ошибка","Проверьте пустые ячейки");
    } else{
        txtWorker->changeClient(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text(),ui->lineEdit_5->text(),ui->lineEdit_6->text(), currentAbonent[6]);
        this->close();
        QMessageBox::information(this, "Успех", "Данные изменены");
        currentAbonent = txtWorker->updateAbonent(currentAbonent[6]);
        updateLines();
        emit closedForSaving();
    }
}

void Profile5::updateLines(){
    ui->lineEdit->setText(currentAbonent[0]); //заполняем ячейки в профиле
    ui->lineEdit_2->setText(currentAbonent[1]);
    ui->lineEdit_3->setText(currentAbonent[2]);
    ui->lineEdit_4->setText(currentAbonent[3]);
    ui->lineEdit_5->setText(currentAbonent[4]);
    ui->lineEdit_6->setText(currentAbonent[5]);
}
