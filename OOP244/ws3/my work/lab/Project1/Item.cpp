//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 06/08/2021
//email: araigorodetsky@myseneca.ca

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;

const double c_tax = 0.13;
namespace sdds {
	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = 0; // '\0'
	}
	void Item::setEmpty()
	{
		m_itemName[0] = '\0';
		m_price = 0.0;
	}
	void Item::set(const char* name, double price, bool taxed)
	{
		
		if (price <= 0.0 || name == nullptr)
		{
			setEmpty();
		}
		else
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		
	}
	double Item::price()const
	{
		return m_price;
	}
	double Item::tax()const
	{
		
			return m_price * c_tax *m_taxed;
	}
	bool Item::isValid()const
	{
	
		return m_itemName[0] != 0;
	}

	void Item::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.width(20);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_itemName;
			cout.unsetf(ios::left);

			cout  << " | ";

			cout.width(7);
			cout.setf(ios::right);
			cout.fill(' ');
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;
			cout.unsetf(ios::right);

			cout  << " | ";

			cout << (m_taxed ? "Yes" : "No ");

			cout << " |" <<endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |\n";
		}
	}
}