#ifndef BUHZ19_H
#define BUHZ19_H

#include <QDialog>

namespace Ui {
class BuhZ19;
}

class BuhZ19 : public QDialog
{
    Q_OBJECT

public:
    explicit BuhZ19(QWidget *parent = nullptr);
    ~BuhZ19();

private:
    Ui::BuhZ19 *ui;
};

#endif // BUHZ19_H
