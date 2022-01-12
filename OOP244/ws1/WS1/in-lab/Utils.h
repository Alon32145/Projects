//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 5/26/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_UTILS_H_ // replace with relevant names
#define SDDS_UTILS_H

namespace sdds
{
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);

}


#endif
