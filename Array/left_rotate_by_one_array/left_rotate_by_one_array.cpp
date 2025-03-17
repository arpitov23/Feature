// left_rotate_by_one_array.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Approach (Single Loop)

    Store the first element in a temporary variable.
    Shift all elements one position to the left.
    Place the first element at the last index.
*/

#include <iostream>
using namespace std;

void left_rotate(int arr[], int n)
{
    if (n <= 1)
        return ;
    int tmp_storage = arr[0];    // store first element in to the temporary variable

    //shift element one position left

    for (int i = 0; i < n; i++)   
    {
        arr[i] = arr[i + 1];   // shifiting all element one position to the left
    }
    arr[n - 1] = tmp_storage;    // place the first element at the last index, where n is the size of array 
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] <<" ";
     
}
int main()
{
    int arr[] = { 1,2,3,4,5 };
   int m = sizeof(arr) / sizeof(arr[0]);
   left_rotate(arr, m);
   print_arr(arr, m);
   return 0;
}

