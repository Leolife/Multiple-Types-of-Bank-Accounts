#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "checkingAccount.h"
#include "noServiceChargeChecking.h"

using namespace std;

    noServiceChargeChecking::noServiceChargeChecking()
    {
        minimumBalance = 0.0;
        interestRate = 0.0;
    }
    noServiceChargeChecking::~noServiceChargeChecking() {};

    double noServiceChargeChecking::getMinimumBalance()
    {
        return minimumBalance;
    }
    double noServiceChargeChecking::getInterestRate()
    {
        return interestRate;
    }

    void noServiceChargeChecking::setMinimumBalance(double minBal)
    {
        minimumBalance = minBal;
    }
    void noServiceChargeChecking::setInterestRate(double intRate)
    {
        interestRate = intRate;
    }

    //write check function with the minimum balance verification built in
    void noServiceChargeChecking::writeCheck()
    {
        setMinimumBalance();
        string answer, answer1;
        double amount;
        {
            while (true)
            {
                //writing a check to withdraw or deposit money
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
                        cin.clear();//lines 62 and 63 make sure the program does not endlessly loop with the same input
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
                        cin.clear();//lines 75 and 76 make sure the program does not endlessly loop with the same input
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

    //withdraw function with the minimum balance verification built in
    void noServiceChargeChecking::withdraw()
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

    void noServiceChargeChecking::createMonthlyStatement()
    {
        setName("Leo");
        setAccountNumber();
        setInterestRate();
        //printing account details
        cout << setw(30) << "-------------------\n" << "|--------";
        cout << "| Monthly Statement |--------|" << endl;
        cout << setw(30) << "------------------- " << endl;
        cout << setw(27) << "Account holder: " << getName() << endl;
        cout << setw(27) << "Account number: " << getAccountNumber() << endl;
        cout << setw(28) << "Balance: $" << getBalance() << endl;
        cout << setw(28) << "Minimum required balance: $" << getMinimumBalance() << endl;
        cout << setw(27) << "Interest rate: " << getInterestRate() << "%" << endl;
        cout << "|-------------------------------------|\n";
    }

    void noServiceChargeChecking::print()
    {
        setMinimumBalance();
        cout << setw(47) << "------------------------------------\n" << "|--------";
        cout << "| No Service Charge Checking Account |--------|" << endl;
        cout << setw(47) << "------------------------------------ " << endl;
        cout << setw(37) << "MINIMUM BALANCE: $" << getMinimumBalance() << endl;
        writeCheck();
        createMonthlyStatement();
    }
