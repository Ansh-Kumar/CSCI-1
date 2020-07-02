//
//  binarySeach.cpp
//  Assignment7
//
//  Created by Ansh Kumar Khalasi on 5/7/20.
//  Copyright © 2020 Ansh Kumar Khalasi. All rights reserved.
//

#include "binarySearch.h"


int binarySearch(float arr[], int size, double searchNum, int& comparison)
{
    float y = (float)((searchNum*100)/100);
    int f, l, m;
    f = 0;
    l = size-1;
    while (f <= l)
    {
        comparison++;
        m = (f+l)/2;
        float x = arr[m];
        if (y == x)
        {
            return m;
        }
        else if (y > x)
        {
            f = m+1;
        }
        else
        {
            l = m-1;
        }
    }
    return -1;
}
