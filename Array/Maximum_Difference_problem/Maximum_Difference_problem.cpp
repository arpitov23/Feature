// Maximum_Difference_problem.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Note --- largest difference between two elements where the second element occurs later in the array than the first one.
/*
    The Maximum Difference Problem typically asks you to find the maximum difference between two elements in an array 
    such that the larger element appears after the smaller element. Specifically, you're given an array of integers, 
    and you want to find the maximum value of arr[j] - arr[i] where i < j. 
    In other words, you're looking for the largest difference between two elements where the second element occurs later in the array than the first one.
*/



#include <iostream>
using namespace std;

int find_max_diff_prob(int arr[], int size)
{
    if (size < 2)
        return 0;

    int min_element = arr[0]; // Initialize first element as minimum element 
    int max_difference = INT_MIN; // variable to store max difference 

    //Iterate the array starting from the second element 
    for (int i = 1; i < size; i++)
    {
        int diff = arr[i] - min_element; // calculate the difference between the current element and minimum element 
        if (diff > max_difference)
        {
            max_difference = diff;      //  update the max difference if current difference is larger
        }

        if (arr[i] < min_element)
        {
            min_element = arr[i];      //  update the minimum element if current element is smaller 
        }
    }
    return max_difference; 
}
int main()
{
    int arr[] = { 7, 1, 5, 3, 6, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = find_max_diff_prob(arr, size);
    cout << "max difference between two element is " << result << endl;
    return 0;
}
