#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QDateTime>
#include <string>

using namespace std;

class Scientist
{
private:
    QString name;
    QString sex;
    QDate doB;
    QDate doD;
public:
    Scientist();
    Scientist(QString name, QString sex, QDate doB, QDate doD);
    QString returnName();
    QString returnSex();
    QDate dateofBirth();
    QDate dateofDeath();
    QString dateofBirthQString();
    QString dateofDeathQString();
    void setName(QString name);
    void setGender(QString sex);
    void setdoB(QDate doB);
    void setdoD(QDate doB);
};

#endif // SCIENTIST_H
