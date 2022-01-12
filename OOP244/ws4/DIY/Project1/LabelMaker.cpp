//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/20/2021
//email: araigorodetsky@myseneca.ca

#include "LabelMaker.h"
#include "Label.h"
#include "cstring.h"

namespace sdds
{

	LabelMaker::LabelMaker(int noOfLabels)
	{
		
		Labels = new char* [noOfLabels];
		noLabels = noOfLabels;
	}

	void LabelMaker::readLabels()
	{
		char word[71];
		cout << "Enter " << noLabels << " labels:" << endl;
		for (int i = 0; i < noLabels; i++)
		{
			cout << "Enter label number " << i + 1 << endl << "> ";
			cin.getline(word, 71);
			Labels[i] = new char[(strLen(word)) + 1];
			strCpy(Labels[i], word);
		}
	}

	void LabelMaker::printLabels()
	{
		
		int length_horizontal = 0;
		char frame[9] = "+-+|+-+|";
		for (int i = 0; i < noLabels; i++)
		{
			
			length_horizontal = strLen(Labels[i]) + 3;
			cout << frame[0];
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(frame[1]);
			cout.unsetf(ios::left);
			cout << frame[2] << endl;

			
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(' ');
			cout << frame[7];
			cout.unsetf(ios::left);
			cout << frame[3] << endl;

			
			cout.width(2);
			cout.setf(ios::left);
			cout.fill(' ');
			cout << frame[7];
			cout.unsetf(ios::left);
			cout << Labels[i];
			cout.width(2);
			cout.setf(ios::left);
			cout.fill(' ');
			cout.unsetf(ios::left);
			cout << frame[3] << endl;

			
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(' ');
			cout << frame[7];
			cout.unsetf(ios::left);
			cout << frame[3] << endl;

			
			cout << frame[6];
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(frame[5]);
			cout.unsetf(ios::left);
			cout << frame[4] << endl;
		}
	}

	LabelMaker::~LabelMaker()
	{
		for (int i = 0; i < noLabels; i++)
			delete[] Labels[i];
		delete[] Labels;
		noLabels = 0;
	}

}