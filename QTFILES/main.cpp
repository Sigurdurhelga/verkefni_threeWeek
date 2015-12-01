#include <QCoreApplication>
#include "View.h"





using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    View newView;
    newView.displayInterface();

    return 0;
}
