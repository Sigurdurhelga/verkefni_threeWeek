#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QDateTime>
#include <string>

using namespace std;

class scientist
{
private:
    QString name;
    QString sex;
    QDate doB;
    QDate doD;
public:
    scientist();
    scientist(QString name, QString sex, QDate doB, QDate doD);
    QString returnName();
    QString returnSex();
    QDate dateofBirth();
    QDate dateofDeath();
    QString dateofBirthQString();
    QString dateofDeathQString();
    friend bool operator < (const scientist& L, const scientist& R);
};

#endif // SCIENTIST_H
