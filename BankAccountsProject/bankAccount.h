#pragma once
#include <iostream>
#include <string>

using namespace std;

//general bank account to build upon for other types of bank accounts
class bankAccount
{
protected:
    string name;
    int accountNumber;
    double balance;

public:
    bankAccount()
    {
        name = "N/A";
        accountNumber = 0;
        balance = 100.0;
    }
    ~bankAccount() {};

    string getName()
    {
        return name;
    }
    int getAccountNumber()
    {
        return accountNumber;//returns account number
    }
    double getBalance()
    {
        return balance;
    }

    void setName(string n)
    {
        name = n;
    }
    void setAccountNumber() //static account number generator, sets account numbers for all types of accounts- FIX
    {
        static int acctNumber = 100;
        accountNumber = acctNumber;
        acctNumber++;
    }
    void setBalance(double bal)
    {
        balance = bal;
    }

    virtual void withdraw()
    {
        string answer;
        double amount;
        while (true)
        {
            cout << "Balance: $" << balance << endl;
            cout << "Would you like to make a withdrawal? (Y or N): ";
            cin >> answer;
            //processes withdrawal
            if (answer == "Y" || answer == "y")
            {
                cout << "Withdrawal amount: $";
                cin >> amount;
                balance -= amount;
                //prevents user from withdrawing more than they have in their account
                if (balance < 0)
                {
                    balance += amount;
                    cout << "Error: amount exceeds balance.\n";
                }
            }
            else if (answer == "N" || answer == "n")
            {
                cout << endl;
                break;
            }
            else
            {
                cout << "Invalid response" << endl; //accounts for invalid input other than "y" or "n" & returns to the top of the while loop
            }
        }
    }

    void deposit()
    {
        string answer;
        double amount;
        while (true)
        {
            cout << "Balance: $" << balance << endl;
            cout << "Would you like to make a deposit? (Y or N): ";
            cin >> answer;
            //processes deposit
            if (answer == "Y" || answer == "y")
            {
                cout << "Deposit amount: $";
                cin >> amount;
                balance += amount;
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

    //pure virtual monthly statement function to use later
    virtual void createMonthlyStatement() = 0;
};

