//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 5/26/2021
//email: araigorodetsky@myseneca.ca
#ifndef SDDS_SHOPPINGREC_H_ // replace with relevant names
#define SDDS_SHOPPINGREC_H_

namespace sdds
{
	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;
	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
	
	

}


#endif

