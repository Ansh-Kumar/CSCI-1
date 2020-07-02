//
//  CNumber.h
//  FinalExam
//
//  Created by Ansh Kumar Khalasi on 6/11/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#ifndef CNumber_h
#define CNumber_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CNumber
{
private:
    int mMaxNum;
    string *mNumberArray;
    string mStr;
    int mNum;
    
public:
    CNumber();
    
    CNumber(string arr);
    
    ~CNumber();
    
    void SetNumber(string Str);
    void Add(const CNumber & n2);
    void Sub(const CNumber & n2);
    
    int GetNum() const;
    string GetStr() const;
    
private:
    int result = 0;
    int getResult();
    int GetNumByString(string Str);
    void SetNum(int x);
};

#endif /* CNumber_h */
