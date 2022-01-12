//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/22/2021
//email: araigorodetsky@myseneca.ca
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator~() const;
        Account& operator=(int number);
        Account& operator=(Account& RA);
        Account& operator+=(double val);
        Account& operator-=(double val);
        Account& operator<<(Account& RA);
        Account& operator>>(Account& RA);
    };
   double operator+(const Account& leftside, const Account& rightside);
   double operator+=(double& leftside, const Account& rightside);
}
#endif // SDDS_ACCOUNT_H_