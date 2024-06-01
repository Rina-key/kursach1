#ifndef BUHZ19_H
#define BUHZ19_H

#include "buhr20.h"
#include <QDialog>
#include "txtworker.h"

namespace Ui {
class BuhZ19;
}

class BuhZ19 : public QDialog
{
    Q_OBJECT

public:
    explicit BuhZ19(QWidget *parent = nullptr);
    ~BuhZ19();
    void updateTable();

private slots:
    void on_pushButton_2_clicked();

private:
    BuhR20 *buhr20;
    txtworker *txtWorker;
    Ui::BuhZ19 *ui;
};

#endif // BUHZ19_H
