#include "adminz16.h"
#include "ui_adminz16.h"
#include <QStandardItemModel>
#include <QMessageBox>


AdminZ16::AdminZ16(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminZ16)
{
    ui->setupUi(this);
}

AdminZ16::~AdminZ16()
{
    delete ui;
}

void AdminZ16::tableMaker(QStringList array, int index) {
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(1);
    ui->zayavkiATableView->setModel(model);

    QStringList headerLabels = {"Кампания","Имя","Номер","ИНН","Счёт","Город","Логин","Дата"};
    model->setVerticalHeaderLabels(headerLabels);

    ui->zayavkiATableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->zayavkiATableView->horizontalHeader()->hide();


    for (int k = 0; k < array.length() - 2; k++){
        QStandardItem *item = new QStandardItem(array[k]);
        model-> setItem (k, 0, item);
    }
    QStandardItem *item = new QStandardItem(array[8]);
    model-> setItem (7, 0, item);

    connect(ui->deleteAbonent, &QPushButton::clicked, this, [this, index](){
        txtWorker->deleteFromAbonent(index);
        emit deletedAbonent();
        this->close();
    });

}

void AdminZ16::on_pushButton_2_clicked()
{
    this->close();
}


















//    QModelIndex topLeft = model->index(0, 0); // индекс левого верхнего элемента в таблице
//    QModelIndex bottomRight = model->index(7, 0); // индекс правого нижнего элемента в таблице
//    emit model->dataChanged(topLeft, bottomRight); // отправляем сигнал об изменении данных


