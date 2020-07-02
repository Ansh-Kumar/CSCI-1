//
//  CLibrary.h
//  Assignment9
//
//  Created by Ansh Kumar Khalasi on 5/30/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#ifndef CLibrary_h
#define CLibrary_h

#include <string>
#include <fstream>
#include "CBook.h"
using namespace std;

class CLibrary
{
private:
    int mNumBooks;
    CBook *mBooks;
    string mInputFileName;
    string mOutputFileName;
    
    string title;
    string author;
    int yearPub;
    
    ifstream inputFile;
    ofstream outputFile;
    
    void Sort(CBook *Books, int Size);
    

public:
    CLibrary();
    CLibrary(string InputFileName, string OutputFileName);
    ~CLibrary();
    
    int getNumBooks();
    
    void setNumBooks(int value);
    void ReadBooks();
    void Sort();
    void PrintBooks(int b);
    string NewUpdatedString(string value);
    
};

CLibrary::CLibrary()
{
    
}

CLibrary::~CLibrary()
{
    
}

CLibrary::CLibrary(string InputFilename, string OutputFileName)
{
    mInputFileName = InputFilename;
    mOutputFileName = OutputFileName;
    
    inputFile.open(mInputFileName);
    outputFile.open(mOutputFileName);
    
    string sMNumBooks;
    getline(inputFile, sMNumBooks);
    mNumBooks = stoi(sMNumBooks);
    setNumBooks(getNumBooks());
    
}

void CLibrary::setNumBooks(int value)
{
    mNumBooks = value;
    mBooks = new CBook[mNumBooks];
}

void CLibrary::ReadBooks()
{
    for (int x=0;x<mNumBooks;x++)
    {
        string sYearPub;
        getline(inputFile, title);
        getline(inputFile, author);
        getline(inputFile, sYearPub);
        
        yearPub = stoi(sYearPub);
        
        mBooks[x].SetBook(title, author, yearPub);
    }
}

int CLibrary::getNumBooks()
{
    
    return mNumBooks;
}

void CLibrary::PrintBooks(int b)
{
    if (b == 1)
    {
        outputFile << "Unsorted\n";
    }
    else
    {
        outputFile << "\nSorted\n";
    }
    for (int x=0;x<mNumBooks;x++)
    {
        string oldTitle = mBooks[x].GetTitle();
        string newTitle = NewUpdatedString(oldTitle);
        string oldAuthor = mBooks[x].GetAuthor();
        string newAuthor = NewUpdatedString(oldAuthor);
        mBooks[x].GetAuthor() = NewUpdatedString(mBooks[x].GetAuthor());
        if (newTitle.length() > 0 && newTitle.length() < 8)
        {
            outputFile << "\t" << newTitle << "\t\t\t\t" << newAuthor << "\t" << mBooks[x].GetYearPublished() << endl;
        }
        else if (newTitle.length() > 7 && newTitle.length() < 16)
        {
            outputFile << "\t" << newTitle << "\t\t\t" << newAuthor << "\t" << mBooks[x].GetYearPublished() << endl;
        }
        else if (newTitle.length() > 15 && newTitle.length() < 22)
        {
            outputFile << "\t" << newTitle << "\t\t" << newAuthor << "\t" << mBooks[x].GetYearPublished() << endl;
        }
        else
        {
            outputFile << "\t" << newTitle << "\t" << newAuthor << "\t" << mBooks[x].GetYearPublished() << endl;
        }
        
    }
}


string CLibrary::NewUpdatedString(string value)
{
    value.erase(value.end()-1, value.end());
    return value;
}

void CLibrary::Sort(CBook *Books, int Size)
{
    int i, j, imin;
    CBook bStemp;
    for (i=0; i<Size-1;i++)
    {
        imin = i;
        for (j=i+1;j<Size;j++)
        {
            if (Books[j].GetTitle() < Books[imin].GetTitle())
            {
                imin = j;
            }
            
            Books[i].Swap(Books[imin]);
            
        }
    }
}

void CLibrary::Sort()
{
    Sort(mBooks, mNumBooks);
}

#endif /* CLibrary_h */
