//
//  subs.cpp
//  Assignment5
//
//  Created by Ansh Kumar Khalasi on 4/17/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

// Ansh Kumar
// Section 0113
// Assignment 5

#include <stdio.h>
#include "subs.h"
int GetCategory(char c)
{
    
    if (int (c) == 95)
    {
        return 1;
    }
    else if ((int (c) >= 97) and (int (c) <= 122))
    {
        return 2;
    }
    else if ((int (c) >= 65) and (int (c) <= 90))
    {
        return 3;
    }
    else if (int (c) >= 48 and int (c) <= 57)
    {
        return 4;
    }
    else
    {
        return 5;
    }
}

int NextState(int CurrState, int Category, int& Length)
{
    Length += 1;
    if (CurrState == 0)
    {
        if (Category < 4)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if (CurrState == 1)
    {
        if ((Category >= 1) and (Category <= 4))
        {
            return 1;
        }
        if (Category == 5)
        {
            return 2;
        }
    }
    return 2;
}
