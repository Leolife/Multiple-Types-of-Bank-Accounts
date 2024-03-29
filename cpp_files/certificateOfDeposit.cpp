#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "bankAccount.h"
#include "certificateOfDeposit.h"

using namespace std;

certificateOfDeposit::certificateOfDeposit()
{
    interestRate = 0.0;//YEARLY interest rate
    maturityMonths = 0;
    cdMonths = 0;
}

double certificateOfDeposit::getInterestRate()
{
    return interestRate;
}
int certificateOfDeposit::getMaturityMonths()
{
    return maturityMonths;
}
int certificateOfDeposit::getCurrentCDMonth()
{
    return cdMonths;
}

void certificateOfDeposit::setInterestRate(double intRate)
{
    interestRate = intRate;
}
void certificateOfDeposit::setMaturityMonths(int month)
{
    maturityMonths = month;
}
void certificateOfDeposit::setCurrentCDMonth(int cmonth)
{
    cdMonths = cmonth;
}

void certificateOfDeposit::postInterest()
{
    setInterestRate();
    cout << "Annual interest rate: " << getInterestRate() << "%" << endl;
}

//withdraw function with maturity month verification built in
void certificateOfDeposit::withdraw()
{
    string answer;
    double amount;
    bool firstLoop = false;
    bool secondLoop = false;
    setInterestRate();
    setMaturityMonths();
    setBalance(10000);//assumed initial balance for sake of this particular CD transaction scenaio

    cout << "Initial balance: $" << balance << endl;

    cout << "Amount of months it has been for your CD: ";
    cin >> cdMonths;
    balance = balance + (balance * ((cdMonths / static_cast<double>(12)) * (getInterestRate() / 100)));
    cin.clear();//lines 73 and 74 make sure the program does not endlessly loop with the same input
    cin.ignore(1000, '\n');
    if (cdMonths < 6)
    {
        cout << "Cannot withdraw until maturity month is reached. Maturity month: " << getMaturityMonths() << ".\n";
    }
    else if (cdMonths >= 6)
    {
        while (true)
        {
            cout << "\nCurrent balance (including interest): $" << fixed << setprecision(2) << balance << endl;
            cout << "Would you like to make a withdrawal? (Y or N): ";
            cin >> answer;

            if (answer == "Y" || answer == "y")
            {
                cout << "Withdrawal amount: $";
                cin >> amount;
                cin.clear();//lines 91 and 92 make sure the program does not endlessly loop with the same input
                cin.ignore(1000, '\n');
                balance -= amount;
                if (balance < 0)
                {
                    balance += amount;
                    cout << "\nError: amount exceeds balance" << endl;
                }
            }
            else if (answer == "N" || answer == "n")
            {
                cout << endl;
                break;
            }
            else
            {
                cout << "Invalid response" << endl;
            }
        }
    }
    else
    {
        cout << "Invalid response" << endl;
    }
}

void certificateOfDeposit::createMonthlyStatement()
{
    setName("Leo");
    setAccountNumber();
    setInterestRate();
    //printing account details
    cout << setw(30) << "-------------------\n" << "|--------";
    cout << "| Monthly Statement |--------|" << endl;
    cout << setw(30) << "------------------- " << endl;
    cout << setw(27) << "Account holder: " << getName() << endl;
    cout << setw(27) << "Account number: " << getAccountNumber() << endl;
    cout << setw(25) << "Current balance" << endl;
    cout << setw(28) << "(including interest): $" << balance << endl;
    cout << setw(5) << "";
    postInterest();
    cout << "|-------------------------------------|\n";
}

void certificateOfDeposit::print()
{
    cout << setw(35) << "------------------------\n" << "|--------";
    cout << "| Certificate of Deposit |--------|" << endl;
    cout << setw(35) << "------------------------ " << endl << endl;
    withdraw();
    createMonthlyStatement();
    cout << endl << endl;
}
