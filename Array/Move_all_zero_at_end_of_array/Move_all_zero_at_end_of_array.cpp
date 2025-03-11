// Move_all_zero_at_end_of_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std; 

void move_zero_to_end(int arr[], int size)
{
    int index = 0; // to store the position of next non-zero element
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[index++] = arr[i]; // place non-zero element at the correct index
        }
    }
    
    // fill the remaining position with zero

    while (index < size)
    {
        arr[index++] = 0;
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 0,1,0,2,4,0,3,5,0 };
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    move_zero_to_end(arr, size);
    cout << "array after moving zeros to end ";
    print_array(arr, size);
    return 0;

}

