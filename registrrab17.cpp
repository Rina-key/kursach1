#include "registrrab17.h"
#include "qmessagebox.h"
#include "ui_registrrab17.h"
#include <QStringList>

#include <QRegularExpression>
#include <QRegularExpressionValidator>

RegistrRab17::RegistrRab17(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrRab17)
{
    ui->setupUi(this);

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->comboBox->setCurrentText("");

    ui->lineEdit_5->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-zA-Z]{25}"))); // login HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

}

RegistrRab17::~RegistrRab17()
{
    delete ui;
}

void RegistrRab17::on_pushButton_2_clicked()
{
    this->close();
}


void RegistrRab17::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty() or ui->lineEdit_2->text().isEmpty()
            or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty()
            or ui->lineEdit_5->text().isEmpty() or ui->lineEdit_6->text().isEmpty()
            or ui->comboBox->currentText()==""){
        QMessageBox::warning(this,"Ошибка","Проверьте пустые ячейки");
    } else{
        if (txtWorker->checkRegistrRab(ui->lineEdit_5->text())){
            QStringList registr;
            QString fio = ui->lineEdit->text() + ' ' + ui->lineEdit_2->text() + ' ' +  ui->lineEdit_3->text();
            registr << fio << ui->lineEdit_4->text() << ui->lineEdit_5->text() << ui->lineEdit_6->text()<< ui->comboBox->currentText();
            txtWorker->writingToRab(registr);
            this->close();
        } else {
            QMessageBox::warning(this, "Ошибка", "Используйте другой логин");
        }
    }
}

