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
        QString description;


    public:
        Computers();
        Computers(int SID, QString Sname, bool Screated, int ScreationYear, QString Sdescription);
        QString returnName();
        bool returnCreated();
        int returnCreationYear();
        QString returnDescription();
        void setName(QString name);
        void setCreated(bool sCreated);
        void setCreationYear(int sCreationYear);
        void setDescription(QString sDescription);
};

#endif // COMPUTERS_H
