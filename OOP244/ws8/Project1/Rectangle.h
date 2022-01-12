

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {

	class Rectangle : public LblShape
	{
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle();
		Rectangle(const char* label, int m_width, int m_height);
		void getSpecs(std::istream&);
		void draw(std::ostream&) const;
	};
}
#endif