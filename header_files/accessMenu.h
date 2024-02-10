#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "serviceChargeChecking.h"
#include "noServiceChargeChecking.h"
#include "highInterestChecking.h"
#include "savingsAccount.h"
#include "highInterestSavings.h"
#include "certificateOfDeposit.h"

using namespace std;

//menu class to print a menu for the user to choose which bank account to operate
class accessMenu
{
public:
    void menu();
};

