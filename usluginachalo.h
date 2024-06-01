#ifndef USLUGINACHALO_H
#define USLUGINACHALO_H

#include <QDialog>
#include <uslovia8.h>
#include <ui_uslovia8.h>

namespace Ui {
class UslugiNachalo;
}

class UslugiNachalo : public QDialog
{
    Q_OBJECT

public:
    explicit UslugiNachalo(QWidget *parent = nullptr);
    ~UslugiNachalo();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::UslugiNachalo *ui;
    Uslovia8 *uslovia8;
};

#endif // USLUGINACHALO_H
