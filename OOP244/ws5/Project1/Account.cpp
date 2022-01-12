//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/22/2021
//email: araigorodetsky@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const
    {
        return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
    }

    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }
    bool Account::operator~() const
    {
        return m_number == 0;
    }

    Account& Account::operator=(int number)
    {
        if (~*this) // newaccount
        {
            if (number >= 10000 && number <= 99999)
            {
                m_number = number;
            }
            else
            {
                setEmpty();
            }
            
        }
        return *this;
    }
    Account& Account::operator=(Account& RA)
    {
        if (~*this && RA)
        {
            m_number = RA.m_number;
            m_balance = RA.m_balance;
            RA.m_number = 0;
            RA.m_balance = 0.0;
        }
        return *this;
    }
    Account& Account::operator+=(double val)
    {
        if (*this && val >= 0)
        {
            m_balance += val;
        }
        return *this;
    }

    Account& Account::operator-=(double val)
    {
        if (*this && val >= 0 && val <= m_balance)
        {
            m_balance -= val;
        }
        return *this;
    }
    Account& Account::operator<<(Account& RA)
    {
        if (this!=&RA && *this && RA)
        {
            m_balance += RA.m_balance;
            RA.m_balance = 0.0;
        }
        return *this;
    }
    Account& Account::operator>>(Account& RA)
    {
        if (this != &RA && *this && RA)
        {
            RA.m_balance += m_balance;
            m_balance = 0.0;
        }
        return *this;
    }
    double operator+(const Account& leftside, const Account& rightside)
    {
        double r = 0;
        if (leftside && rightside)
        {
            r = (double(leftside) + double(rightside));
           
        }
        return r;
    }

    double operator+=(double& leftside, const Account& rightside)
    {
        leftside += double(rightside);
        return leftside;
       
    }
};
