#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeChecking.h"

using namespace std;

class highInterestChecking : public noServiceChargeChecking
{
public:
    highInterestChecking()
    {
        minimumBalance = 0.0;
        interestRate = 0.0;
    }
    ~highInterestChecking() {};

    double getInterestRate()
    {
        return interestRate;
    }
    double getMinimumBalance()
    {
        return minimumBalance;
    }

    void setInterestRate(double intRate = 0.05)
    {
        interestRate = intRate;
    }
    void setMinimumBalance(double minBal = 100)
    {
        minimumBalance = minBal;
    }

    void postInterest()
    {
        setInterestRate();
        cout << "Interest rate: " << getInterestRate() << "%" << endl;
    }

    //write check with minimum balance verification built in
    void writeCheck() override
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

    void createMonthlyStatement() override
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

    virtual void print()
    {
        setMinimumBalance();
        cout << setw(43) << "--------------------------------\n" << "|--------";
        cout << "| High Interest Checking Account |--------|" << endl;
        cout << setw(43) << "-------------------------------- " << endl;
        cout << setw(33) << "MINIMUM BALANCE: $" << getMinimumBalance() << endl;
        writeCheck();
        createMonthlyStatement();
    }
};

