#pragma once
#include <iostream>
#include <string>
#include "bankAccount.h"

using namespace std;

//general checking account to build upon for other types of checking accounts
class checkingAccount : public bankAccount
{
public:
    checkingAccount();
    
    ~checkingAccount() {};

    //pure virtual check function to use later
    virtual void writeCheck() = 0;
};

