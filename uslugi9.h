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

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Uslugi9 *ui;
};

#endif // USLUGI9_H
