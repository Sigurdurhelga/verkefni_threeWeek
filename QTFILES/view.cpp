#include <iostream>
#include "view.h"
#include "controller.h"
#include <string>

using namespace std;

view::view()
{
    // This should never happen
}

void view::displayInterface()
{
    controller cont;
    int select = 25;
      cout << "This is commandline interface for a CS Scientist program" << endl;
    while (select != 0){
        cout << "1. List all Scientists" << endl
             << "2. Add new Scientist" << endl
             << "3. Remove Scientist" << endl
             << "4. Search by Name" << endl
             << "5. Edit a Scientist" << endl
             << "0. Quit the Application" << endl;
        cin >> select;
        if(select != 0)
        {
            cont.functionHandler(select);
        }
    }
}

