#include <iostream>
using std::cout;
using std::endl;

#include "Create.h"

CreateAndDestory::CreateAndDestory(int ID, string msg)
{
    objectID = ID;
    message = msg;

    cout << "Object " << objectID << "    constructor runs    " << message << endl;
}
CreateAndDestory::~CreateAndDestory()
{
    // output newline for certain objects; helps readability
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");

    cout << "Object " << objectID << "    destructor runs    "
         << message << endl;
}