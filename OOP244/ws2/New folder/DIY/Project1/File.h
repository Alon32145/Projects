//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/6/2021
//email: araigorodetsky@myseneca.ca

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();



	bool read(char postal[]);
	bool read(int& populationNo);

}
#endif // !SDDS_FILE_H_
