// Rotate_left_array_by_D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

/*
void left_rotate_by_D(int arr[], int N, int D)
{
    D = D % N;  // Handle cases where D > N
    //int temp[D]; // error - array type int[D] is not assignable

    int* temp = new int[D]; // Allocate dynamic memory

    //store first  D elements in temp

    for (int i = 0; i < D; i++)
    {
        temp[i] = arr[i];
    }

    // shift the rest of the element left

    for (int i = 0; i < N - D; i++)
    {
        arr[i] = arr[i + D];
    }

    // copy temp element to the end 

    for (int i = 0; i < D; i++)
    {
        arr[N - D + i] = temp[i];
    }
}
*/

// -------- Approach 2 -In-Place Rotation Using Reversal Algorithm (No Extra Space)

// - Reverse the first D element
// - Reverse the remaining N-D elements
// - Reverse the entire array 


void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void left_rotate_by_D(int arr[], int N, int D)
{
    D = D % N; // Handle cases where D > N

    reverse(arr, 0, D - 1); // Reverse first D elements
    reverse(arr, D, N - 1); // Reverse remaining elements
    reverse(arr, 0, N - 1); // reverse the whole array 
}
void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int D = 2;

    left_rotate_by_D(arr, N, D);
    printArray(arr, N);

    return 0; 
}

