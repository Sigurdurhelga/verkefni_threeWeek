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
        QString type;
        QString description;


    public:
        // Constructors
        Computers();
        Computers(int SID, QString Sname, bool Screated, int ScreationYear, QString type, QString Sdescription);

        // Set functions
        void setName(QString name);
        void setCreated(bool sCreated);
        void setCreationYear(int sCreationYear);
        void setType(QString sType);
        void setDescription(QString sDescription);

        // Get functions
        bool returnCreated();
        int returnCreationYear();
        QString returnName();
        QString returnType();
        QString returnDescription();
};

#endif // COMPUTERS_H
