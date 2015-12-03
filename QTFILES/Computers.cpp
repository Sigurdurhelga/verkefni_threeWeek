#include "Computers.h"

Computers::Computers()
{

}

Computers(int SID, bool Screated, QDate ScreationDate, QString Sname, QString Sdescription)
{
    id = SID;
    created = Screated;
    creationDate = ScreationDate;
    name = Sname;
    description = Sdescription;
}
