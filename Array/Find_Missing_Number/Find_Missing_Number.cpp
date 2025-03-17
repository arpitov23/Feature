// Find_Missing_Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std; 

int missing_num(int arr[], int size, int n)
{
    int expected_sum = n * (n + 1) / 2; // calculate the sum of first n natural numbers
    int actual_sum = 0; // calculate the sum of element in array - below is the logic

    for (int i = 0; i < size; i++)
    {
        actual_sum = actual_sum + arr[i];
    }

    // The missing element is the different between the expected and actual sum 
    return expected_sum - actual_sum;


}

int main()
{
    int arr[] = { 1, 2, 3, 4, 6, 7, 8, 9, 10 };  // Missing element is 5
    int size = sizeof(arr) / sizeof(arr[0]);

    int n = 10; // the range is from 1 to 10 

    int missing_num_ele = missing_num(arr, size, n);
    cout << "missing numnber is : " << missing_num_ele << endl;
    return 0;
}


/*

Approach - 

For the input array {1, 2, 3, 4, 6, 7, 8, 9, 10} with n = 10, the steps would be:

Expected Sum -  n * (n + 1) / 2; i.e. 10*(10+1)/2  = 55
Actual Sum - Actual Sum=1 + 2 + 3 + 4 + 6 + 7 + 8 + 9 + 10 = 50

Missing Element - Expected - Actual i.e. 55-50 = 5

*/