#ifndef ZAYAVKI12_H
#define ZAYAVKI12_H

#include <QDialog>

namespace Ui {
class Zayavki12;
}

class Zayavki12 : public QDialog
{
    Q_OBJECT

public:
    explicit Zayavki12(QWidget *parent = nullptr);
    ~Zayavki12();

private:
    Ui::Zayavki12 *ui;
};

#endif // ZAYAVKI12_H
