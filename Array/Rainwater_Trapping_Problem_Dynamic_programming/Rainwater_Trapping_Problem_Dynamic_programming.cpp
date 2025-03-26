// Rainwater_Trapping_Problem_Dynamic_programming.cpp : This file contains the 'main' function. Program execution begins and ends there.


/*

Problem Description:
    Given an array of non-negative integers representing the height of bars, where the width of each bar is 1, 
    compute how much water is trapped between these bars after raining.

Approach:
    To solve this problem efficiently, we need to compute the water trapped at each position. The water trapped at a particular index depends 
    on the heights of the tallest bars to the left and right of it. The formula is:

    Water at index i = min(max_left[i], max_right[i]) - height[i]
    Where:
         max_left[i] is the maximum height to the left of index i.
         max_right[i] is the maximum height to the right of index i.

Steps:
    -> Create two arrays max_left and max_right to store the maximum heights from the left and the right respectively.
    -> Traverse the array to fill these arrays.
    -> Traverse again to calculate the water trapped at each index.
    ->  Sum the trapped water for the final answer.

*/



#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int trapping_water(int height[], int size)
{
    if (size <= 2)
        return 0; // No water can be trapped with less than 3 bars , because as per logic of we need 3 bars for comparasion the index left and right

    int* left_max = new int[size];
    int* right_max = new int[size];
    int water_trapped = 0;

    // Initialize the left_max array

    left_max[0] = height[0];

    for (int i = 0; i < size; i++)
    {
        left_max[i] = std::max(left_max[i - 1], height[i]);
    }

    // Initialize the right_max array

    right_max[size - 1] = height[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // calculate the trapped water 

    for (int i = 0; i < size; i++) 
    {
        water_trapped = water_trapped + min(left_max[i], right_max[i]) - height[i];
    }

    return water_trapped;
}

int main()
{
    int height[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; // Example input
    int n = sizeof(height) / sizeof(height[0]);

    int result = trapping_water(height, n);
    cout << "Water trapped: " << result << endl; // Output the result - 6

    return 0;
}


/*

Dry Run - 

Input - 
        height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}

Step 1: Initialize Arrays
       
       left_max[0] = height[0] = 0
      
      Traverse left_max[]:

            left_max[1] = max(0, 1) = 1
            left_max[2] = max(1, 0) = 1
            left_max[3] = max(1, 2) = 2
            left_max[4] = max(2, 1) = 2
            left_max[5] = max(2, 0) = 2
            left_max[6] = max(2, 1) = 2
            left_max[7] = max(2, 3) = 3
            left_max[8] = max(3, 2) = 3
            left_max[9] = max(3, 1) = 3
            left_max[10] = max(3, 2) = 3
            left_max[11] = max(3, 1) = 3
      
      left_max[] = {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3}

      Traverse right_max[]:

            right_max[10] = max(1, 2) = 2
            right_max[9] = max(2, 1) = 2
            right_max[8] = max(2, 2) = 2
            right_max[7] = max(2, 3) = 3
            right_max[6] = max(3, 1) = 3
            right_max[5] = max(3, 0) = 3
            right_max[4] = max(3, 1) = 3
            right_max[3] = max(3, 2) = 3
            right_max[2] = max(3, 0) = 3
            right_max[1] = max(3, 1) = 3
            right_max[0] = max(3, 0) = 3

      right_max[] = {3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1}


Step 2: Calculate Water Trapped at Each Index

        Now we calculate the trapped water at each index:

        
        Formula = waterTrapped += min(max_left[i], max_right[i]) - height[i];
       
        left_max[] =  {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3}
        right_max[] = {3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1}
        height[] =    {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}

        Water at index 0 = min(0, 3) - 0 = 0
        Water at index 1 = min(1, 3) - 1 = 0
        Water at index 2 = min(1, 3) - 0 = 1
        Water at index 3 = min(2, 3) - 2 = 0
        Water at index 4 = min(2, 3) - 1 = 1
        Water at index 5 = min(2, 3) - 0 = 2
        Water at index 6 = min(2, 3) - 1 = 1
        Water at index 7 = min(3, 3) - 3 = 0
        Water at index 8 = min(3, 2) - 2 = 0
        Water at index 9 = min(3, 2) - 1 = 1
        Water at index 10 = min(3, 2) - 2 = 0
        Water at index 11 = min(3, 1) - 1 = 0


Step 3: Sum the Water Trapped

        Total water trapped = 0 + 0 + 1 + 0 + 1 + 2 + 1 + 0 + 0 + 1 + 0 + 0 = 6

        output: Water trapped: 6

Time Complexity:
        The time complexity of this solution is O(n) because we are making three passes over the array: one for filling max_left, 
        one for filling max_right, and one for calculating the water trapped at each index.

Space Complexity:
        The space complexity is O(n) because we are using two additional arrays max_left[] and max_right[], each of size n.

*/