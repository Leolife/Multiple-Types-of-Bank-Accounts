#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "highInterestChecking.h"
#include "noServiceChargeChecking.h"

using namespace std;

highInterestChecking::highInterestChecking()
{
    minimumBalance = 0.0;
    interestRate = 0.0;
}
highInterestChecking::~highInterestChecking() {};

double highInterestChecking::getInterestRate()
{
    return interestRate;
}
double highInterestChecking::getMinimumBalance()
{
    return minimumBalance;
}

void highInterestChecking::setInterestRate(double intRate)
{
    interestRate = intRate;
}
void highInterestChecking::setMinimumBalance(double minBal)
{
    minimumBalance = minBal;
}

void highInterestChecking::postInterest()
{
    setInterestRate();
    cout << "Interest rate: " << getInterestRate() << "%" << endl;
}

//write check with minimum balance verification built in
void highInterestChecking::writeCheck()
{
    setMinimumBalance();
    string answer, answer1;
    double amount;
    {
        while (true)
        {
            cout << "\n -----\n|Check|\n -----\nCurrent Balance: $" << balance << "\nWould you like to make a withdrawal / deposit? (Y or N): ";
            cin >> answer;

            if (answer == "Y" || answer == "y")
            {
                cout << "Withdrawal or Deposit? (W or D): ";
                cin >> answer1;
                if (answer1 == "W" || answer1 == "w")
                {
                    cout << "Withdrawal amount: $";
                    cin >> amount;
                    cin.clear();//lines 64 and 65 make sure the program does not endlessly loop with the same input
                    cin.ignore(1000, '\n');
                    balance -= amount;
                    if (balance < getMinimumBalance())
                    {
                        balance += amount;
                        cout << "Error: balance cannot fall under minimum required balance.\n";
                    }
                }
                else if (answer1 == "D" || answer1 == "d")
                {
                    cout << "Deposit amount: $";
                    cin >> amount;
                    cin.clear();//lines 76 and 77 make sure the program does not endlessly loop with the same input
                    cin.ignore(1000, '\n');
                    balance += amount;
                }
                else
                {
                    cout << "Invalid response" << endl;
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
}

void highInterestChecking::createMonthlyStatement()
{
    setName("Leo");
    setAccountNumber();
    setInterestRate();
    setMinimumBalance();
    //printing account details
    cout << setw(30) << "-------------------\n" << "|--------";
    cout << "| Monthly Statement |--------|" << endl;
    cout << setw(30) << "------------------- " << endl;
    cout << setw(27) << "Account holder: " << getName() << endl;
    cout << setw(27) << "Account number: " << getAccountNumber() << endl;
    cout << setw(28) << "Balance: $" << getBalance() << endl;
    cout << setw(28) << "Minimum required balance: $" << getMinimumBalance() << endl;
    cout << setw(12) << "";
    postInterest();
    cout << "|-------------------------------------|\n";
}

void highInterestChecking::print()
{
    setMinimumBalance();
    cout << setw(43) << "--------------------------------\n" << "|--------";
    cout << "| High Interest Checking Account |--------|" << endl;
    cout << setw(43) << "-------------------------------- " << endl;
    cout << setw(33) << "MINIMUM BALANCE: $" << getMinimumBalance() << endl;
    writeCheck();
    createMonthlyStatement();
}
