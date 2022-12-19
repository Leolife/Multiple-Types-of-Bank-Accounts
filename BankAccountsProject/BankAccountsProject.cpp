#include <iostream>
#include <string>
#include <iomanip>
#include "accessMenu.h"

using namespace std;

/*
* when you refactor this, do these things:
* 1. incorporate try catches for exceptions if useful
* 2. incorporate pointers maybe?
* DONE 3. use header files
* DONE 4. comment out the code better
* DONE 5. Create a Menu
* 6. FIX account number issue to be a set account number for each bank account, maybe ask user for account number6
* 7. 
*/


int main()
{
    accessMenu printMenu;
    printMenu.menu();

    return 0;
}