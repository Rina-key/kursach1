#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //самый главный класс, запускает впринципе весь проект
    MainWindow w;
    w.show();
    return a.exec(); // когда закрываем все переменные подчищаются
}
