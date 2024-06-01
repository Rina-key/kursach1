#include "buhr20.h"
#include "qdatetime.h"
#include "qstandarditemmodel.h"
#include "ui_buhr20.h"
#include <QMessageBox>

BuhR20::BuhR20(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuhR20)
{
    ui->setupUi(this);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    QIntValidator *validator = new QIntValidator(0, 100, this);
    ui->lineEdit->setValidator(validator);
    validator = new QIntValidator(0, 1000, this);
    ui->lineEdit_2->setValidator(validator);
}

BuhR20::~BuhR20()
{
    delete ui;
}

void BuhR20::tableMaker(QStringList array) {
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");

    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(1);
    ui->tableView->setModel(model);

    QStringList headerLabels = {"Логин","Кампания","Откуда","Куда","Дата","Звонокнач","Звоноккон","Продолжительность"};
    model->setVerticalHeaderLabels(headerLabels);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->hide();


    for (int k = 0; k < array.length() - 2; k++){
        QStandardItem *item = new QStandardItem(array[k]);
        model-> setItem (k, 0, item);
    }
    QTime time1 = QTime::fromString(array[5], "HH:mm"); //считываем время
    QTime time2 = QTime::fromString(array[6], "HH:mm");

    int seconds = time1.secsTo(time2); //считаем разницу в секундах
    int minutes = seconds / 60; //считаем продолжительность в минутах

    QStandardItem *item = new QStandardItem(QString::number(minutes));
    model-> setItem (7, 0, item);

    connect (ui->pushButton, &QPushButton::clicked, this, [this, array, minutes]() { //соединяем нажатие кнопки
        if (!(ui->lineEdit->text().isEmpty() or ui->lineEdit_2->text().isEmpty())){
            int skidka = ui->lineEdit->text().toInt(); //считываем скидку
            float cost = ui->lineEdit_2->text().toFloat(); //считываем стоимость
            float sum = skidka/100.0*cost*minutes; // считаем сумму
            txtWorker -> setCost(array,skidka,cost,sum);
        }// передаем при нажатии кнопки лист, скидку, стоимость и сумму}
        else {
            QMessageBox::warning(this,"Ошибка","Проверьте пустые ячейки");
        }
    });

}


void BuhR20::on_pushButton_2_clicked()
{
    this->close();
}
