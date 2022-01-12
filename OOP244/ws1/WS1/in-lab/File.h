//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 5/26/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_FILE_H_ // replace with relevant names
#define SDDS_FILE_H_
#include "ShoppingRec.h"
namespace sdds
{
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);



}


#endif