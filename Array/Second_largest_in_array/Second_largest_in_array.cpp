// Second_largest_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int second_lar(int arr[], int n)
{

    int sec_lar = INT_MIN;
    int lar = INT_MIN;
    if (n < 2)
        return -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > lar)
        {
            sec_lar = lar;
            lar = arr[i];
        }
        else if (arr[i] > sec_lar && arr[i] != lar)
        {
            sec_lar = arr[i];
        }
    }
    int result = (sec_lar == INT_MIN) ? -1 : sec_lar;
    return result;
}

int main()
{
    int arr[] = { -20,-10, -3,-5 ,-15, -10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = second_lar(arr, n);
    std::cout << "result of second largest no is " << result << endl;
    return 0;
}
