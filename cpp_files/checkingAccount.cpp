#pragma once
#include <iostream>
#include <string>
#include "bankAccount.h"
#include "checkingAccount.h"

using namespace std;

//general checking account to build upon for other types of checking accounts
checkingAccount::checkingAccount()
{
    name = "N/A";
    accountNumber = 0;
    balance = 100.0;
}
checkingAccount::~checkingAccount() {};
