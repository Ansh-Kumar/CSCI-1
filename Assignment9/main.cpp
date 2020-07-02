//
//  main.cpp
//  Assignment9
//
//  Created by Ansh Kumar Khalasi on 5/30/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "CBook.h"
#include "CLibrary.h"

int main()
{
    
    
    ifstream inputFile;
    ofstream outputFile;
    
    string inpLoc = "/Users/anshkumar/Downloads/A09_OfficialInput.txt";
    string outLoc = "/Users/anshkumar/Documents/Computer Science/CSCI 1/Assignment9/A09_OutputFile.txt";
    
    CLibrary mainLibrary(inpLoc, outLoc);
    
    
    mainLibrary.ReadBooks();
    mainLibrary.PrintBooks(1);
    mainLibrary.Sort();
    mainLibrary.PrintBooks(2);
    
    
    
}
