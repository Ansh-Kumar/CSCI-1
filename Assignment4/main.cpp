//
//  main.cpp
//  Assignment4
//
//  Created by Ansh Kumar Khalasi on 4/1/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

// Ansh Kumar
// Section 0113
// Assignment 4

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    cout << "Ansh Kumar" << endl;
    cout << "Section 0113" << endl;
    cout << "Assignment 4" << endl << endl << endl;
    ofstream outputFile;
    ifstream inputFile;
    string current_department, department, current_division, division;
    // int linenum = 1;
    float departmentSum = 0.0, divisionSum = 0.0, companySum = 0.0, profit;
    
    outputFile.open("/Users/anshkumar/Documents/Computer Science/CSCI 1/Assignment4/A04_OutputFile.txt");
    inputFile.open("/Users/anshkumar/Downloads/A04_OfficialInput.txt");
    
    outputFile << "Ansh Kumar" << endl << "Section 0113" << endl << "Assignment 4" << endl;
    
    inputFile >> department >> division >> profit;
    
    while (inputFile.eof() == false)
    {
        current_department = department;
        departmentSum = 0.0;
        while ((current_department == department) and (inputFile.eof() == false))
        {
            divisionSum = 0.0;
            current_division = division;
            while ((current_division == division) and (inputFile.eof() == false))
            {
                divisionSum += profit;
                departmentSum += profit;
                companySum += profit;
                outputFile << department << "-" << division << ": " << fixed << setprecision(2) << profit << endl;
                inputFile >> department >> division >> profit;
                
            }
            if (divisionSum < 10)
            {
                outputFile << "\t\t " << divisionSum << endl;
            }
            else
            {
                outputFile << "\t\t" << divisionSum << endl;
            }
        }
        outputFile << "\t\t\t" << departmentSum << endl;
    }
    outputFile << "\t\t\t\t" << companySum << endl;
    inputFile.close();
    outputFile.close();
}
