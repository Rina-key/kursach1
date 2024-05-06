#ifndef ZAYAVKI13_H
#define ZAYAVKI13_H

#include <QDialog>

namespace Ui {
class Zayavki13;
}

class Zayavki13 : public QDialog
{
    Q_OBJECT

public:
    explicit Zayavki13(QWidget *parent = nullptr);
    ~Zayavki13();

private:
    Ui::Zayavki13 *ui;
};

#endif // ZAYAVKI13_H
