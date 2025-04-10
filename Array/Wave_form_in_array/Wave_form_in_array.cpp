// Wave_form_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

int wave_form(int arr[], int n)
{
    // traverse all element 

    for (int i = 0; i < n; i+=2)
    {
        // if current element is smaller than previous element than swap
        if (i > 0 && arr[i - 1] > arr[i])
        {
            swap(arr[i], arr[i - 1]);
        }

        // if current elemenent is smaller than nect element than also swap
        if (i <n-1 && arr[i] < arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
    return 0;
}
int main()
{
    int arr[] = { 10, 90, 49, 2, 1, 5, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    wave_form(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

