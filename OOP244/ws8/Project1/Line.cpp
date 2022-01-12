
#include "Line.h"
#include <iomanip>
using namespace std;
namespace sdds {
	Line::Line() : m_length(0)
	{

	}
	Line::Line(const char* label, int length) : LblShape(label), m_length(length)
	{
		
	}
	void Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label() != nullptr)
		{
			os << label() << endl;
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	}
}
