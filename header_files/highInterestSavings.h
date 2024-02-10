#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "savingsAccount.h"

using namespace std;

class highInterestSavings : public savingsAccount
{
protected:
    double minimumBalance;

public:
    highInterestSavings();

    ~highInterestSavings() {};

    double getMinimumBalance();
    
    double getInterestRate();

    void setMinimumBalance(double minBal = 50.0);

    void setInterestRate(double intRate = 0.06);

    //withdraw function with minimum balance verification built in
    virtual void withdraw();
    
    void showAccountInformation();

    virtual void print();
};
