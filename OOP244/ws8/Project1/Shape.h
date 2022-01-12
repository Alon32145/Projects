

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
	class Shape
	{
	public:
		virtual void draw(std::ostream&) const = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape(){}
    };
	std::ostream& operator << (std::ostream& os, const Shape& S);
	std::istream& operator >> (std::istream& is, Shape& S);
}

#endif // !SDDS_SHAPE_H

