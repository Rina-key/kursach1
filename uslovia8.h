#ifndef USLOVIA8_H
#define USLOVIA8_H

#include <QDialog>

namespace Ui {
class Uslovia8;
}

class Uslovia8 : public QDialog
{
    Q_OBJECT

public:
    explicit Uslovia8(QWidget *parent = nullptr);
    ~Uslovia8();


private slots:

private:
    Ui::Uslovia8 *ui;
};

#endif // USLOVIA8_H
