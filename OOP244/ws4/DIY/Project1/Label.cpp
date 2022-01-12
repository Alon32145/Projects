//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/20/2021
//email: araigorodetsky@myseneca.ca

#include "Label.h"
#include "cstring.h"

namespace sdds
{
	void Label::setTitle(const char* frame_base)
	{
		title = new char[strLen(frame_base) + 1];
		strCpy(title, frame_base);
	}

	void Label::setText(const char* text_base)
	{
		text = new char[strLen(text_base) + 1];
		strCpy(text, text_base);
	}


	Label::Label(const char* frameArg, const char* content)
	{
		setTitle(frameArg);
		setText(content);
	}


	Label::Label(const char* frameArg)
	{
		setTitle(frameArg);
		text = nullptr;
	}


	Label::Label()
	{
		setTitle("+-+|+-+|");
		text = nullptr;
	}

	Label::~Label()
	{
		delete[] title;
		title = nullptr;
		delete[] text;
		text = nullptr;
	}


	std::ostream& Label::printLabel() const
	{
		if (text != nullptr && title != nullptr)
		{
			//length of horizontal lines
			int length_horizontal = strLen(text) + 3;

			// up horizontal
			cout << title[0];
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(title[1]);
			cout.unsetf(ios::left);
			cout << title[2] << endl;

			//left vertical
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(' ');
			cout << title[7];
			cout.unsetf(ios::left);
			cout << title[3] << endl;

			//text 
			cout.width(2);
			cout.setf(ios::left);
			cout.fill(' ');
			cout << title[7];
			cout.unsetf(ios::left);
			cout << text;
			cout.width(2);
			cout.setf(ios::left);
			cout.fill(' ');
			cout.unsetf(ios::left);
			cout << title[3] << endl;

			//right vertical
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(' ');
			cout << title[7];
			cout.unsetf(ios::left);
			cout << title[3] << endl;

			// down horizontal
			cout << title[6];
			cout.width(length_horizontal);
			cout.setf(ios::left);
			cout.fill(title[5]);
			cout.unsetf(ios::left);
			cout << title[4];

			return cout;
		}
		return cout;
	}
}