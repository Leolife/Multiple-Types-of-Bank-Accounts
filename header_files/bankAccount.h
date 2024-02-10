#pragma once
#include <iostream>
#include <string>

using namespace std;

//general bank account to build upon for other types of bank accounts
class bankAccount
{
protected:
    string name;
    int accountNumber;
    double balance;

public:
    bankAccount();

    ~bankAccount() {};

    string getName();

    int getAccountNumber();

    double getBalance();

    void setName(string n);

    void setAccountNumber(); //static account number generator, sets account numbers for all types of accounts- FIX

    void setBalance(double bal);

    virtual void withdraw();

    void deposit();

    //pure virtual monthly statement function to use later
    virtual void createMonthlyStatement() = 0;
};

