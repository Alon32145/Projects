//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/20/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_LABELMAKER_H 
#define SDDS_LABELMAKER_H
#include <iostream>
using namespace std;

namespace sdds
{
	class LabelMaker
	{
	private:
		char** Labels;
		int noLabels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif 