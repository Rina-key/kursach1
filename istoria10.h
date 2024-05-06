#ifndef ISTORIA10_H
#define ISTORIA10_H

#include <QDialog>

namespace Ui {
class Istoria10;
}

class Istoria10 : public QDialog
{
    Q_OBJECT

public:
    explicit Istoria10(QWidget *parent = nullptr);
    ~Istoria10();

private:
    Ui::Istoria10 *ui;
};

#endif // ISTORIA10_H
