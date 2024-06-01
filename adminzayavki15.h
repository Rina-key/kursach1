#ifndef ADMINZAYAVKI15_H
#define ADMINZAYAVKI15_H

#include <QDialog>
#include "txtworker.h"
#include "adminz16.h"

namespace Ui {
class AdminZayavki15;
}

class AdminZayavki15 : public QDialog
{
    Q_OBJECT

public:
    explicit AdminZayavki15(QWidget *parent = nullptr);
    ~AdminZayavki15();
    void updateTable();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AdminZayavki15 *ui;
    txtworker *txtWorker;
    AdminZ16 *adminz16;

};

#endif // ADMINZAYAVKI15_H
