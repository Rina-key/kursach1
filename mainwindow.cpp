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
    connect(abonent, &Abonent:: abonentWindow, this, &MainWindow:: show); //(:: show - вызвали метод)

    formaregistracii=new formaRegistracii(); //HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

    admin=new Admin();
    operator11=new Operator11();
    buH18 = new buh18();
    connect(admin, &Admin:: adminWindow, this, &MainWindow:: show);//соединение сигнала и метода

//    connect(admin,&Admin::closed, this, MainWindow::returnToMain(ui->centralwidget));
//    connect(abonent,&Abonent::closed, this, MainWindow::returnToMain(ui->centralwidget));
    connect(admin, &Admin::closed, this, [this]() { returnToMain(ui->centralwidget); }); //Лямбда функция - это без названия, для чего? УДОБНАЯ ФУНКЦИЯ!!! Данные в коробочке
    connect(abonent, &Abonent::closed, this, [this]() { returnToMain(ui->centralwidget); });
    connect(buH18, &buh18::closed, this, [this]() { returnToMain(ui->centralwidget); });
    connect(operator11, &Operator11::closed, this, [this]() { returnToMain(ui->centralwidget); });

//    usluginachalo=new UslugiNachalo();
}

MainWindow::~MainWindow() //диструктор
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QStringList registr; // TODO: QSring
    QString login;
    QString password;
    bool loginout = false;
    login = ui->lineEdit->text();// взяли со строчек в форме //метод //QString это класс и вызываем его метод
    password = ui->lineEdit_2->text();

    if(ui->radioButtonRab->isChecked()) {
        this->setWindowTitle("Администратор");
        //try { // TODO: ???
           // rab = Database::getRabByLogin(login);

            //+ ...
        //}
        //catch(NotFound e){
        //    QMessageBox::critical(nullptr,"Ошибка","Неправильный логин или пароль");
        //}
        //catch (Ctitical) {
        //    QMessageBox::warning(...);
        //    qApp->quit();

       // }

        // QTableWidget

        // QTableView   QAbstractTableModel

       // Rab rab = Database::getRabByLogin(login);

        string filepath="C:\\kursach1\\rab.txt";
        registr = txtWorker->reading(filepath);//содержит список из файла
//        int col=5;
        for (int i=0; i<registr.length(); i++){
            QStringList array=txtWorker->splitWords(registr[i]);
            if (array [2]==login){
                if (array [3]==password){
                    if (array[4] =="Admin") {
                        returnToMain(admin);
                        loginout = true;//если условия пройдены, то ошибки не будет
                    }
                    if (array[4] =="Operator"){
                        returnToMain(operator11);
                        loginout = true;//если условия пройдены, то ошибки не будет
                    }
                    if (array[4] =="Buhgalter") {
                        returnToMain(buH18);
                        loginout = true;//если условия пройдены, то ошибки не будет
                    }
                }
            }
        }
        if (!loginout){
            QMessageBox::critical(nullptr,"Ошибка","Неправильный логин или пароль");
        }
    }
    else{
        if(ui->radioButtonAbonent->isChecked()) {
            string filepath="C:\\kursach1\\zayavki.txt";
            registr = txtWorker->reading(filepath);//содержит список из файла
//            int col=9;
            for (int i=0; i<registr.length(); i++){
                QStringList array=txtWorker->splitWords(registr[i]);
                if (array [6]==login){
                    if (array [7]==password){
                        returnToMain(abonent);
                        loginout =true;
                    }
                }
            }
            if (!loginout){
                QMessageBox::critical(nullptr,"Ошибка","Неправильный логин или пароль");
            }
        }
        else {
            QMessageBox::critical(nullptr,"Ошибка","Не выбран пользователь");
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
