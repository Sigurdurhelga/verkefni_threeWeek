#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <QDateTime>
#include <string>

class Computers
{
    private:
        int ID;
        QString name;
        bool created;
        int creationYear;
        QString inventor;
        QString description;


    public:
        Computers();
        Computers(int SID, QString Sname, bool Screated, int ScreationYear, QString Sinventor, QString Sdescription);
};

#endif // COMPUTERS_H
