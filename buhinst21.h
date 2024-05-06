#ifndef BUHINST21_H
#define BUHINST21_H

#include <QDialog>

namespace Ui {
class BuhInst21;
}

class BuhInst21 : public QDialog
{
    Q_OBJECT

public:
    explicit BuhInst21(QWidget *parent = nullptr);
    ~BuhInst21();

private:
    Ui::BuhInst21 *ui;
};

#endif // BUHINST21_H
