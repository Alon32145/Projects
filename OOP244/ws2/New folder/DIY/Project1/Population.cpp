//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/6/2021
//email: araigorodetsky@myseneca.ca

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"
using namespace std;
namespace sdds {

	
	Population* postalcode;
	int dataSize = 0;

	void sort()
	{
		int i, j;
		Population transition;
		for (i = dataSize - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (postalcode[j].population > postalcode[j + 1].population)
				{
					transition = postalcode[j];
					postalcode[j] = postalcode[j + 1];
					postalcode[j + 1] = transition;
				}
			}
		}
	}

	void display(const Population& population)
	{
		cout << population.postalCode << ":  " <<
			population.population << endl;
	}

	void display()
	{
		int totalPop = 0;
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort();
		for (int i = 0; i < dataSize; i++)
		{
			totalPop += postalcode[i].population;
			cout << i + 1 << "- ";
			display(postalcode[i]);
			
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPop << endl;
	}

	bool load(Population& population)
	{
		bool ok = false;
		char postalCodeNum[5];
		if (read(postalCodeNum) && read(population.population))
		{
			population.postalCode = new char[strLen(postalCodeNum) + 1];
			strCpy(population.postalCode, postalCodeNum);
			ok = true;
		}
		return ok;
	}

	bool load(const char filename[])
	{
		
		int i = 0;
		bool ok = false;
		if (openFile(filename))
		{
			dataSize = noOfRecords();
			postalcode = new Population[dataSize];
			for (i = 0; i < dataSize && load(postalcode[i]); i++);


			if (i == dataSize + 1)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
			}
			else
				ok = true;
			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
		}
		return ok;
	}

	void deallocateMemory()
	{
		for (int i = 0; i < dataSize; i++)
		{
			delete[] postalcode[i].postalCode;
		}
		delete[] postalcode;
	}
}