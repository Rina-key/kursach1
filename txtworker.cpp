#include "txtworker.h"
#include <QDebug>
#include <iostream>
#include <fstream>
#include <txtworker.h>
#include <QDateTime>


txtworker::txtworker(){}
txtworker::~txtworker(){}

QStringList txtworker::reading(string filepath) //считываем txt
{
    QStringList registr;
    string line;
    ifstream in(filepath);
    if (in.is_open())
    {
        while (getline(in,line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            QString lineReg =QString::fromStdString(line); //Меняем тип строки
            registr << lineReg; //CЧитали и занесли строку
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
        throw Critical("file open failed");
    }
    in.close();
    return(registr);
}
void txtworker::writingToRab(QStringList registr)
{
    //string line;
    string filepath="C:\\kerker\\rab.txt";
    ofstream out(filepath, ios::app);
    if (out.is_open())
    {
        for (int i=0; i<registr.length(); i++) //если индекс меньше чем длина списка то работай
        {
            out <<registr[i].toStdString(); //так как берем по индексу то вводим по слову, используем как список слов
            if (i==registr.length()-1){
                out<<endl;
            }
            else {
                out <<';';
            }
        }

    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    out.close();
}


QStringList txtworker::splitWords(QString line)
{
    qDebug()<<line;//Выводим в консоль
    QStringList array;
    size_t pos = 0; //размер любого объекта в памяти, беззнаковый целый тип
    while (true) {
        int nextPos = line.indexOf(';', pos);
        if (nextPos == -1) {
            array << line.mid(pos); //выделяем строку
            break;
        } else {
            array << line.mid(pos, nextPos - pos);
        }
        pos= nextPos + 1;
    }
    return array;
}

QString txtworker::getRoleByLoginAndPass(QString login, QString pass)
{
    string filepath="C:\\kerker\\rab.txt";
    auto rawStrs = reading(filepath);
    for (int i=0; i<rawStrs.length(); i++){
        QStringList array= splitWords(rawStrs[i]);
        if (array [2]==login && array [3]==pass){
                return array[4];
        }
    }

    throw NotFound("rab not found");
}
QStringList txtworker::zayavkiForPass(QString login, QString pass)
{
    string filepath="C:\\kerker\\registr.txt";
    auto rawStrs = reading(filepath);
    for (int i=0; i<rawStrs.length(); i++){
        QStringList array= splitWords(rawStrs[i]);
        if (array [6]==login && array [7]==pass){
                return array;
        }
    }

    throw NotFound("abonent not found");
}
void txtworker::deleteFromAbonent(int index){ //удаляем по индексу
    string filepath="C:\\kerker\\zayavki.txt";
    string line;
    bool found = false;
    ifstream input(filepath);
    ofstream out("temp.txt"); // Создаем временный файл для записи
    if (input.is_open())
    {
        int col = 0;
        while (getline(input, line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            if (col!=index){
                out << line << endl;
                col++;
            }
            else {
                col++;
                found = true;
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    input.close();
    out.close();
    if (!found) {
        remove("temp.txt"); // Если строка не была найдена, удаляем временный файл
    } else {
        remove(filepath.c_str()); // Удаляем исходный файл
        rename("temp.txt", filepath.c_str()); // Переименовываем временный файл
    }
}

//регистраниция клиента
void txtworker::registKlient(QStringList registr){
    string filepath="C:\\kerker\\registr.txt";
    ofstream out(filepath, ios::app);
    if (out.is_open())
    {
        for (int i=0; i<registr.length(); i++) //если индекс меньше чем длина списка то работай
        {
            out <<registr[i].toStdString(); //так как берем по индексу то вводим по слову, используем как список слов
            if (i==registr.length()-1){
                out<<endl;
            }
            else {
                out <<';';
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    out.close();
}

// для добавления заявки из текущего пользователя
void txtworker::addToZayavki(QStringList currentAbonent){
    string filepath="C:\\kerker\\zayavki.txt";
    ofstream out(filepath, ios::app);
    if (out.is_open()){
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString dateTimeString = currentDateTime.toString("yyyy-MM-dd HH:mm:ss"); //считывание текущего времени
        string dateTimeStdString = dateTimeString.toStdString();
        for (int i=0; i<currentAbonent.length(); i++) //если индекс меньше чем длина списка то работай
        {
            out <<currentAbonent[i].toStdString(); //так как берем по индексу то вводим по слову, используем как список слов
            if (i==currentAbonent.length()-1){
                out << ';' << dateTimeStdString << ';' << "Ожидает" << endl;
            }
            else {
                out <<';';
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    out.close();
}

// для изменения стутуса в текстовом файле
void txtworker::slotComboBoxTextChanged(QStringList array, QString text){
    string filepath="C:\\kerker\\zayavki.txt";
    string line;
    bool found = false;
    ifstream input(filepath);
    ofstream out("temp.txt"); // Создаем временный файл для записи
    if (input.is_open())
    {
        while (getline(input, line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            QString lineReg = QString::fromStdString(line);
            QStringList array2 = splitWords(lineReg);
            if (array==array2 and text!=array2[9]){ //сравниваем по логину
                for (int i=0; i<array.length()-1;i++){
                    out << array2[i].toStdString() << ';'; //записываем то, что было!!!
                }
                out << text.toStdString() << endl;
                found=true;
            }
            else {
                out << line << endl;
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    input.close();
    out.close();
    if (!found) {
        remove("temp.txt"); // Если строка не была найдена, удаляем временный файл
    } else {
        remove(filepath.c_str()); // Удаляем исходный файл
        rename("temp.txt", filepath.c_str()); // Переименовываем временный файл
    }
}

//для заноса данных о стоиости, скидки
void txtworker::setCost(QStringList array,int skidka,float cost, float sum){
    string filepath="C:\\kerker\\money.txt";
    string line;
    bool found = false;
    ifstream input(filepath);
    ofstream out("temp.txt"); // Создаем временный файл для записи
    if (input.is_open())
    {
        while (getline(input, line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            QString lineReg = QString::fromStdString(line);
            QStringList array2 = splitWords(lineReg); //считываем еще раз лист, чтобы найти там строку, которую ищем
            //чтобы по-другому ее записать во временный файл
            if (array==array2){
                for (int i=0; i<array.length()-3;i++){ // -3, чтобы не считывать 3 последних числа
                    out << array[i].toStdString() << ';';
                }
                out << skidka << ';' << cost << ';' << sum << endl;
                found = true;
                qDebug() << skidka << ';' << cost << ';' << sum;
            }
            else {
                out << line << endl;
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    input.close();
    out.close();
    if (!found) {
        remove("temp.txt"); // Если строка не была найдена, удаляем временный файл
    } else {
        remove(filepath.c_str()); // Удаляем исходный файл
        rename("temp.txt", filepath.c_str()); // Переименовываем временный файл
    }
}

//для изменения данных о клиенте
void txtworker::changeClient(QString name, QString company, QString tel, QString inn, QString chet, QString town, QString login){
    string filepath="C:\\kerker\\registr.txt";;
    string line;
    bool found = false;
    ifstream input(filepath);
    ofstream out("temp.txt"); // Создаем временный файл для записи
    if (input.is_open())
    {
        while (getline(input, line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            QString lineReg = QString::fromStdString(line);
            QStringList array = splitWords(lineReg);
            if (array[6]==login){
                out << name.toStdString() << ';' << company.toStdString() << ';' << tel.toStdString()
                    << ';' << inn.toStdString() << ';' << chet.toStdString() << ';' << town.toStdString()
                    << ';' << login.toStdString() << ';' << array[7].toStdString() << endl;
                found=true;
            }
            else {
                out << line << endl;
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    input.close();
    out.close();
    if (!found) {
        remove("temp.txt"); // Если строка не была найдена, удаляем временный файл
    } else {
        remove(filepath.c_str()); // Удаляем исходный файл
        rename("temp.txt", filepath.c_str()); // Переименовываем временный файл
    }
}

//для изменения пароля
void txtworker::changePassword(QString login, QString password){
    string filepath="C:\\kerker\\registr.txt";;
    string line;
    bool found = false;
    ifstream input(filepath);
    ofstream out("temp.txt"); // Создаем временный файл для записи
    if (input.is_open())
    {
        while (getline(input, line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            QString lineReg = QString::fromStdString(line);
            QStringList array = splitWords(lineReg);
            if (array[6]==login){
                for (int i=0; i<array.length()-1;i++){ // -1, чтобы не считывать пароль
                    out << array[i].toStdString() << ';';
                }
                out << password.toStdString() << endl;
                found=true;
            }
            else {
                out << line << endl;
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    input.close();
    out.close();
    if (!found) {
        remove("temp.txt"); // Если строка не была найдена, удаляем временный файл
    } else {
        remove(filepath.c_str()); // Удаляем исходный файл
        rename("temp.txt", filepath.c_str()); // Переименовываем временный файл
    }
}

void txtworker::deleteHistory(QString login){
    string filepath="C:\\kerker\\money.txt";;
    string line;
    bool found = false;
    ifstream input(filepath);
    ofstream out("temp.txt"); // Создаем временный файл для записи
    if (input.is_open())
    {
        while (getline(input, line))// СЧИТАЛИ ИМЕННО ТУТ СТРОКУ!!!!!!!
        {
            QString lineReg = QString::fromStdString(line);
            QStringList array = splitWords(lineReg);
            if (array[0]!=login){
                out << line << endl;
            }
            else {
                found=true;
            }
        }
    }
    else {
        qDebug() << "Не удалось открыть файл"; // Выведи ошибку
    }
    input.close();
    out.close();
    if (!found) {
        remove("temp.txt"); // Если строка не была найдена, удаляем временный файл
    } else {
        remove(filepath.c_str()); // Удаляем исходный файл
        rename("temp.txt", filepath.c_str()); // Переименовываем временный файл
    }
}

QStringList txtworker::updateAbonent(QString login){ //чтобы обновить в самом абоненте при изменении данных
    string filepath="C:\\kerker\\registr.txt";
    auto rawStrs = reading(filepath);
    for (int i=0; i<rawStrs.length(); i++){
        QStringList array= splitWords(rawStrs[i]);
        if (array[6]==login){
                return array;
        }
    }
}

bool txtworker::checkRegistr(QString login){ //проверяем, есть ли кто-то с таким логином
    string filepath="C:\\kerker\\registr.txt";
    auto rawStrs = reading(filepath);
    for (int i=0; i<rawStrs.length(); i++){
        QStringList array= splitWords(rawStrs[i]);
        if (array[6]==login){
                return false;
        }
    }
    return true;
}

bool txtworker::checkRegistrRab(QString login){ //проверяем, есть ли кто-то с таким логином
    string filepath="C:\\kerker\\rab.txt";
    auto rawStrs = reading(filepath);
    for (int i=0; i<rawStrs.length(); i++){
        QStringList array= splitWords(rawStrs[i]);
        if (array[2]==login){
                return false;
        }
    }
    return true;
}
