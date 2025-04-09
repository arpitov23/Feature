// Reverse_array_in_group_size_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

int reverse_array_group(int arr[], int n, int group_size)
{
    for (int i = 0; i < n; i = i + group_size)
    {
        // Get the end of the current chunk (either the next group or the end of the array)
        int end = min(i + group_size - 1, n - 1);
        
        // reverse the current chunk of the array from i to end 
        reverse(arr + i, arr + end + 1);
            
    }
    return 0;
}
int main()
{
    // Declare a fixed-size array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Define the group size
    int groupSize = 3;

    // Call the function to reverse in groups
    reverse_array_group(arr, n, groupSize);

    // Print the modified array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}

