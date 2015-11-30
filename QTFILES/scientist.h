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
};

#endif // SCIENTIST_H
