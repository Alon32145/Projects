//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 06/13/2021
//email: araigorodetsky@myseneca.ca

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
	void CalorieList::setEmpty()
	{
		
		m_foods = nullptr;
	}
	bool CalorieList::isValid()const
	{
		bool valid = m_foods != nullptr ;
		for (int i = 0; valid && i < m_noOfItems; i++)
		{
			valid = m_foods[i].isValid();
		}
		return valid;
	}
	int CalorieList::totalCalories()const
	{
		int calories = 0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			calories += m_foods[i].calories();
		}
		return calories;
	}
	

	void CalorieList::Title()const
	{
		cout << "+----------------------------------------------------+\n";
		if (isValid())
		{
			cout.width(35);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << "|  Daily Calorie Consumption                         |\n";
			cout.unsetf(ios::left);

		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |\n";

		}
		cout << "+--------------------------------+------+------------+\n";
		cout << "| Food name                      | Cals | When       |\n";
		cout << "+--------------------------------+------+------------+\n";
	}
	void CalorieList::footer()const
	{
		cout << "+--------------------------------+------+------------+\n";
		if (isValid())
		{
			int calories = totalCalories();
			
			cout << "|    Total Calories for today:";
			cout.setf(ios::fixed);
			cout.setf(ios::right);
			cout.precision(2);
			cout.fill(' ');
			cout.width(9);
			cout << calories << " |            |\n";
			
		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |\n";
		}
		cout << "+----------------------------------------------------+\n";
	}
	void CalorieList::init(int noOfItems)
	{
		if (noOfItems > 0)
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			
			m_foods = new Food[noOfItems];
			for (int i = 0; i < noOfItems; i++)
			{
				m_foods[i].setEmpty();
			}
		}
		else
		{
			setEmpty();
		}

	}
	bool CalorieList::add(const char* food_Name, int calories, int time)
	{
		bool success = false;
		if (m_itemsAdded < m_noOfItems)
		{
			m_foods[m_itemsAdded++].set(food_Name, calories, time);
			success = true;
		}
		return success;
	}
	void CalorieList::display()const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_foods[i].display();
		}
		footer();
	}
	void CalorieList::deallocate()
	{
		delete[] m_foods;
		m_foods = nullptr;
	}
}