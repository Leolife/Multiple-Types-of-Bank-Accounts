#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "checkingAccount.h"
#include "serviceChargeChecking.h"

using namespace std;

serviceChargeChecking::serviceChargeChecking()
{
    monthlyServiceCharge = 0.0;
    checkLimitServiceCharge = 0.0;
    numberOfChecksWritten = 0;
}

double serviceChargeChecking::getAccountServiceCharge()
{
    return monthlyServiceCharge;
}
double serviceChargeChecking::getCheckLimitServiceCharge()
{
    return checkLimitServiceCharge;
}
int serviceChargeChecking::getNumberOfChecksWritten()
{
    return numberOfChecksWritten;
}

void serviceChargeChecking::setAccountServiceCharge(double charge)
{
    monthlyServiceCharge = charge;
}
void serviceChargeChecking::setChecksServiceCharge(double charge)
{
    checkLimitServiceCharge = charge;
}
void serviceChargeChecking::setNumberOfChecksWritten(int numOfChecks)
{
    numberOfChecksWritten = numOfChecks;
}

//assumes monthly charge has not been paid
void serviceChargeChecking::postServiceCharge()
{
    setAccountServiceCharge();

    cout << "\nYour monthly service charge of $" << getAccountServiceCharge() << " is due and will be subtracted automatically from your balance.\n" << endl;
    balance -= getAccountServiceCharge();//charges the monthly account service fee
}

void serviceChargeChecking::writeCheck()
{
    setNumberOfChecksWritten();
    setChecksServiceCharge();
    string answer, answer2;
    double amount;
    {
        while (true)
        {
            //writing a check to withdraw or deposit money
            cout << "\n -----\n|Check|\n -----\nCurrent Balance: $" << balance << "\nWould you like to make a withdrawal / deposit? (Y or N): ";
            cin >> answer;

            if (answer == "Y" || answer == "y")
            {
                //displays remaining available checks
                if (4 - getNumberOfChecksWritten() >= 0)
                    cout << "\nAfter completing this check, you can write " << 4 - getNumberOfChecksWritten() << " more checks this month before you are charged a service fee.\n"
                    << "Withdrawal or Deposit? (W or D): ";
                else if (4 - getNumberOfChecksWritten() < 0)
                {
                    cout << "You have exceeded your monthly check limit will be charged $" << getCheckLimitServiceCharge() << ".\n" << "Withdrawal or Deposit? (W or D): ";
                    balance -= getCheckLimitServiceCharge();//charges the service fee for exceeding monthly check limit
                }

                cin >> answer2;
                if (answer2 == "W" || answer2 == "w")
                {
                    cout << "Withdrawal amount: $";
                    cin >> amount;
                    cin.clear();//lines 90 and 91 make sure the program does not endlessly loop with the same input
                    cin.ignore(1000, '\n');
                    balance -= amount;
                    //prevents user from withdrawing more than they have in their account
                    if (balance < 0)
                    {
                        balance += amount;
                        cout << "Error: amount exceeds balance.\n";
                    }
                    else if (balance >= 0)
                    {
                        numberOfChecksWritten++;
                    }
                    else
                    {
                        cout << "Invalid response" << endl;
                    }
                }
                else if (answer2 == "D" || answer2 == "d")
                {
                    cout << "Deposit amount: $";
                    cin >> amount;
                    cin.clear();//lines 112 and 113 make sure the program does not endlessly loop with the same input
                    cin.ignore(1000, '\n');
                    balance += amount;
                    numberOfChecksWritten++;
                }
                else
                {
                    cout << "Invalid response" << endl;
                }
            }
            else if (answer == "N" || answer == "n")
            {
                //displays remaining available checks
                if (4 - getNumberOfChecksWritten() >= 0)
                {
                    cout << "\nYou can write " << 5 - getNumberOfChecksWritten() << " more checks this month before you are charged a service fee." << endl;
                }
                else if (4 - getNumberOfChecksWritten() < 0)
                {
                    cout << "\nYou have reached your monthly check limit and may have been charged for any extra checks written." << endl;
                }
                break;
            }
            else
            {
                cout << "Invalid response" << endl;
            }
        }
    }
}

void serviceChargeChecking::createMonthlyStatement()
{
    setName("Leo");//setting account name for all accounts to be my name as a sample
    setAccountNumber();
    //printing account details
    cout << setw(30) << "-------------------\n" << "|--------";
    cout << "| Monthly Statement |--------|" << endl;
    cout << setw(30) << "------------------- " << endl;
    cout << setw(27) << "Account holder: " << getName() << endl;
    cout << setw(27) << "Account number: " << getAccountNumber() << endl;
    cout << setw(28) << "Balance: $" << getBalance() << endl;
    cout << setw(31) << " Monthly service charge: PAID" << endl;
    cout << "|-------------------------------------|\n";
}

//prints the checks, any service charge that may occur, and the monthly statement
void serviceChargeChecking::print()
{
    cout << setw(44) << "---------------------------------\n" << "|--------";
    cout << "| Service Charge Checking Account |--------|" << endl;
    cout << setw(44) << "--------------------------------- " << endl;
    writeCheck();
    postServiceCharge();
    createMonthlyStatement();
}
