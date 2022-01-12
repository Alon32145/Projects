//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 06/13/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        //char m_title[37];
        Food* m_foods;
        int m_noOfItems;
        int m_itemsAdded;
        int totalCalories()const;
        void Title()const;
        void footer()const; // will print totalCalroies
        void setEmpty();
        bool isValid()const;
    public:
        void init( int noOfItems);
        bool add(const char* food_Name, int calories, int time);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
