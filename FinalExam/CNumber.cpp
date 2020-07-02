//
//  CNumber.cpp
//  FinalExam
//
//  Created by Ansh Kumar Khalasi on 6/11/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#include <stdio.h>
#include "CNumber.h"
#include <iostream>
#include <string>
#include <fstream>

CNumber::CNumber()
{
    
}
/*
CNumber::CNumber(int arrSize)
{
    mNumberArray = new string[arrSize];
}
*/
CNumber::~CNumber()
{
    
}

void CNumber::SetNumber(string Str)
{
    string delim = "|";
    int pos = Str.find(delim);
    mStr = Str.substr(0, pos);
    string t = Str.substr(pos+1, Str.length());
    int i = stoi(t);
    SetNum(i+1);
    
}

string CNumber::GetStr() const
{
    return mStr;
}

int CNumber::GetNum() const
{
    return mNum;
}

void CNumber::SetNum(int x)
{
    mNum = x;
}

void CNumber::Add(const CNumber &n2)
{
    int t = n2.GetNum();
    int t2 = mNum;
    int result = t + t2;
    mNum = result;
}
void CNumber::Sub(const CNumber &n2)
{
    mNum -= n2.GetNum();
}
