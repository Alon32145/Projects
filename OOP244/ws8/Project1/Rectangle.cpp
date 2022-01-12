//Name:
//ID:
//Email:
//Date:
//section
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle()
	{

	}
	Rectangle::Rectangle(const char* label, int width, int height):
		LblShape(label), m_width(width), m_height(height)
	{
		if ((m_height < 3) || (m_width < int(strlen(label) + 2)))
		{
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');
	}
	void Rectangle::draw(std::ostream& os) const
	{
		if (m_height > 0)
		{
			os << "+" << setw(m_width - 2) << setfill('-') << '-' << '+' << endl;
			os << "|" << setw(m_width - 2) << setfill(' ') << left << label() << '|' << endl;
			for (int i = 0; i < m_height -3; i++)
			{
				os << "|" << setw(m_width - 2) << setfill(' ') << ' ' << '|' << endl;
			}
			os << "+" << setw(m_width - 2) << setfill('-')<< '-' << '+' ;
		}
	}
}