/*
    ==================================================
    Name   : Alon
    ID     : 109763201
    Email  : araigorodtesky@myseneca.ca
*/


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
    bool read(char name[])
    {
        bool res = fscanf(fptr, "%[^\n]\n", name) == 1;
        return res ;
    }
    bool read(int& empNo)
    {
        bool res = fscanf(fptr, "%d,", &empNo) == 1;
        return res;
    }
    bool read(double& salary)
    {
        bool res = fscanf(fptr, "%lf,", &salary) == 1;
        return res;
    }
}