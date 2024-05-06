#ifndef USLUGIRIS7_H
#define USLUGIRIS7_H

#include <QDialog>

namespace Ui {
class UslugiRis7;
}

class UslugiRis7 : public QDialog
{
    Q_OBJECT

public:
    explicit UslugiRis7(QWidget *parent = nullptr);
    ~UslugiRis7();

private:
    Ui::UslugiRis7 *ui;
};

#endif // USLUGIRIS7_H
