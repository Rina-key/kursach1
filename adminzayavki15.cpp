#include "adminzayavki15.h"
#include "ui_adminzayavki15.h"
#include "ui_adminzayavki15.h"
#include <string>
#include <QStandardItemModel>

AdminZayavki15::AdminZayavki15(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminZayavki15)
{
    ui->setupUi(this);
    this->setWindowTitle("Заявки");

    adminz16 = new AdminZ16(this);
    connect(adminz16, &AdminZ16:: deletedAbonent, this, &AdminZayavki15:: updateTable);//соединение сигнала и метода
    updateTable();
}

AdminZayavki15::~AdminZayavki15()
{
    delete ui;
}

void AdminZayavki15::on_pushButton_2_clicked()
{
    this->close();
}

void AdminZayavki15::updateTable(){
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(4);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("№"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Кампания"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Информация"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Статус"));

    ui->tableView->verticalHeader()->hide();

    string filepath = "C:\\kerker\\zayavki.txt";
    QStringList registr = txtWorker -> reading(filepath);

    QStringList array;
    for(int i=0; i< registr.length(); i++){
        QString line= registr[i];
        array = txtWorker->splitWords(line);

        QStandardItem *item = new QStandardItem(QString::number(i+1));
        model->setItem(i,0,item);

        item = new QStandardItem(array[0]);
        model->setItem(i,1,item);

        QPushButton *button = new QPushButton("Посмотреть");
        connect (button, &QPushButton::clicked, this, [this, array, i]() {
            adminz16->show();
            adminz16 -> tableMaker(array, i);
        });

        ui->tableView->setIndexWidget(model->index(i,2), button);

        item = new QStandardItem(array[9]);
        model->setItem(i,3,item);
    }
}
