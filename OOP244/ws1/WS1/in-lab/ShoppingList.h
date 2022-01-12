//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 5/26/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_SHOPPINGLIST_H_ // replace with relevant names
#define SDDS_SHOPPINGLIST_H_

namespace sdds
{
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}


#endif