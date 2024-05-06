#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <abonent.h>
#include <formaregistracii.h>
//HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
#include <admin.h>
#include <QStackedWidget>
#include <usluginachalo.h>
#include <uslovia8.h>
#include <txtworker.h>
#include <operator11.h>
#include <buh18.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow //объявдение класса
{
    Q_OBJECT //его наследует любой класс, помогает использовать сигналы и слоты (если бы не было, то приват бы не работал)


public: //объяление конструктора
    MainWindow(QWidget *parent = nullptr);//обнуляет указатель, очищает ячейку памяти
    ~MainWindow(); //объявление диструктора


private slots: //слоты по нажатию кнопок или любого действия, они есть только в QT
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

private: //используем только в этом классе
    Ui::MainWindow *ui; //формы, для применения свойств
    QStackedWidget *stackedWidget;
    Abonent *abonent;
    formaRegistracii *formaregistracii; //hereeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
    Admin *admin;//указатель, объекты значние которых адреса
//    UslugiNachalo *usluginachalo;
//    Uslovia8 *uslovia8;
    txtworker *txtWorker;
    Operator11 *operator11;
    buh18 *buH18;
    void returnToMain(QWidget* nameWidget);



};
#endif // MAINWINDOW_H
