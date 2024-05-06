#ifndef BUH18_H
#define BUH18_H

#include <QDialog>

namespace Ui {
class buh18;
}

class buh18 : public QDialog
{
    Q_OBJECT

public:
    explicit buh18(QWidget *parent = nullptr);
    ~buh18();
signals:
    void closed();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::buh18 *ui;
};

#endif // BUH18_H
