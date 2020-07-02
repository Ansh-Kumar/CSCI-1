//
//  main.cpp
//  Assignment8
//
//  Created by Ansh Kumar Khalasi on 5/20/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

// Ansh Kumar
// Section 0113
// Assignment 8

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Ansh Kumar\nSection 0113\nAssignment 8\n";
    int numStudents, numTests;
    char* firstCharData;
    char* secondCharData;
    int* firstIntData;
    int* secondIntData;
    
    ifstream inputFile;
    ofstream outputFile;
    
    inputFile.open("/Users/anshkumar/Downloads/A08_OfficialInput__.txt");
    outputFile.open("/Users/anshkumar/Documents/Computer Science/CSCI 1/Assignment8/A08_OutputFile.txt");
    
    struct sStudent
    {
        string name;
        char grade;
        float avg;
        int studentID;
        int OGTest;
        int tempTest;
        int sum;
    };
    
    inputFile >> numStudents >> numTests;
    
    sStudent studentData[numStudents];
    firstCharData = new char[numStudents];
    secondCharData = new char[numStudents];
    firstIntData = new int[numStudents];
    secondIntData = new int[numStudents];
    
    for (int students = 0;students < numStudents; students++)
    {
        inputFile >> studentData[students].name >> studentData[students].studentID >> studentData[students].OGTest;
        studentData[students].sum = studentData[students].OGTest;
        for (int tests = 0;tests < numTests -1; tests++)
        {
            inputFile >> studentData[students].tempTest;
            studentData[students].sum += studentData[students].tempTest;
        }
        studentData[students].avg = studentData[students].sum/6;
        if (studentData[students].avg >= 90)
        {
            studentData[students].grade = 'A';
        }
        else if (studentData[students].avg >= 80 and studentData[students].avg <90)
        {
            studentData[students].grade = 'B';
        }
        else if (studentData[students].avg >= 70 and studentData[students].avg < 80)
        {
            studentData[students].grade = 'C';
        }
        else if (studentData[students].avg >= 60 and studentData[students].avg < 70)
        {
            studentData[students].grade = 'D';
        }
        else
        {
            studentData[students].grade = 'F';
        }
        // THIS IS HOW U OUTPUT
        //outputFile << name << "\n\t" << studentID << "\n\t" << OGtest << "\n\t" << avg << "\n\t" << grade << endl;
    }
    
    // Find the first int
    for (int i=0;i<numStudents;i++)
    {
        string tempName = studentData[i].name;
        firstCharData[i] = tempName.at(0);
        secondCharData[i] = studentData[i].name.at(1);
    }
    // Determine the int values of them
    for (int i=0;i<numStudents;i++)
    {
        firstIntData[i] = (int)firstCharData[i];
        secondIntData[i] = (int)secondCharData[i];
    }
    
    int i, j, imin;
    int temp;
    string Stemp;
    sStudent SStemp;
    for (i=0; i<numStudents-1;i++)
    {
        imin = i;
        for (j=i+1;j<numStudents;j++)
        {
            if (studentData[j].name < studentData[imin].name)
            {
                imin = j;
            }
            // Swap first int
            /*
            temp = firstIntData[i];
            firstIntData[i] = firstIntData[imin];
            firstIntData[imin] = temp;
            */
            SStemp = studentData[i];
            studentData[i] = studentData[imin];
            studentData[imin] = SStemp;
            
        }
    }
    
    for (int i=0;i<numStudents;i++)
    {
        outputFile << studentData[i].name << "\n\t" << studentData[i].studentID << "\n\t" << studentData[i].OGTest << "\n\t" << studentData[i].avg << "\n\t" << studentData[i].grade << endl;
    }
    
}

