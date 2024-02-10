#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "checkingAccount.h"

using namespace std;

class serviceChargeChecking : public checkingAccount
{
protected:
    double monthlyServiceCharge;
    double checkLimitServiceCharge;//applies a service charge if amount of checks written exceeds monthly limit
    int numberOfChecksWritten;

public:
    serviceChargeChecking();

    ~serviceChargeChecking() {};

    double getAccountServiceCharge();

    double getCheckLimitServiceCharge();

    int getNumberOfChecksWritten();

    void setAccountServiceCharge(double charge = 10.00);

    void setChecksServiceCharge(double charge = 5.00);

    void setNumberOfChecksWritten(int numOfChecks = 0);

    //assumes monthly charge has not been paid
    void postServiceCharge();

    void writeCheck() override;

    virtual void createMonthlyStatement();

    //prints the checks, any service charge that may occur, and the monthly statement
    virtual void print();
};

