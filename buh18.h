#ifndef BUH18_H
#define BUH18_H

#include <QDialog>
#include "buhz19.h"
#include "buhinst21.h"

namespace Ui {
class buh18;
}

class buh18 : public QDialog
{
    Q_OBJECT

public:
    explicit buh18(QWidget *parent = nullptr);
    ~buh18();
signals:
    void closed();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::buh18 *ui;
    BuhZ19* buhz19;
    BuhInst21* buhinst21;
};

#endif // BUH18_H
