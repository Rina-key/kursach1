#ifndef ABONENT4_H
#define ABONENT4_H

#include <QDialog>

namespace Ui {
class DeistvieAbonentaRis4;
}

class DeistvieAbonentaRis4 : public QDialog
{
    Q_OBJECT

public:
    explicit DeistvieAbonentaRis4(QWidget *parent = nullptr);
    ~DeistvieAbonentaRis4();

private:
    Ui::DeistvieAbonentaRis4 *ui;
};

#endif // ABONENT4_H
