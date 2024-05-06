#include "registrrab17.h"
#include "ui_registrrab17.h"
#include <QStringList>
RegistrRab17::RegistrRab17(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrRab17)
{
    ui->setupUi(this);

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
    QStringList registr;
    string filepath="C:\\kursach1\\rab.txt";
    QString fio = ui->lineEdit->text() + ' ' + ui->lineEdit_2->text() + ' ' +  ui->lineEdit_3->text();
    registr << fio << ui->lineEdit_4->text() << ui->lineEdit_5->text() << ui->lineEdit_6->text()<< ui->comboBox->currentText();
    txtWorker->writingToRab(filepath, registr);
    this->close();
}

