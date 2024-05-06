#include "txtworker.h"
#include <QDebug>
#include <iostream>
#include <fstream>


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
    }
    in.close();
    return(registr);
}
void txtworker::writingToRab(string filepath, QStringList registr)
{
    //string line;
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







