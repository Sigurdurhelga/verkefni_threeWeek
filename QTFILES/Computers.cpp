#include "Computers.h"

Computers::Computers()
{

}

Computers::Computers(int SID, bool Screated, QDate ScreationDate, QString Sname, QString Sdescription)
{
    ID = SID;
    created = Screated;
    creationDate = ScreationDate;
    name = Sname;
    description = Sdescription;
}
