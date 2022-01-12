/*
	==================================================
	Name   : Alon
	ID     : 109763201
	Email  : araigorodtesky@myseneca.ca
*/


#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "File.h"
#include "Employee.h"
using namespace std;

namespace sdds
{

	int noOfEmployees;
	Employee* employees;


	void sort()
	{
		int i, j;
		Employee temp;
		for (i = noOfEmployees - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (employees[j].m_empNo > employees[j + 1].m_empNo)
				{
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	// TODO: Finish the implementation of the 1 arg load function which
	// reads one employee record from the file and loads it into the employee reference
	// argument
	bool load(Employee& theEmployee)
	{
		bool ok = false;
		char name[128];
		if (read(theEmployee.m_empNo)
			&& read(theEmployee.m_salary)
			&& read(name))
		{
			theEmployee.m_name = new char[strLen(name) + 1];
			strCpy(theEmployee.m_name, name);
			ok = true;
		}
		return ok;
	}
	// TODO: Finish the implementation of the 0 arg load function 
	bool load()
	{
		bool ok = false;
		int i = 0;
		if (openFile(DATAFILE))
		{
			noOfEmployees = noOfRecords();
			employees = new Employee[noOfEmployees];
			for (i = 0; i < noOfEmployees && load(employees[i]); i++);

			if (i == noOfEmployees + 1)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
			}
			else
				ok = true;
			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << DATAFILE << endl;
		}
		return ok;
	}

	void display(const Employee& theEmployee)
	{
		cout << theEmployee.m_empNo << ": " <<
			theEmployee.m_name << ", " <<
			theEmployee.m_salary << endl;
	}
	// TODO: Implementation for the display functions go here

	void display()
	{
		cout << "Employee Salary report, sorted by employee number" << endl;
		cout << "no- Empno, Name, Salary" << endl;
		cout << "------------------------------------------------" << endl;
		sort();
		for (int i = 0; i < noOfEmployees; i++)
		{
			cout << i + 1 << "- ";
			display(employees[i]);
		}
	}

	void deallocateMemory()
	{
		for (int i = 0; i < noOfEmployees; i++)
		{
			delete[] employees[i].m_name;
		}
		delete[] employees;
	}
}