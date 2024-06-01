#ifndef TXTWORKER_H
#define TXTWORKER_H

#include <string>
#include <QStringList>

using namespace std;

class NotFound : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Critical :  public std::runtime_error {
    using std::runtime_error::runtime_error;
};


class txtworker
{
public:
    txtworker();
    ~txtworker();
    QStringList reading(string filepath);//лист возвращает список стринг
    QStringList zayavkiForPass(QString login, QString pass); //потому что тру и фолс
    void deleteFromAbonent(int index);
    QStringList splitWords(QString line);
    void writingToRab(QStringList registr); //ничего не возвращает
    void registKlient(QStringList registr);
    QString getRoleByLoginAndPass(QString login, QString pass);
    void addToZayavki(QStringList currentAbonent);
    void slotComboBoxTextChanged(QStringList array, QString text);
    void setCost(QStringList array,int skidka,float cost, float sum);
    void changeClient(QString name, QString company, QString tel, QString inn, QString chet, QString town, QString login);
    void changePassword(QString login, QString password);
    void deleteHistory(QString login);
    QStringList updateAbonent(QString login);
    bool checkRegistr(QString login);
    bool checkRegistrRab(QString login);
};

#endif // TXTWORKER_H
