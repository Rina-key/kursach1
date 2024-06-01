#include "istoria10.h"
#include "qdatetime.h"
#include "qstandarditemmodel.h"
#include "ui_istoria10.h"
#include <QMessageBox>

Istoria10::Istoria10(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Istoria10)
{
    ui->setupUi(this);
}

Istoria10::~Istoria10()
{
    delete ui;
}

void Istoria10::on_pushButton_2_clicked()
{
    this->close();
}

void Istoria10::updateTable(){ //делаем таблицу, похожую на админа
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(6);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Дата"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ВремяНач"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ВремяКон"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Город"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Продолжительность"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Стоимость"));

    ui->tableView->verticalHeader()->hide();

    string filepath = "C:\\kerker\\money.txt";
    QStringList registr = txtWorker -> reading(filepath);

    QStringList array;
    for(int i=0; i< registr.length(); i++){
        QString line = registr[i];
        array = txtWorker->splitWords(line);
        if (array[0]==currentAbonent[6]){ //чтобы показывался только этот абонент
            QStandardItem *item = new QStandardItem(array[4]); //каждый по отдельности, т.к. они не по порядку
            model->setItem(i,0,item);

            item = new QStandardItem(array[5]);
            model->setItem(i,1,item);

            item = new QStandardItem(array[6]);
            model->setItem(i,2,item);

            item = new QStandardItem(array[2]);
            model->setItem(i,3,item);

            QTime time1 = QTime::fromString(array[5], "HH:mm");
            QTime time2 = QTime::fromString(array[6], "HH:mm");

            int seconds = time1.secsTo(time2); //разница времени в секундых
            int minutes = seconds / 60;

            item = new QStandardItem(QString::number(minutes));
            model->setItem(i,4,item);

            item = new QStandardItem(array[9]); //сумма
            model->setItem(i,5,item);
        }
    }
}


void Istoria10::on_pushButton_clicked()
{
    txtWorker->deleteHistory(currentAbonent[6]);
    updateTable();
    QMessageBox::information(this, "Успех", "История удалена");
}

