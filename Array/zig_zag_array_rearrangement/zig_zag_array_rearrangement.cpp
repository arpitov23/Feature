// zig_zag_array_rearrangement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int zig_zag(int arr[], int n)
{
    bool ans = true; // variable to track the pattern (if the next element should be greater or smaller)

    // loop through the array and rearrange the element in zig-zag pattern

    for (int i = 0; i <= n-2; i++)
    {
        if (ans) // if the pattern is to have the next element greater
        {
            if (arr[i] > arr[i + 1])  // swap if the current element is greater
            {
                swap(arr[i], arr[i + 1]);
            }
        }
            else  // if the pattern is to have the next element smaller
            {
                if (arr[i] < arr[i + 1])
                    swap(arr[i], arr[i + 1]);
            }
            ans = !ans; // toggles the pattern for the next iteration
    }
    
    return 0;
}

int main()
{
    int arr[] = { 0,1,3,4,5,6,7,8,10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int res = zig_zag(arr, n);
    cout << "\nnew array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

