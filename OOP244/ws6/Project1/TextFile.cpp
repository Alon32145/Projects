// Name: Alon Raigorodetsky
// ID: 109763201
// Email: araigorodetsky@myseneca.ca
// Date: 2021/07/06

// Section: NEE

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Line::operator const char* () const
    {
        return (const char*)m_value;
    }


    Line& Line::operator=(const char* lineValue)
    {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }


    Line::~Line()
    {
        delete[] m_value;
    }


    void TextFile::setEmpty()
    {
        delete[] m_textLines;
        delete[] m_filename;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_noOfLines = 0;
    }


    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        delete[] m_filename;

        m_filename = new char[strLen(fname) + 1 + (isCopy * 2)];
        m_filename[0] = '\0';
        if (isCopy)
        {
            strCpy(m_filename, "C_");
        }
        strCat(m_filename, fname);
    }


    void TextFile::setNoOfLines()
    {
        ifstream file(m_filename);
        m_noOfLines = 0;
        while (file)
        {
            if (file.get() == '\n')
            {
                m_noOfLines++;
            }
        }
        m_noOfLines++;
        if (m_noOfLines == 1)
        {
            delete[] m_filename;
            m_filename = nullptr;

        }
    }


    void TextFile::loadText()
    {
        if (m_filename != nullptr)
        {
            ifstream file(m_filename);
            string line;
            int i = 0;
            m_textLines = new Line[m_noOfLines];
            while (getline(file, line))
            {
                m_textLines[i++] = line.c_str();// point
            }
            m_noOfLines = i; // reletaed to line 44
        }
    }


    void TextFile::saveAs(const char* fileName)const
    {
        ofstream file(fileName);
        for (unsigned int i = 0; i < m_noOfLines; i++)
            file << m_textLines[i] << endl;

    }


    TextFile::TextFile(unsigned pageSize)
    {
        m_pageSize = pageSize;
    }


    TextFile::TextFile(const char* filename, unsigned pageSize)
    {
        m_pageSize = pageSize;
        if (filename)
        {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }


    TextFile::TextFile(const TextFile& text)
    {
        m_pageSize = text.m_pageSize;
        if (text)
        {
            setFilename(text.m_filename, true);
            text.saveAs(m_filename);
            setNoOfLines();
            loadText();


        }
    }


    TextFile& TextFile::operator=(const TextFile& text)
    {
        if (this != &text && text && *this)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
            text.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return*this;
    }


    TextFile::~TextFile()
    {
        delete[] m_textLines;
        delete[] m_filename;
    }


    unsigned TextFile::lines()const
    {
        return m_noOfLines;
    }


    std::ostream& TextFile::view(std::ostream& ostr)const
    {
        if (m_filename)
        {
            ostr << m_filename << endl;
            ostr.width(strLen(m_filename));
            ostr.fill('=');
            ostr << '=' << endl;
            for (unsigned i = 0; i < m_noOfLines; i++)
            {
                ostr << (*this)[i] << endl;
                if ((i + 1) % m_pageSize == 0)
                {
                    ostr << "Hit ENTER to continue...";
                    cin.ignore(1000, '\n');
                }
                    
            }
        }
        return ostr;
    }


    std::istream& TextFile::getFile(std::istream& istr)
    {
        char fname[256];
        istr >> fname;
        istr.ignore(1000, '\n');
        setFilename(fname);
        setNoOfLines();
        loadText();
        return istr;
    }


    const char* TextFile::operator[](unsigned index)const
    {
        const char* line = nullptr;
        if (*this)
        {
            line = m_textLines[index % m_noOfLines];
        }
        return line;
    }


    TextFile::operator bool()const
    {
        return m_filename != nullptr;
    }


    const char* TextFile::name()const
    {
        return m_filename;
    }


    ostream& operator<<(ostream& ostr, const TextFile& text)
    {
        return text.view(ostr);
    }


    istream& operator>>(istream& istr, TextFile& text)
    {
        return text.getFile(istr);
    }


}