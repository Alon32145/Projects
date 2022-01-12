//Name: Alon Raigorodetsky
//User ID: 109763201
//Date: 6/6/2021
//email: araigorodetsky@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }



    bool read(char postal[])
    {
        bool res = fscanf(fptr, "%[^,]", postal) == 1;
        return res;
    }
    bool read(int& populationNo)
    {
        bool res = fscanf(fptr, ", %d\n", &populationNo) == 1;
        return res;
    }

}