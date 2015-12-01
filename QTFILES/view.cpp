#include <iostream>
#include "view.h"
#include "controller.h"
#include <string>

using namespace std;

view::view()
{
    // This should never happen
}

// This function takes the users input and forwards it to the controller.
void view::displayInterface()
{
    controller cont;
    int select = 25;
      cout << "This is commandline interface for a CS scientist program" << endl;
    while (select != 0){
        cout << "1. List all scientists" << endl
             << "2. Add new scientist" << endl
             << "3. Remove scientist" << endl
             << "4. Search by name" << endl
             << "0. Quit the application" << endl;
        cin >> select;
        if(select != 0)
        {
            cont.functionHandler(select);
        }
    }
}

