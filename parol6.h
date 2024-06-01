#ifndef PAROL6_H
#define PAROL6_H

#include "txtworker.h"
#include <QDialog>

namespace Ui {
class Parol6;
}

class Parol6 : public QDialog
{
    Q_OBJECT

public:
    explicit Parol6(QWidget *parent = nullptr);
    ~Parol6();
    QStringList currentAbonent;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Parol6 *ui;
    txtworker *txtWorker;
};

#endif // PAROL6_H
