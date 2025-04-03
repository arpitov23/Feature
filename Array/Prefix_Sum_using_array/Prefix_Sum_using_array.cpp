// Prefix_Sum_using_array.cpp : This file contains the 'main' function. Program execution begins and ends there.

// ------- Problem - It is used to compute cumulative sums of element in an array.


/*
  Approach - 
           -> First we take the size n of the array and then the n elements
           -> We create an array "prefix" of the same size as arr.
           -> We initialize the first element of "prefix" to be the same as arr[0].
           -> For each subsequent element, we compute "prefix[i] = prefix[i-1 + arr[i]".
           -> prefix array is printed to show the cumulative sum of element at each position.

*/
#include <iostream>
using namespace std;

void prefix_sum(int arr[], int n)
{
    // step 2 - create a prefix sum array
   // int prefix[n];
    int* prefix = new int[n];

    // step 3 - initialize the first element of prefix sum array
    prefix[0] = arr[0];

    // step 4 - calculate the rest of the prefix sum array
    for (int i = 1; i < n; i++)
    {
       // cout << "prefix[i] = " << prefix[i] << endl;
       // cout << "prefix[i-1] = " << prefix[i-1] << endl;
       // cout << "arr[i] = " << arr[i] << endl;
        prefix[i] = prefix[i - 1] + arr[i];
    }

    //step 5 -  display the prefix sum
    cout << "Prefix Sum array: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;
    

}

int main()
{
    int arr[] = { 1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    prefix_sum(arr, n);
    return 0;
}


/*

Explanation - 

prefix[0] = arr[0] = 1

prefix[1] = arr[0] + arr[1] = 1+2 = 3
prefix[2] = arr[0] + arr[2] + arr[3] = 1+2+3 = 6
prefix[1] = arr[0] + arr[1] + arr[3] + arr[4] = 1+2+3+4 = 10
prefix[1] = arr[0] + arr[1] + arr[3] + arr[4] + arr[5] = 1+2+3+4+5 = 15

This approach works in O(n) time complexity where n is the number of elements in the array.
*/