//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/20/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_LABEL_H 
#define SDDS_LABEL_H
#include <iostream>
#include "LabelMaker.h"
using namespace std;
namespace sdds
{
	class Label
	{
	private:
		char *title;
		char *text;
	public:
		Label(const char* frameArg, const char* content);
		Label(const char* frameArg);
		Label();
		~Label();
		std::ostream& printLabel() const;
		void setTitle(const char* frame_base);
		void setText(const char* text_base);
	};
}
#endif