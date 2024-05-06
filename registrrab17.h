#ifndef REGISTRRAB17_H
#define REGISTRRAB17_H
#include <txtworker.h>
#include <QDialog>

namespace Ui {
class RegistrRab17;
}

class RegistrRab17 : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrRab17(QWidget *parent = nullptr);
    ~RegistrRab17();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::RegistrRab17 *ui;
    txtworker *txtWorker;
};

#endif // REGISTRRAB17_H
