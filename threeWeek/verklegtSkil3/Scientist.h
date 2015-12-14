#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <QString>

using namespace std;

class Scientist
{
private:
    QString id;
    QString name;
    QString sex;
    QString doB;
    QString doD;
    QString description;
public:
    // Constructor
    Scientist();
    Scientist(QString sID, QString name, QString sex, QString doB, QString doD, QString description);

    // Set functions
    void setName(QString name);
    void setGender(QString sex);
    void setdoB(QString doB);
    void setdoD(QString doB);
    void setDescription(QString Sdescription);

    // Get functions
    QString returnID();
    QString returnName();
    QString returnSex();
    QString dateofBirth();
    QString dateofDeath();
    QString dateofBirthQString();
    QString dateofDeathQString();
    QString returnDescription();
};

#endif // SCIENTIST_H
