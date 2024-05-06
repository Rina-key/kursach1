#include "buhr20.h"
#include "ui_buhr20.h"

BuhR20::BuhR20(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuhR20)
{
    ui->setupUi(this);
}

BuhR20::~BuhR20()
{
    delete ui;
}
