/*
    ==================================================
    Name   : Alon
    ID     : 109763201
    Email  : araigorodtesky@myseneca.ca
*/
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#define DATAFILE "employees.csv"
namespace sdds
{
    struct Employee
    {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();
    // loads a employee structue with its values from the file
    bool load(Employee& theEmployee);
    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load();


    void display(const Employee& theEmployee);

    void display();

    void deallocateMemory();

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:

    // TODO: Declare the prototype for the display function that 
    // first sorts the employees then displays all the employees on the screen

    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
}
#endif 