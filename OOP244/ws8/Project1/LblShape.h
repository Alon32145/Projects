

#ifndef SDDS_LABELEDSHAPE_H
#define SDDS_LABELEDSHAPE_H
#include "Shape.h"
namespace sdds {

	class LblShape : public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape&) = delete;
		void operator = (const LblShape&) = delete;
		void getSpecs(std::istream& is);
	};

}
#endif