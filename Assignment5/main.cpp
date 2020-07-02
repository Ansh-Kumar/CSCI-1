//
//  main.cpp
//  Assignment5
//
//  Created by Ansh Kumar Khalasi on 4/7/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

// Ansh Kumar
// Section 0113
// Assignment 5

#include <iostream>
#include <fstream>
#include "subs.h"
using namespace std;

int main()
{
    cout << "Ansh Kumar" << endl << "Section 0113" << endl << "Assignment 5" << endl;
    ifstream inputFile;
    ofstream outputFile;
    
    inputFile.open("/Users/anshkumar/Downloads/A05_OfficialInputEdit.txt");
    outputFile.open("/Users/anshkumar/Documents/A05_out.txt");
    
    int State, Category, Length;
    char c;
    
    while (inputFile.eof() == false)
    {
        inputFile.get(c);
        if (c == 'z')
        {
            break;
        }
        outputFile << c;
        State = 0;
        Length = 0;
        
        do
        {
            Category = GetCategory(c);
            State = NextState(State, Category, Length);
            inputFile.get(c);
            outputFile << c;
        }
        while (c != '\n');
        
        if (State == 1)
        {
            outputFile << "\tValid Identifier\tLength = " << Length-1 << "\n";
        }
        else
        {
            outputFile << "\tInvalid Identifier\tLength = " << Length-1 << "\n";
        }
    }
    
}
