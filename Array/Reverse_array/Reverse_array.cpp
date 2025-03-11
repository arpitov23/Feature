// Reverse_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void reverse_array(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // swap the element at start and end 
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
}
void print_reverse_arr(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";

    }
    cout << endl;
}

int main()
{
    int arr[5] = { 1,2,3,4,5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "original array : ";
    print_reverse_arr(arr, size);
    reverse_array(arr, size);
    cout << "Reversed Array : ";
    print_reverse_arr(arr, size);
    return 0;
}

