//
//  main.cpp
//  Assignment6
//
//  Created by Ansh Kumar Khalasi on 4/25/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//


// Ansh Kumar
// Section 0113
// Assignment 6
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "Ansh Kumar" << endl << "Section 0113" << endl << "Assignment 6" << endl;
    ifstream inputFile;
    ofstream outputFile;
    string name, id;
    int questionNum;
    char answer;
    string key[15], studentAns[15], checker[15], status;
    double grade, correct;
    
    inputFile.open("/Users/anshkumar/Downloads/A06_OfficialInput.txt");
    outputFile.open("/Users/anshkumar/Documents/Computer Science/CSCI 1/Assignment6/A06_OutputFile.txt");
    outputFile << "Ansh Kumar" << endl << "Section 0113" << endl << "Assignment 6" << endl;
    getline(inputFile, name);
    while (!inputFile.eof())
    {
        if (name == "zzz" or id == "zzz")
        {
            break;
        }
        if (name == "key\r")
        {
            for (int x=1; x<16;x++)
            {
                inputFile >> questionNum >> answer;
                key[questionNum-1] = answer;
            }
        }
        else
        {
            correct = 0;
            for (int x=1; x<16;x++)
            {
                inputFile >> questionNum >> answer;
                studentAns[questionNum-1] = answer;
                
            }
            // Check answers
            for (int x=0;x<15;x++)
            {
                if (key[x] == studentAns[x])
                {
                    checker[x] = "";
                    correct += 1;
                }
                else
                {
                    checker[x] = "X";
                }
            }
            grade = correct/15*100;
            status = grade < 70? "Failed" : "Passed";
            
            
            outputFile << "Name: " << id << " " << name << endl;
            for (int x=0;x<15;x++)
            {
                if ((x+1) % 5 != 0)
                {
                    if ((x+1) < 10)
                    {
                        outputFile << "\t " << x+1 << " " << studentAns[x] << checker[x];
                    }
                    else
                    {
                        outputFile << "\t" << x+1 << " " << studentAns[x] << checker[x];
                    }
                }
                else
                {
                    if ((x+1) < 10)
                    {
                        outputFile << "\t " << x+1 << " " << studentAns[x] << checker[x] << endl;
                    }
                    else
                    {
                        outputFile << "\t" << x+1 << " " << studentAns[x] << checker[x] << endl;
                    }
                }
            }
            outputFile << setprecision(4) << "\nScore: " << grade << " " << status << endl << endl;
        }
        inputFile >> id >> name;
    }
    inputFile.close();
    outputFile.close();
}
