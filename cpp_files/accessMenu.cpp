#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "accessMenu.h"
#include "serviceChargeChecking.h"
#include "noServiceChargeChecking.h"
#include "highInterestChecking.h"
#include "savingsAccount.h"
#include "highInterestSavings.h"
#include "certificateOfDeposit.h"

using namespace std;

//menu class to print a menu for the user to choose which bank account to operate
void accessMenu::menu()
{
    int selection;
    string answer;
    bool main = true;
    bool cont;

    while (main)
    {
        //printing an organized menu of the user's bank account options
        cont = false;
        cout << endl << setw(37) << "--------------------\n";
        cout << setw(48) << "|----------| Your Bank Accounts |----------|" << endl;
        cout << setw(37) << "-------------------- " << endl;
        cout << setw(42) << "1: Service Charge Checking Account " << endl << setw(45) << "2: No Service Charge Checking Account " << endl << setw(41) << "3: High Interest Checking Account " << endl
            << setw(26) << "4: Savings Account " << endl << setw(40) << "5: High Interest Savings Account " << endl << setw(33) << "6: Certificate of Deposit " << endl;
        cout << setw(48) << "|------------------------------------------|" << endl;
        cout << endl;
        cout << setw(44) << "\nSelect which bank account to use (1-6): ";
        cin >> selection;
        cin.clear();//lines 38 and 39 make sure the program does not endlessly loop with the same input
        cin.ignore(1000, '\n');
        cout << endl;
        if (selection >= 1 && selection <= 6)
        {
            if (selection == 1)
            {
                serviceChargeChecking serviceChargeChecking;
                serviceChargeChecking.print();
            }
            else if (selection == 2)
            {
                noServiceChargeChecking noServiceChargeChecking;
                noServiceChargeChecking.print();
            }
            else if (selection == 3)
            {
                highInterestChecking highInterestChecking;
                highInterestChecking.print();
            }
            else if (selection == 4)
            {
                savingsAccount savingsAccount;
                savingsAccount.print();
            }
            else if (selection == 5)
            {
                highInterestSavings highInterestSavings;
                highInterestSavings.print();
            }
            else if (selection == 6)
            {
                certificateOfDeposit certificateOfDeposit;
                certificateOfDeposit.print();
            }
        }
        else
        {
            cout << "Invalid selection. " << endl;
            cont = true;
        }


        while (!cont)
        {
            cout << "\nWould you like to access another bank account? (Y or N): ";
            cin >> answer;
            if (answer == "y" || answer == "Y")
            {
                cont = true;
            }
            else if (answer == "n" || answer == "N")
            {
                cout << "\nThank you for using our services, have a nice day! " << endl;
                main = false;
                cont = true;
            }
            else
                cout << "Please enter Y or N to indicate yes or no, respectively. ";
        }
    }
}

