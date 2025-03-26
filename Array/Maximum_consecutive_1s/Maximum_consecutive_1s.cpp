// Maximum_consecutive_1s.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*

To find the maximum number of consecutive 1s in an array

input nums = {1, 1, 0, 1, 1, 1}
Maximum consecutive 1's: 3  (from index 3rd to 5th)


*/

#include <iostream>
using namespace std;

int max_consecutive_1s(int arr[], int n)
{
    int max_count = 0;  // To store the maximum count of consecutive 1s
    int current_count = 0; // To store the current count of consecutive 1s.

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            current_count++; // If the current number is 1, increment the current count
        }
        else
        {
             // If it's a 0, update the max count and reset the current_count 
            if (current_count > max_count)
            {
                max_count = current_count;   // This will store the current_count of 1 in max_count variable in case 0 will occur
            }
            current_count = 0; // Reset the count  // after if condition again current_count reset to 0 and start from the begining
        }
    }

    // Final check in case the arrat end with a sequence of 1s
    if (current_count > max_count)
        max_count = current_count;

    return max_count;
}
int main()
{
    // Example input array
    int nums[] = { 1, 1, 0, 1, 1, 1 };
    int size = sizeof(nums) / sizeof(nums[0]);  // Calculate size of the array

    int result = max_consecutive_1s(nums, size);
    cout << "Maximum consecutive 1's: " << result << endl;

    return 0;
}

