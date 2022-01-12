//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 06/08/2021
//email: araigorodetsky@myseneca.ca

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}
	bool Bill::isValid() const
	{
		bool valid = m_items != nullptr && m_title != 0;
		for (int i = 0; valid && i < m_noOfItems; i++)
		{
			valid = m_items[i].isValid();
		}
		return valid;
	}
	double Bill::totalTax()const
	{
		double tax = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			tax += m_items[i].tax();
		}
		return tax;
	}
	double Bill::totalPrice()const
	{
		double price = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			price += m_items[i].price();
		}
		return price;
	}

	void Bill::Title()const
	{
		cout << "+--------------------------------------+\n";
		if (isValid())
		{
			cout << "| ";
			cout.width(36);
			cout.fill(' ');
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |\n";

		}
		else
		{
			cout << "| Invalid Bill                         |\n";

		}
		cout << "+----------------------+---------+-----+\n";
		cout << "| Item Name            | Price   + Tax |\n";
		cout << "+----------------------+---------+-----+\n";
	}
	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+\n";
		if (isValid())
		{
			double tax = totalTax();
			double price = totalPrice();
			cout << "|                Total Tax: ";
			cout.setf(ios::fixed);
			cout.setf(ios::right);
			cout.precision(2);
			cout.fill(' ');
			cout.width(10);
			cout << tax << " |\n";
			cout << "|              Total Price: ";
			cout.width(10);
			cout << price << " |\n";
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << price + tax << " |\n";
			cout.unsetf(ios::right);
		}
		else
		{
			cout << "| Invalid Bill                         |\n";
		}
		cout << "+--------------------------------------+\n";
	}
	void Bill::init(const char* title, int noOfItems)
	{
		if (title != nullptr  && noOfItems > 0)
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title , title, 36);
			m_items = new Item[noOfItems];
			for (int i = 0; i < noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
		else
		{
			setEmpty();
		}
		
	}
	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool success = false;
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded++].set(item_name, price, taxed);
			success = true;
		}
		return success;
	}
	void Bill::display()const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}
	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}