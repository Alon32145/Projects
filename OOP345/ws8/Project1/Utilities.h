//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 19/11/2021
//email: araigorodetsky@myseneca.ca


//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


// include files
#include "List.h"
#include "Element.h"

namespace sdds {
	
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif // SDDS_UTILITIES_H
