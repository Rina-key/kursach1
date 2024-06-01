#ifndef FORMAREGISTRACII_H
#define FORMAREGISTRACII_H

#include <QDialog>
#include <txtworker.h>

namespace Ui {
class formaRegistracii;
}

class formaRegistracii : public QDialog
{
    Q_OBJECT

public:
    explicit formaRegistracii(QWidget *parent = nullptr);
    ~formaRegistracii();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::formaRegistracii *ui;
    txtworker *txtWorker;
};

#endif // FORMAREGISTRACII_H
