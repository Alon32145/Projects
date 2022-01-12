// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/14

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_

namespace sdds {
   //search
	template<typename CT, typename KT>
	bool search(Collection<CT>& C,CT * A, int size, KT key)
	{
		bool res = false;
		for (int i = 0; i < size; i++)
		{
			if (A[i] == key)
			{
				C.add(A[i]);
				res = true;
			}
		}
		return res;
	}

	template<typename T>
	void listArrayElements(const char* Title, T* A, int size )
	{
		std::cout << Title << std::endl;

		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << ": " << A[i] << std::endl;
			
		}
	}
	
}
#endif // !SDDS_SEARCHNLIST_H_