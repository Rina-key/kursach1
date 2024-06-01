#include "parol6.h"
#include "ui_parol6.h"
#include <QMessageBox>

Parol6::Parol6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parol6)
{
    ui->setupUi(this);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}

Parol6::~Parol6()
{
    delete ui;
}

void Parol6::on_pushButton_2_clicked()
{
    this->close();
}


void Parol6::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty() or ui->lineEdit_2->text().isEmpty()
            or ui->lineEdit_3->text().isEmpty()){
        QMessageBox::warning(this,"Ошибка","Проверьте пустые ячейки");
    }
    else{
        if (ui->lineEdit_2->text() == ui->lineEdit_3->text() and ui->lineEdit->text() == currentAbonent[7]){
            //Cравниваем пароли текущий с файлом и новый с подтверждением
            txtWorker -> changePassword(currentAbonent[6], ui->lineEdit_2->text());
            QMessageBox::information(this, "Успех", "Пароль изменен");
            this->close();
        }
        else{
            QMessageBox::warning(this, "Ошибка", "Проверьте данные");
        }
    }
}
