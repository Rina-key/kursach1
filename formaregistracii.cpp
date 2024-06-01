#include "formaregistracii.h"
#include "ui_formaregistracii.h"
#include <QMessageBox>

formaRegistracii::formaRegistracii(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formaRegistracii)
{
    ui->setupUi(this);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
}

formaRegistracii::~formaRegistracii()
{
    delete ui;
}

void formaRegistracii::on_pushButton_2_clicked()
{
    this->close();
}


void formaRegistracii::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty() or ui->lineEdit_2->text().isEmpty()
            or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty()
            or ui->lineEdit_5->text().isEmpty() or ui->lineEdit_6->text().isEmpty()
            or ui->lineEdit_7->text().isEmpty() or ui->lineEdit_8->text().isEmpty()){
        QMessageBox::warning(this,"Ошибка","Проверьте пустые ячейки");
    } else{
        if (txtWorker->checkRegistr(ui->lineEdit_6->text())){
            if (ui->lineEdit_7->text() == ui->lineEdit_8->text()){
                QStringList registr;
                registr << ui->lineEdit->text() << ui->lineEdit_2->text() << ui->lineEdit_3->text() << ui->lineEdit_4->text() << ui->lineEdit_5->text() << ui->lineEdit_6->text() << ui->lineEdit_7->text() << ui->lineEdit_8->text() << "";
                txtWorker->registKlient(registr);
                this->close();
                QMessageBox::information(this, "Успешно", "Пользователь зарегистрирован.");
            }
            else {
                QMessageBox::warning(this, "Ошибка", "Пароли не совпадают.");
            }
        }
        else{
            QMessageBox::warning(this, "Ошибка", "Такой логин уже существует");
        }
    }
}
