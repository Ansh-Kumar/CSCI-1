//
//  main.cpp
//  FinalExam
//
//  Created by Ansh Kumar Khalasi on 6/11/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "CNumber.h"
using namespace std;

int main() {
    ifstream inputFileOG;
    ifstream inputFileOperations;
    ofstream outputEFile;
    ofstream outputFile;
    
    inputFileOG.open("/Users/anshkumar/Downloads/Final_OfficialInput_num.txt");
    inputFileOperations.open("/Users/anshkumar/Downloads/Final_OfficialInput_op4.txt");
    outputEFile.open("/Users/anshkumar/Documents/FinalEchoFile.txt");
    outputFile.open("/Users/anshkumar/Documents/FinalOutputFile.txt");
    
    outputEFile << "Ansh Kumar\nSection 0113\nFinal Exam Program: Echo File\n";
    outputFile << "Ansh Kumar\nSection 0113\nFinal Exam Program: Operation Output File\n\n";
    
    CNumber *numbers;
    
    int arrSize;
    string *arr;
    string tempStr;
    string operation, val1, val2;
    CNumber v1, v2;
    
    inputFileOG >> arrSize;
    
    arr = new string[arrSize];
    
    numbers = new CNumber[arrSize];
    
    // Echo File
    
    for (int x=0; x<arrSize; x++)
    {
        inputFileOG >> tempStr;
        tempStr = tempStr + "|" + to_string(x);
        numbers[x].SetNumber(tempStr);
        outputEFile << numbers[x].GetStr() << endl;
    }
    
    
    
    while (operation != "end")
    {
        getline(inputFileOperations, operation);
        getline(inputFileOperations, val1);
        getline(inputFileOperations, val2);
        operation = operation.substr(0, operation.length()-1);
        val1 = val1.substr(0, val1.length()-1);
        val2 = val2.substr(0, val2.length()-1);
        
        for (int x = 0; x<arrSize;x++)
        {
            if (val1 == numbers[x].GetStr())
            {
                v1 = numbers[x];
                break;
            }
        }
        for (int x = 0; x<arrSize;x++)
        {
            if (val2 == numbers[x].GetStr())
            {
                v2 = numbers[x];
                break;
            }
        }
        
        if (operation == "add")
        {
            if (v1.GetNum() < 10)
            {
                outputFile << "n1:\t\t  " << v1.GetNum() << " (" << v1.GetStr() << ")\n";
            }
            else
            {
            outputFile << "n1:\t\t " << v1.GetNum() << " (" << v1.GetStr() << ")\n";
            }
            
            if (v2.GetNum() < 10) {
                outputFile << "n2:\t\t  " << v2.GetNum() << " (" << v2.GetStr() << ")\n";
            }
            else
            {
                outputFile << "n2:\t\t " << v2.GetNum() << " (" << v2.GetStr() << ")\n";
            }
            
            int i = v1.GetNum();
            v1.Add(v2);
            
            if (v1.GetNum() > 0 and v1.GetNum() < 100)
            {
                if (v1.GetNum() < 10)
                {
                    outputFile << "Add:\t\t  " << v1.GetNum() << " (" << numbers[i+v2.GetNum()-1].GetStr() << ")\n\n";
                }
                else
                {
                    outputFile << "Add:\t\t " << v1.GetNum() << " (" << numbers[i+v2.GetNum()-1].GetStr() << ")\n\n";
                }
            }
            else if (v1.GetNum() == 0)
            {
                outputFile << "Add:\t\t  " << v1.GetNum() << " (zero)\n\n";
            }
            else if (v1.GetNum() == 100)
            {
                outputFile << "Add:\t\t" << v1.GetNum() << " (one hundred)\n\n";
            }
            else if (v1.GetNum() > 100)
            {
                string temp = numbers[i+v2.GetNum()-101].GetStr();
                outputFile << "Add:\t\t" << v1.GetNum() << " (one hundred " << numbers[i+v2.GetNum()-101].GetStr() << ")\n\n";
            }
            v1.Sub(v2);
            
        }
        else if (operation == "sub")
        {
            if (v1.GetNum() < 10)
            {
                outputFile << "n1:\t\t  " << v1.GetNum() << " (" << v1.GetStr() << ")\n";
            }
            else
            {
            outputFile << "n1:\t\t " << v1.GetNum() << " (" << v1.GetStr() << ")\n";
            }
            
            if (v2.GetNum() < 10) {
                outputFile << "n2:\t\t  " << v2.GetNum() << " (" << v2.GetStr() << ")\n";
            }
            else
            {
                outputFile << "n2:\t\t " << v2.GetNum() << " (" << v2.GetStr() << ")\n";
            }
            
            int i = v1.GetNum();
            v1.Sub(v2);
            
            if (v1.GetNum() > 0 and v1.GetNum() < 100)
            {
                if (v1.GetNum() < 10)
                {
                    outputFile << "Sub:\t\t  " << v1.GetNum() << " (" << numbers[i-v2.GetNum()-1].GetStr() << ")\n\n";
                }
                else
                {
                    outputFile << "Sub:\t\t " << v1.GetNum() << " (" << numbers[i-v2.GetNum()-1].GetStr() << ")\n\n";
                }
            }
            else if (v1.GetNum() == 0)
            {
                outputFile << "Sub:\t\t  " << v1.GetNum() << " (zero)\n\n";
            }
            else if (v1.GetNum() == 100)
            {
                outputFile << "Sub:\t\t" << v1.GetNum() << " (one hundred)\n\n";
            }
            else if (v1.GetNum() < 0)
            {
                if (v1.GetNum() > -10)
                {
                    outputFile << "Sub:\t\t " << v1.GetNum() << " (" << "negative " << numbers[(i-v2.GetNum()+1)*-1].GetStr() << ")\n\n";
                }
                else if (v1.GetNum() > -100)
                {
                    outputFile << "Sub:\t\t" << v1.GetNum() << " (" << "negative " << numbers[(i-v2.GetNum()+1)*-1].GetStr() << ")\n\n";
                }
            }
            
            v1.Add(v2);
            
        }
    }
        
    
    
    
    inputFileOG.close();
    outputFile.close();
    
    delete[] numbers;
    
}
