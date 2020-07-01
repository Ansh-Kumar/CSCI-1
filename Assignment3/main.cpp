//
//  main.cpp
//  Assignment3
//
//  Created by Ansh Kumar Khalasi on 3/12/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//
// Ansh Kumar
// Section 0113
// Assignment 3

#include <iostream>
#include <string>

int main() {
    int month;
    int year;
    std::cout << "Ansh Kumar\n";
    std::cout << "Section 0113\n";
    std::cout << "Assignment 3\n";
    std::cout << "Enter a month from 1-12: ";
    std::cin >> month;
    std::cout << "Enter a year: ";
    std::cin >> year;
    if ((month >= 1  && month <= 12) && (year >= 1800 && year <= 8000)) {
        std::cout << "The number of days this month has is ";
        switch (month) {
            case 1:
                std::cout << 31;
                break;
            case 2:
                if ((year % 100 == 0) and (year % 400 == 0))
                {
                    std::cout << 29;
                }
                else if ((year % 100 != 0) and (year % 4 == 0))
                {
                    std::cout << 29;
                }
                else
                {
                    std::cout << 28;
                }
                break;
            case 3:
                std::cout << 31;
                break;
            case 4:
                std::cout << 30;
                break;
            case 5:
                std::cout << 31;
                break;
            case 6:
                std::cout << 30;
                break;
            case 7:
                std::cout << 31;
                break;
            case 8:
                std::cout << 31;
                break;
            case 9:
                std::cout << 30;
                break;
            case 10:
                std::cout << 31;
                break;
            case 11:
                std::cout << 30;
                break;
            case 12:
                std::cout << 31;
                break;
        }
    }
    else {
        std::cout << "The month and/or the year is incorrect.";
    }
    std::cout << "\n";
}
