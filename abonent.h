#ifndef ABONENT_H
#define ABONENT_H

#include <QDialog>

namespace Ui {
class Abonent;
}

class Abonent : public QDialog
{
    Q_OBJECT

public:
    explicit Abonent(QWidget *parent = nullptr);
    ~Abonent();
signals:
    void abonentWindow();
    void closed();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::Abonent *ui;
};

#endif // ABONENT_H
