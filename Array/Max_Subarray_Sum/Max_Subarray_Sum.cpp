// Max_Subarray_Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int max_sub_array(int arr[], int n)
{
    // Initialize variable

    int max_so_far = arr[0]; // Store the max sum found so far
    int max_end_here = 0; // Store the sum of the current subarray

    // Traverse the array

    for (int i = 0; i < n; i++)
    {
        cout << "max_end_here + arr[i] = " << max_end_here << " + "<<arr[i];
        max_end_here = max_end_here + arr[i]; // Add the current element to the current subarray sum
        cout <<" = "<<max_end_here << endl;

        // update max_so_far if needed
        if (max_so_far < max_end_here)
            max_so_far = max_end_here;

        // If current sum is negative , reset it to 0
        if (max_end_here < 0)
            max_end_here = 0;
    }
    return max_so_far;
}
int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Length of the array

    int result = max_sub_array(arr, n);
    cout << "Maximum subarray sum is: " << result << endl;
    return 0;
}


