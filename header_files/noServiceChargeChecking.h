#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "checkingAccount.h"

using namespace std;

class noServiceChargeChecking : public checkingAccount
{
protected:
    double minimumBalance;
    double interestRate;

public:
    noServiceChargeChecking();

    ~noServiceChargeChecking() {};

    double getMinimumBalance();

    double getInterestRate();

    void setMinimumBalance(double minBal = 50.0);
    
    void setInterestRate(double intRate = 0.01);

    //write check function with the minimum balance verification built in
    void writeCheck() override;

    //withdraw function with the minimum balance verification built in
    void withdraw() override;

    virtual void createMonthlyStatement();

    virtual void print();
};
