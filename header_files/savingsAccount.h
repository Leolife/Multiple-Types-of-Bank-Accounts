#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

class savingsAccount : public bankAccount
{
protected:
    double interestRate;

public:
    savingsAccount()
    {
        interestRate = 0.0;
    }
    ~savingsAccount() {};

    double getInterestRate()
    {
        return interestRate;
    }

    void setInterestRate(double intRate = 0.03)
    {
        interestRate = intRate;
    }

    void postInterest()
    {
        setInterestRate();
        cout << "Interest rate: " << getInterestRate() << "%" << endl;
    }

    virtual void createMonthlyStatement()
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
        cout << setw(12) << "";
        postInterest();
        cout << "|-------------------------------------|\n";
    }

    virtual void print()
    {
        cout << setw(28) << "-----------------\n" << "|--------";
        cout << "| Savings Account |--------|" << endl;
        cout << setw(28) << "----------------- " << endl << endl;
        deposit();
        withdraw();
        createMonthlyStatement();
    }
};

