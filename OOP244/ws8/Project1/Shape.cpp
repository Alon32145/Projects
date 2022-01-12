
#include "Shape.h"
namespace sdds {
	std::ostream& operator << (std::ostream& os, const Shape& S)
	{
		S.draw(os);
		return os;
	}
	std::istream& operator >> (std::istream& is, Shape& S)
	{
		S.getSpecs(is);
		return is;
	}
}