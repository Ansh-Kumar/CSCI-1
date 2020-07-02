//
//  CBook.h
//  Assignment9
//
//  Created by Ansh Kumar Khalasi on 5/30/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#ifndef CBook_h
#define CBook_h

#include <string>
using namespace std;

class CBook
{
private:
    string mTitle;
    string mAuthor;
    int mYearPublished;
    
public:
    CBook();
    CBook(string Title, string Author, int YearPublished);
    ~CBook();
    
    string GetTitle() const;
    string GetAuthor() const;
    int GetYearPublished() const;
    void SetBook(string Title, string Author, int YearPublished);
    void SetTitle(string Title);
    void SetAuthor(string Author);
    void SetYearPublished(int YearPublished);
    void Swap(CBook &Book);
};

CBook::CBook()
{
    // Leave empty
}

CBook::~CBook()
{
    // Leave empty
}

string CBook::GetTitle() const
{
    return mTitle;
}

string CBook::GetAuthor() const
{
    return mAuthor;
}

int CBook::GetYearPublished() const
{
    return mYearPublished;
}

void CBook::SetTitle(string Title)
{
    mTitle = Title;
}

void CBook::SetAuthor(string Author)
{
    mAuthor = Author;
}

void CBook::SetYearPublished(int YearPublished)
{
    mYearPublished = YearPublished;
}

void CBook::SetBook(string Title, string Author, int YearPublished)
{
    CBook::SetTitle(Title);
    CBook::SetAuthor(Author);
    CBook::SetYearPublished(YearPublished);
}

void CBook::Swap(CBook &Book)
{
    string temp = mTitle;
    mTitle = Book.GetTitle();
    Book.SetTitle(temp);
    
    temp = mAuthor;
    mAuthor = Book.GetAuthor();
    Book.SetAuthor(temp);
    
    int itemp = mYearPublished;
    mYearPublished = Book.GetYearPublished();
    Book.SetYearPublished(itemp);
}

#endif /* CBook_h */
