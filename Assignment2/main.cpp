//
//  main.cpp
//  Assignment2
//
//  Created by Ansh Kumar Khalasi on 3/5/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

// Ansh Kumar
// Section 0113
// Assignment 2

#include <iostream>

int main() {
    std::cout << "Ansh Kumar\n";
    std::cout << "Section 0113\n";
    std::cout << "Assignment #2\n";
    
    int givenHour;
    int givenMinute;
    int givenSecond;
    int timeChange;
    std::cout << "Give me the hour: ";
    std::cin >> givenHour;
    std::cout << "Give me the minute: ";
    std::cin >> givenMinute;
    std::cout << "Give me the second: ";
    std::cin >> givenSecond;
    std::cout << "Give me the time change: ";
    std::cin >> timeChange;
    
    int newSeconds = givenSecond;
    int newMinute = givenMinute;
    int newHour = givenHour;
    int secondChange = givenSecond + timeChange;
    int minuteChange;
    int hourChange;
    
    newSeconds = secondChange >= 60? secondChange%60 : secondChange;
    minuteChange = secondChange >= 60? (secondChange/60): 0;
    newMinute += minuteChange;
    newMinute = newMinute >= 60? newMinute%60 : newMinute;
    hourChange = minuteChange >= 60? (minuteChange/60): 0;
    newHour += hourChange;
    newHour = newHour >= 25? newHour%25 : newHour;
    
    std::cout << "Hour: " << newHour << "\nMinute: " << newMinute << "\nSeconds: " << newSeconds << '\n';
}
