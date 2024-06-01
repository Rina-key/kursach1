#include "buhz19.h"
#include "qstandarditemmodel.h"
#include "ui_buhz19.h"

using namespace std;

BuhZ19::BuhZ19(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuhZ19)
{
    ui->setupUi(this);
    buhr20 = new BuhR20(this);
}

BuhZ19::~BuhZ19()
{
    delete ui;
}

void BuhZ19::updateTable(){ //делаем таблицу и заносим данные
    QStandardItemModel *model = new QStandardItemModel(this);
    model->setColumnCount(3);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("№"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Кампания"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Информация"));

    ui->tableView->verticalHeader()->hide();

    string filepath = "C:\\kerker\\money.txt";
    QStringList registr = txtWorker -> reading(filepath);

    QStringList array;
    for(int i=0; i< registr.length(); i++){
        QString line= registr[i];
        array = txtWorker->splitWords(line);

        QStandardItem *item = new QStandardItem(QString::number(i+1));
        model->setItem(i,0,item);

        item = new QStandardItem(array[0]);
        model->setItem(i,1,item);

        QPushButton *button = new QPushButton("Рассчитать");//кнопка для открытия окна
        connect (button, &QPushButton::clicked, this, [this, array]() {
            buhr20->show();
            buhr20 -> tableMaker(array); //метод класса для рассчитывания и делания таблицы
        });

        ui->tableView->setIndexWidget(model->index(i,2), button);
    }
}

void BuhZ19::on_pushButton_2_clicked()
{
    this -> close();
}

