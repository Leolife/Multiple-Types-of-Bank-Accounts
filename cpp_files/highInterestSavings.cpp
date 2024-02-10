#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestSavings.h"
#include "savingsAccount.h"

using namespace std;

highInterestSavings::highInterestSavings()
{
    minimumBalance = 0.0;
}

double highInterestSavings::getMinimumBalance()
{
    return minimumBalance;
}
double highInterestSavings::getInterestRate()
{
    return interestRate;
}

void highInterestSavings::setMinimumBalance(double minBal)
{
    minimumBalance = minBal;
}
void highInterestSavings::setInterestRate(double intRate)
{
    interestRate = intRate;
}

//withdraw function with minimum balance verification built in
void highInterestSavings::withdraw()
{
    string answer;
    double amount;
    setMinimumBalance();

    while (true)
    {
        cout << "Balance: $" << balance << endl;
        cout << "Would you like to make a withdrawal? (Y or N): ";
        cin >> answer;

        if (answer == "Y" || answer == "y")
        {
            cout << "Withdrawal amount: $";
            cin >> amount;
            cin.clear();//lines 56 and 57 make sure the program does not endlessly loop with the same input
            cin.ignore(1000, '\n');
            balance -= amount;
            if (balance < getMinimumBalance())
            {
                balance += amount;
                cout << "Error: balance cannot fall under minimum required balance.\n";
            }
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

void highInterestSavings::showAccountInformation()
{
    setName("Leo");
    setAccountNumber();
    setInterestRate();
    //printing account details
    cout << "\n -------------------------------------------\n| High Interest Savings Account Information |\n -------------------------------------------\n";
    cout << setw(27) << "Account holder: " << getName() << endl;
    cout << setw(27) << "Account number: " << getAccountNumber() << endl;
    cout << setw(28) << "Balance: $" << getBalance() << endl;
    cout << setw(27) << "Interest rate: " << getInterestRate() << "%" << endl;
    cout << "|-------------------------------------------|\n";
}

void highInterestSavings::print()
{
    setMinimumBalance();
    cout << setw(42) << "-------------------------------\n" << "|--------";
    cout << "| High Interest Savings Account |--------|" << endl;
    cout << setw(42) << "------------------------------- " << endl;
    cout << setw(34) << "MINIMUM BALANCE: $" << getMinimumBalance() << endl << endl;
    deposit();
    withdraw();
    showAccountInformation();
}

