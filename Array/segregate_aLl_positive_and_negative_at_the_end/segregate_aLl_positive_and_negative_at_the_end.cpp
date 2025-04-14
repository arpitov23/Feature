// segregate_aLl_positive_and_negative_at_the_end.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


// Method 1 : Using temporary array  (maintain relative order)
/*
void segregate_elements(int arr[], int n)
{
    int* temp = new int[n];
  
  
    int j = 0;

    // First store non-negative elements
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    // Then store negative elements
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
*/

// Method 2: Two-pointer approach (in-place but doesn't maintain order)
void moveNegativesToEndInPlace(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Find negative number from left
        while (left < right && arr[left] >= 0) {
            left++;
        }

        // Find non-negative number from right
        while (left < right && arr[right] < 0) {
            right--;
        }

        // Swap if we found a pair
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
}


int main()
{
    int nums[] = { 0, 9, -7, 2, -12, 11, -20 }; // Declaration and initialization of an integer array
    int n = sizeof(nums) / sizeof(nums[0]); // Calculate the number of elements in the array
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " "; // Output each element of the original array

  //  segregate_elements(nums, n); // Segregate positive and negative elements in the array
    moveNegativesToEndInPlace(nums, n);
    cout << "\nArray elements after rearrange: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " "; // Output each element of the modified array after rearrangement
    return 0;
}

