#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "noServiceChargeChecking.h"

using namespace std;

class highInterestChecking : public noServiceChargeChecking
{
public:
    highInterestChecking();

    ~highInterestChecking() {};

    double getInterestRate();

    double getMinimumBalance();

    void setInterestRate(double intRate = 0.05);

    void setMinimumBalance(double minBal = 100.0);

    void postInterest();

    //write check with minimum balance verification built in
    void writeCheck() override;
        
    void createMonthlyStatement() override;

    virtual void print();
};

