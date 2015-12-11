#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QDateTime>
#include <string>

using namespace std;

class Scientist
{
private:
    int id;
    QString name;
    QString sex;
    QString doB;
    QString doD;
    QString fact;
public:
    // Constructor
    Scientist();
    Scientist(int sID, QString name, QString sex, QString doB, QString doD, QString fact);

    // Set functions
    void setName(QString name);
    void setGender(QString sex);
    void setdoB(QString doB);
    void setdoD(QString doB);
    void setFact(QString fact);

    // Get functions
    QString returnName();
    QString returnSex();
    QString dateofBirth();
    QString dateofDeath();
    QString dateofBirthQString();
    QString dateofDeathQString();
    QString returnFact();
};

#endif // SCIENTIST_H
