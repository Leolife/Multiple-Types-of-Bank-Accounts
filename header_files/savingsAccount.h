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
    savingsAccount();

    ~savingsAccount() {};

    double getInterestRate();

    void setInterestRate(double intRate = 0.03);

    void postInterest();

    virtual void createMonthlyStatement();

    virtual void print();
};
