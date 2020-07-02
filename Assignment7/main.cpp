//
//  main.cpp
//  Assignment7
//
//  Created by Ansh Kumar Khalasi on 5/3/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

// Ansh Kumar
// Section 0113
// Assignment 7

#include <iostream>
#include <fstream>
#include "binarySearch.h"
using namespace std;

int main() {
    cout << "Ansh Kumar\nSection 0113\nAssignment 7\n";
    
    // Declare variables
    
    float *set1, tempNum1, y=0.0, l=0.0;
    double *set2, tempNum2;
    int set1Size, set2Size, location, comparison=0;
    ifstream inputFile;
    ofstream outputFile;
    
    inputFile.open("/Users/anshkumar/Downloads/A07_OfficialInput.txt");
    outputFile.open("/Users/anshkumar/Documents/Computer Science/CSCI 1/Assignment7/A07_OutputFile.txt");
    
    inputFile >> set1Size;
    set1 = new float[set1Size];
    // Setting up the first array
    for (int x=0;x<set1Size;x++)
    {
        inputFile >> tempNum1;
        set1[x] = tempNum1;
    }
    // Setting up second array
    inputFile >> set2Size;
    set2 = new double[set2Size];
    for (int x=0;x<set2Size;x++)
    {
        inputFile >> tempNum2;
        set2[x] = tempNum2;
    }
    /*
    for (int x = 0; x<set1Size;x++)
    {
        cout << x << "\t" << set1[x] << endl;
    }
    for (int x = 0; x<set2Size;x++)
    {
        cout << x << "\t" << set2[x] << endl;
    }
    */
    // Linear Search
    
    outputFile << "Linear Search:\n\n\t\tSearched\tIndex\tComparisons\n";
    
    for (int x=0; x<set2Size;x++)
    {
        comparison = 0;
        location = -1;
        l = (float)((set2[x]*100)/100);
        for (int i=0; i<set1Size;i++)
        {
            y = (float)((set1[i]*100)/100);
            if (l < 1)
            {
                l = 0;
            }
            comparison += 1;
            if (y == l)
            {
                location = i;
                break;
            }
        }
        outputFile << "\t\t" << set2[x] << "\t\t" << location << "\t" << comparison << endl;
    }
    
    // Selection Sort
    int i, j, imin;
    for (i=0; i<set1Size-1;i++)
    {
        imin = i;
        for (j=i+1;j<set1Size;j++)
        {
            if (set1[j] < set1[imin])
            {
                imin = j;
            }
            // Swap
            float temp;
            temp = set1[i];
            set1[i] = set1[imin];
            set1[imin] = temp;
        }
    }
    // Binary Search
    outputFile << "\n\nBinary Search:\n\n\t\tSearched\tIndex\tComparisons\n";
    comparison = 0;
    for (int x=0; x < set2Size; x++)
    {
        float y = (float)((set2[x]*100)/100);
        location = binarySearch(set1, set1Size, set2[x], comparison);
        outputFile << "\t\t" << y << "\t\t" << location << "\t" << comparison << endl;
    }
}
