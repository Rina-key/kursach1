#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abonent.h"
#include "admin.h"
#include "usluginachalo.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QStringList>
using namespace std;
MainWindow::MainWindow(QWidget *parent) //экземпляр класса (мнтод, атрибут), а сам класс в заголовке
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//автоматически, чтобы использовалась форма

    stackedWidget = new QStackedWidget(this);// окна в окна
    returnToMain(ui->centralwidget);
    abonent=new Abonent();

    formaregistracii=new formaRegistracii(); //HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

    admin=new Admin();
    operator11=new Operator11();
    buH18 = new buh18();
    usluginachalo = new UslugiNachalo();
    connect(admin, &Admin:: adminWindow, this, &MainWindow:: show);//соединение сигнала и метода

//    connect(admin,&Admin::closed, this, MainWindow::returnToMain(ui->centralwidget));
//    connect(abonent,&Abonent::closed, this, MainWindow::returnToMain(ui->centralwidget));
    connect(admin, &Admin::closed, this, [this]() { returnToMain(ui->centralwidget);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");}); //Лямбда функция - это без названия, для чего? УДОБНАЯ ФУНКЦИЯ!!! Данные в коробочке
    connect(abonent, &Abonent::closed, this, [this]() { returnToMain(ui->centralwidget);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");});
    connect(buH18, &buh18::closed, this, [this]() { returnToMain(ui->centralwidget);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");});
    connect(operator11, &Operator11::closed, this, [this]() { returnToMain(ui->centralwidget);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");});

//    usluginachalo=new UslugiNachalo();
}

MainWindow::~MainWindow() //диструктор
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // ВХОД
{
    QString login;
    QString password;
    login = ui->lineEdit->text();// взяли со строчек в форме //метод //QString это класс и вызываем его метод
    password = ui->lineEdit_2->text();

    if(ui->radioButtonRab->isChecked()) {
        this->setWindowTitle("Работник");

        try {
            auto strRole = txtWorker->getRoleByLoginAndPass(login, password);

            if (strRole =="Admin")
                returnToMain(admin);
            if (strRole =="Operator")
                returnToMain(operator11);
            if (strRole =="Buhgalter")
                returnToMain(buH18);

        } catch (const NotFound&) {
            QMessageBox::critical(this,"Ошибка","Неправильный логин или пароль");
        } catch (const Critical&) {
            QMessageBox::warning(this, "Ошибка", "Обратитесь к админу.");
            qApp->quit();
        }
    }
    else{
        if(ui->radioButtonAbonent->isChecked()) {
            this->setWindowTitle("Клиент");

            try {
                QStringList array;
                array = txtWorker->zayavkiForPass(login, password);
                abonent -> currentAbonent = array;
                returnToMain(abonent);

            } catch (const NotFound&) {
                QMessageBox::critical(this,"Ошибка","Неправильный логин или пароль");
            } catch (const Critical&) {
                QMessageBox::warning(this, "Ошибка", "Обратитесь к админу.");
                qApp->quit();
            }
        }
        else{
            QMessageBox::critical(this,"Ошибка","Не выбран пользователь");
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    formaregistracii -> show(); //HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEeee
}
//void MainWindow::on_pushButton_3_clicked()//Услуги на главном окне
//{
//    usluginachalo -> show();
//}

void MainWindow::returnToMain(QWidget* nameWidget) //чтобы ставило виджет при возвращении
{
    if (stackedWidget->indexOf(nameWidget)==-1) {
        stackedWidget->addWidget(nameWidget); // Если нет, добавляем его
    }
    stackedWidget->setCurrentWidget(nameWidget);
    setCentralWidget(stackedWidget);
}

void MainWindow::on_pushButton_3_clicked()
{
    usluginachalo -> show();
}

