#ifndef ISTORIA10_H
#define ISTORIA10_H

#include "txtworker.h"
#include <QDialog>

namespace Ui {
class Istoria10;
}

class Istoria10 : public QDialog
{
    Q_OBJECT

public:
    explicit Istoria10(QWidget *parent = nullptr);
    ~Istoria10();

    void updateTable();
    QStringList currentAbonent;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Istoria10 *ui;
    txtworker *txtWorker;
};

#endif // ISTORIA10_H
