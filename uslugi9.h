#ifndef USLUGI9_H
#define USLUGI9_H

#include <QDialog>

namespace Ui {
class Uslugi9;
}

class Uslugi9 : public QDialog
{
    Q_OBJECT

public:
    explicit Uslugi9(QWidget *parent = nullptr);
    ~Uslugi9();

private:
    Ui::Uslugi9 *ui;
};

#endif // USLUGI9_H
