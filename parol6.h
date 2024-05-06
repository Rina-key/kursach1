#ifndef PAROL6_H
#define PAROL6_H

#include <QDialog>

namespace Ui {
class ParolRis6;
}

class ParolRis6 : public QDialog
{
    Q_OBJECT

public:
    explicit ParolRis6(QWidget *parent = nullptr);
    ~ParolRis6();

private:
    Ui::ParolRis6 *ui;
};

#endif // PAROL6_H
