#ifndef USLUGINACHALO_H
#define USLUGINACHALO_H

#include <QDialog>

namespace Ui {
class UslugiNachalo;
}

class UslugiNachalo : public QDialog
{
    Q_OBJECT

public:
    explicit UslugiNachalo(QWidget *parent = nullptr);
    ~UslugiNachalo();

//private slots:
//    void on_pushButton_3_clicked();

private:
    Ui::UslugiNachalo *ui;
};

#endif // USLUGINACHALO_H
