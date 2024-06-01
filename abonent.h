#ifndef ABONENT_H
#define ABONENT_H

#include <QDialog>
#include "istoria10.h"
#include "uslugiris7.h"
#include "profile5.h"

namespace Ui {
class Abonent;
}

class Abonent : public QDialog
{
    Q_OBJECT

public:
    explicit Abonent(QWidget *parent = nullptr);
    ~Abonent();
    QStringList currentAbonent;
signals:
    void abonentWindow();
    void closed();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Abonent *ui;
    Istoria10* istoria10;
    UslugiRis7* uslugiris7;
    Profile5* profile5;
};

#endif // ABONENT_H
