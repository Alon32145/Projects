//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/29/2021
//email: araigorodetsky@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
  
   
    Mark::Mark() {
        marks = 0;
    }
    Mark::Mark(int grade)
    {
       
            marks = grade;
        
    }
    Mark::operator int()
    {
        if (marks >= 0 && marks <= 100)
        {
            return marks;
        }
        else
        {
            return 0;
        }
    }
    Mark& Mark::operator+=(int grade)
    {
       
            marks += grade;
 
        return *this;
    }
    Mark& Mark::operator==(int grade)
    {
        marks = grade;

        return *this;
    }
    Mark::operator double()
    {
        if (0 <= marks && marks < 50)
        {
            
           
            return 0;
        }
        else if(50 <= marks && marks < 60)
        {
            
            return 1;
        }
        else if (60 <= marks && marks < 70)
        {
            
            return 2;
        }
        else if (70 <= marks && marks < 80)
        {
            
            return 3;
        }
        else if (80 <= marks && marks < 100)
        {
            
            return 4;
        }
        else
        {
           
            return 0;
        }

    }
    Mark::operator char()
    {
        if (0 <= marks && marks < 50)
        {


            return 'F';
        }
        else if (50 <= marks && marks < 60)
        {

            return 'D';
        }
        else if (60 <= marks && marks < 70)
        {

            return 'C';
        }
        else if (70 <= marks && marks < 80)
        {

            return 'B';
        }
        else if (80 <= marks && marks < 100)
        {

            return 'A';
        }
        else
        {

            return 'X';
        }
    }
    int operator+=(int& leftside, const Mark& rightside)
    {
        if (rightside.marks >= 0 && rightside.marks <= 100)
        {
        leftside += rightside.marks;
           
        }
        return leftside;
        
    }

}