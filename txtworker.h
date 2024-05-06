#ifndef TXTWORKER_H
#define TXTWORKER_H

#include <string>
#include <QStringList>

using namespace std;

class txtworker
{
public:
    txtworker();
    ~txtworker();
    QStringList reading(string filepath);//лист возвращает список стринг
    QStringList splitWords(QString line);
    void writingToRab(string filepath, QStringList registr); //ничего не возвращает
};

#endif // TXTWORKER_H
