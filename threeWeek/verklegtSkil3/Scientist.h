#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QDateTime>
#include <string>

using namespace std;

class Scientist
{
private:
    QString name;
    bool sex;
    QDate doB;
    QDate doD;
    QString fact;
public:
    // Constructor
    Scientist();
    Scientist(QString name, bool sex, QDate doB, QDate doD, QString fact);

    // Set functions
    void setName(QString name);
    void setGender(bool sex);
    void setdoB(QDate doB);
    void setdoD(QDate doB);
    void setFact(QString fact);

    // Get functions
    QString returnName();
    bool returnSex();
    QDate dateofBirth();
    QDate dateofDeath();
    QString dateofBirthQString();
    QString dateofDeathQString();
    QString returnFact();
};

#endif // SCIENTIST_H
