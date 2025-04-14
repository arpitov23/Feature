// separate_0s_and_1s_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void segregate_Even_odd(int arr[], int n)
{
    int counter = 0; // initialize a counter for number of 0s

    //count the number of zeros in array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            counter++;
    }

    // place the counted zeroes at the beginning of the array
    for (int i = 0; i < counter; i++)
    {
        arr[i] = 0;
    }

    // place the remaining ones after the zeores in the array 
    for (int i = counter; i < n; i++)
        arr[i] = 1;

}
int main()
{
    int nums[] = { 0, 1, 0, 0 , 1, 1, 1, 0, 1, 0 }; // Declaration and initialization of an integer array
    int n = sizeof(nums) / sizeof(nums[0]); // Calculate the number of elements in the array
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " "; // Output each element of the original array
    segregate_Even_odd(nums, n); // Rearrange the array by segregating 0s and 1s
    cout << "\nArray after segregation: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " "; // Output each element of the modified array
    return 0;
}

