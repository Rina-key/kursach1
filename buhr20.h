#ifndef BUHR20_H
#define BUHR20_H

#include <QDialog>

namespace Ui {
class BuhR20;
}

class BuhR20 : public QDialog
{
    Q_OBJECT

public:
    explicit BuhR20(QWidget *parent = nullptr);
    ~BuhR20();

private:
    Ui::BuhR20 *ui;
};

#endif // BUHR20_H
