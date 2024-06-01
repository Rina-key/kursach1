#include "zayavki13.h"
#include "qstandarditemmodel.h"
#include "ui_zayavki13.h"

Zayavki13::Zayavki13(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zayavki13)
{
    ui->setupUi(this);
}

Zayavki13::~Zayavki13()
{
    delete ui;
}

void Zayavki13::tableMaker(QStringList array) {
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(1);
    ui->tableView->setModel(model);

    QStringList headerLabels = {"Кампания","Имя","Номер","Город","Дата"};
//                                           "ИНН","Счёт","Город","Логин","Дата"};
    model->setVerticalHeaderLabels(headerLabels);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->hide();


    for (int k = 0; k < 3; k++){
        QStandardItem *item = new QStandardItem(array[k]);
        model-> setItem (k, 0, item);
    }
    QStandardItem *item = new QStandardItem(array[5]);
    model-> setItem (3, 0, item);
    item = new QStandardItem(array[8]);
    model-> setItem (4, 0, item);

}

void Zayavki13::on_pushButton_3_clicked()//отмена
{
    this->close();
}

