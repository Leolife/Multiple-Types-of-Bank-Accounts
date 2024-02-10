#pragma once
#include "bankAccount.h"
#include <iostream>
#include <string>

using namespace std;

//general bank account to build upon for other types of bank accounts
bankAccount::bankAccount()
{
    name = "N/A";
    accountNumber = 0;
    balance = 100.0;
}
bankAccount::~bankAccount() {};

string bankAccount::getName()
{
    return name;
}
int bankAccount::getAccountNumber()
{
    return accountNumber;//returns account number
}
double bankAccount::getBalance()
{
    return balance;
}

void bankAccount::setName(string n)
{
    name = n;
}
void bankAccount::setAccountNumber() //static account number generator, sets account numbers for all types of accounts- FIX
{
    static int acctNumber = 100;
    accountNumber = acctNumber;
    acctNumber++;
}
void bankAccount::setBalance(double bal)
{
    balance = bal;
}

void bankAccount::withdraw()
{
    string answer;
    double amount;
    while (true)
    {
        cout << "Balance: $" << balance << endl;
        cout << "Would you like to make a withdrawal? (Y or N): ";
        cin >> answer;
        //processes withdrawal
        if (answer == "Y" || answer == "y")
        {
            cout << "Withdrawal amount: $";
            cin >> amount;
            cin.clear();//lines 66 and 67 make sure the program does not endlessly loop with the same input
            cin.ignore(1000, '\n');
            balance -= amount;
            //prevents user from withdrawing more than they have in their account
            if (balance < 0)
            {
                balance += amount;
                cout << "Error: amount exceeds balance.\n";
            }
        }
        else if (answer == "N" || answer == "n")
        {
            cout << endl;
            break;
        }
        else
        {
            cout << "Invalid response" << endl; //accounts for invalid input other than "y" or "n" & returns to the top of the while loop
        }
    }
}

void bankAccount::deposit()
{
    string answer;
    double amount;
    while (true)
    {
        cout << "Balance: $" << balance << endl;
        cout << "Would you like to make a deposit? (Y or N): ";
        cin >> answer;
        //processes deposit
        if (answer == "Y" || answer == "y")
        {
            cout << "Deposit amount: $";
            cin >> amount;
            cin.clear();//lines 102 and 103 make sure the program does not endlessly loop with the same input
            cin.ignore(1000, '\n');
            balance += amount;
        }
        else if (answer == "N" || answer == "n")
        {
            cout << endl;
            break;
        }
        else
        {
            cout << "Invalid response" << endl;
        }
    }
}
