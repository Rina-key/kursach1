#ifndef BUHR20_H
#define BUHR20_H

#include "txtworker.h"
#include <QDialog>

namespace Ui {
class BuhR20;
}

class BuhR20 : public QDialog
{
    Q_OBJECT

public:
    explicit BuhR20(QWidget *parent = nullptr);
    ~BuhR20();

    void tableMaker(QStringList array);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::BuhR20 *ui;
    txtworker *txtWorker;

};

#endif // BUHR20_H
