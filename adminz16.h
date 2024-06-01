#ifndef ADMINZ16_H
#define ADMINZ16_H

#include <QDialog>
#include <txtworker.h>

namespace Ui {
class AdminZ16;
}

class AdminZ16 : public QDialog
{
    Q_OBJECT

public:
    explicit AdminZ16(QWidget *parent = nullptr);
    ~AdminZ16();
    void tableMaker (QStringList array, int index);


private slots:
    void on_pushButton_2_clicked();

signals:
    void deletedAbonent();

private:
    Ui::AdminZ16 *ui;
    txtworker* txtWorker;
};

#endif // ADMINZ16_H
