#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

class certificateOfDeposit : public bankAccount
{
private:
    double interestRate;
    int maturityMonths;//amount of months before user can withdraw money
    int cdMonths;//amount of months since initial deposit

public:
    certificateOfDeposit();

    ~certificateOfDeposit() {};

    double getInterestRate();

    int getMaturityMonths();

    int getCurrentCDMonth();

    void setInterestRate(double intRate = 5);

    void setMaturityMonths(int month = 6);

    void setCurrentCDMonth(int cmonth);

    void postInterest();

    //withdraw function with maturity month verification built in
    void withdraw() override;

    void createMonthlyStatement() override;

    void print();
};

