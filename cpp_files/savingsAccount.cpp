#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccount.h"
#include "savingsAccount.h"

using namespace std;

savingsAccount::savingsAccount()
{
    interestRate = 0.0;
}
savingsAccount::~savingsAccount() {};

double savingsAccount::getInterestRate()
{
    return interestRate;
}

void savingsAccount::setInterestRate(double intRate)
{
    interestRate = intRate;
}

void savingsAccount::postInterest()
{
    setInterestRate();
    cout << "Interest rate: " << getInterestRate() << "%" << endl;
}

void savingsAccount::createMonthlyStatement()
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

void savingsAccount::print()
{
    cout << setw(28) << "-----------------\n" << "|--------";
    cout << "| Savings Account |--------|" << endl;
    cout << setw(28) << "----------------- " << endl << endl;
    deposit();
    withdraw();
    createMonthlyStatement();
}
