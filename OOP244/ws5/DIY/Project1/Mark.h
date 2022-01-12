//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/29/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
    public:
        int marks;
        Mark();
        Mark(int grade);
        operator int();
        Mark& operator+=(int grade);
        Mark& operator==(int grade);
        operator double();
        operator char();

        
    };
    int operator+=(int& leftside, const Mark& rightside);
}
#endif // SDDS_MARK_H_