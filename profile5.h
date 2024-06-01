#ifndef PROFILE5_H
#define PROFILE5_H

#include <QDialog>
#include "parol6.h"
#include "txtworker.h"

namespace Ui {
class Profile5;
}

class Profile5 : public QDialog
{
    Q_OBJECT

public:
    explicit Profile5(QWidget *parent = nullptr);
    ~Profile5();
    QStringList currentAbonent;
    void updateLines();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

signals:
    void closedForSaving();

private:
    Ui::Profile5 *ui;

    Parol6* parol6;
    txtworker *txtWorker;
};

#endif // PROFILE5_H
