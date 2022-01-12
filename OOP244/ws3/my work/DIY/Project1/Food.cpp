//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 06/13/2021
//email: araigorodetsky@myseneca.ca

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

const double c_tax = 0.13;
namespace sdds {
	
	void Food::setName(const char* name)
	{
		strnCpy(m_foodName, name, 30);
		m_foodName[30] = 0; // '\0'
	}
	void Food::setEmpty()
	{
		m_foodName[0] = '\0';
		m_calories = 0;
		m_time = 0;
	}
	void Food::set(const char* name, int calorie, int time)
	{

		if (calorie <= 0 || name == nullptr || calorie >= 3001 || time  <= 0 || time >= 5)
		{
			setEmpty();
		}
		else
		{
			setName(name);
			m_calories = calorie;
			m_time = time;
		}

	}
	int Food::calories()const
	{
		return m_calories;
	}
	int Food::time()const
	{

		return m_time;
	}
	bool Food::isValid()const
	{

		return m_foodName[0] != 0;
	}

	void Food::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.width(30);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_foodName;
			cout.unsetf(ios::left);

			cout << " | ";

			cout.width(4);
			cout.setf(ios::right);
			cout.fill(' ');
			cout.setf(ios::fixed);
			//cout.precision(2);
			cout << m_calories;
			cout.unsetf(ios::right);

			cout << " | ";

			if (m_time == 1)
			{
				cout << "Breakfast";
				cout.width(3);
				//cout.setf(ios::right);
			}
			else if (m_time == 2)
			{
				cout << "Lunch";
				cout.width(7);
				//cout.setf(ios::right);
			}
			else if (m_time == 3)
			{
				cout << "Dinner";
				cout.width(6);
				//cout.setf(ios::right);
			}
			else if (m_time == 4)
			{
				cout << "Snack";
				cout.width(7);
				//cout.setf(ios::right);
			};

			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |\n";
		}
	}
}