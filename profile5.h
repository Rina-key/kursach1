#ifndef PROFILE5_H
#define PROFILE5_H

#include <QDialog>

namespace Ui {
class ProfileRis5;
}

class ProfileRis5 : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileRis5(QWidget *parent = nullptr);
    ~ProfileRis5();

private:
    Ui::ProfileRis5 *ui;
};

#endif // PROFILE5_H
