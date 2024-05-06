#ifndef ADMINZ16_H
#define ADMINZ16_H

#include <QDialog>

namespace Ui {
class AdminZ16;
}

class AdminZ16 : public QDialog
{
    Q_OBJECT

public:
    explicit AdminZ16(QWidget *parent = nullptr);
    ~AdminZ16();

private:
    Ui::AdminZ16 *ui;
};

#endif // ADMINZ16_H
