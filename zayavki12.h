#ifndef ZAYAVKI12_H
#define ZAYAVKI12_H

#include <QDialog>
#include "zayavki13.h"
#include "txtworker.h"

namespace Ui {
class Zayavki12;
}

class Zayavki12 : public QDialog
{
    Q_OBJECT

public:
    explicit Zayavki12(QWidget *parent = nullptr);
    ~Zayavki12();

    void updateTable();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Zayavki12 *ui;
    Zayavki13* zayavki13;
    txtworker* txtWorker;
};

#endif // ZAYAVKI12_H
