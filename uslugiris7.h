#ifndef USLUGIRIS7_H
#define USLUGIRIS7_H

#include <QDialog>
#include "uslovia8.h"
#include "txtworker.h"
#include "uslugi9.h"

namespace Ui {
class UslugiRis7;
}

class UslugiRis7 : public QDialog
{
    Q_OBJECT

public:
    explicit UslugiRis7(QWidget *parent = nullptr);
    ~UslugiRis7();
    QStringList currentAbonent;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UslugiRis7 *ui;
    Uslovia8 *uslovia8;
    Uslugi9 * uslugi9;
    txtworker *txtWorker;
};

#endif // USLUGIRIS7_H
