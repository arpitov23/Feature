// sort an array of 0's 1's and 2s Dutch National flag algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sort_ZeroOneTwo_dutch_algo(int arr[], int n)
{

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
            cout << "wrong number for sorting\n";

    }
    return 0;
}

int main()
{
    int arr[] = { 2,1,2,0,0,1,2,0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int a = sort_ZeroOneTwo_dutch_algo(arr, n);
    for (int i = 0; i< n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
    return 0;

}

/*
   Dry Run - 

Initial Pointers:
    low = 0
    mid = 0
    high = 8 (index of the last element)

Step-by-Step Dry Run:
    
   Iteration 1 (mid = 0, arr[mid] = 0):
    Swap arr[low] and arr[mid] → No change since both are 0.
    Increment low → low = 1
    Increment mid → mid = 1

   Iteration 2 (mid = 1, arr[mid] = 1):
    No swap needed.
    Increment mid → mid = 2

   Iteration 3 (mid = 2, arr[mid] = 2):
    Swap arr[mid] and arr[high] → Swap 2 with 2 (no visible change).
    Decrement high → high = 7

   Iteration 4 (mid = 2, arr[mid] = 1):
    No swap needed.
    Increment mid → mid = 3

   Iteration 5 (mid = 3, arr[mid] = 1):
    No swap needed.
    Increment mid → mid = 4

   Iteration 6 (mid = 4, arr[mid] = 0):
    Swap arr[low] and arr[mid] → Swap 1 with 0.
    arr = {0, 0, 1, 1, 1, 2, 1, 0, 2}
    Increment low → low = 2
    Increment mid → mid = 5

   Iteration 7 (mid = 5, arr[mid] = 2):
    Swap arr[mid] and arr[high] → Swap 2 with 0.
    arr = {0, 0, 1, 1, 1, 0, 1, 2, 2}
    Decrement high → high = 6

   Iteration 8 (mid = 5, arr[mid] = 0):
    Swap arr[low] and arr[mid] → Swap 1 with 0.
    arr = {0, 0, 0, 1, 1, 1, 1, 2, 2}
    Increment low → low = 3
    Increment mid → mid = 6

   Iteration 9 (mid = 6, arr[mid] = 1):
    No swap needed.
    Increment mid → mid = 7

   Iteration 10 (mid = 7, arr[mid] = 2):
    Swap arr[mid] and arr[high] → Swap 2 with 2 (no visible change).
    Decrement high → high = 5
    Now mid > high, so the loop terminates.

   Final Sorted Array - {0, 0, 0, 1, 1, 1, 1, 2, 2}

*/