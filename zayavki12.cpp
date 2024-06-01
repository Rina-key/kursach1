#include "zayavki12.h"
#include "qcombobox.h"
#include "qstandarditemmodel.h"
#include "ui_zayavki12.h"
#include <QMessageBox>

Zayavki12::Zayavki12(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zayavki12)
{
    ui->setupUi(this);
    zayavki13 = new Zayavki13(this);
}

Zayavki12::~Zayavki12()
{
    delete ui;
}

void Zayavki12::on_pushButton_2_clicked()
{
    this->close();
}


void Zayavki12::updateTable(){
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
        connect (button, &QPushButton::clicked, this, [this, array]() {
            zayavki13-> show();
            zayavki13 -> tableMaker(array);
        });

        ui->tableView->setIndexWidget(model->index(i,2), button);

        QComboBox *comboBox = new QComboBox();
        comboBox->addItems({"Одобрено", "Отклонено", "Ожидает"});
        comboBox->setCurrentText(array[9]);
        connect(comboBox, QOverload<const QString &>::of(&QComboBox::currentTextChanged), //Если значение ячеек изменится,
                //то оно сразу в таблицу уйдет
                [=](const QString &text){
                    txtWorker->slotComboBoxTextChanged(array, text);
                    updateTable();
                });

        ui->tableView->setIndexWidget(model->index(i, 3), comboBox);
    }
}

