// Equilibrium_Point_mean_sumofLEFT_equal_sumofRIGHT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
  Description - Equilibrium Point mean sum of left element is equal to sum of right element.
                In other words, the sum of elements before index i is equal to the sum of elements after index i.
  
  Approach -

  -> Compute the total sum of array
  -> Traverse the array while maintaining the sum of elements to the left of the current index.
  -> For each index i, check if the sum of element on the left is equal to the sum of elements on the right.
         1. Sum of elements on left = left_sum
         2. Sum of elements on right = total_sum - left_sum - arr[i]
  -> If left_sum == right_sum, then i is the equilibrium point
*/
#include <iostream>
using namespace std;

int equilibrium_point(int arr[], int n)
{
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
        cout << "Grand total sum = " << total_sum << endl;
    }

    //initiate the left sum to 0

    int left_sum = 0;

    for (int i = 0; i < n; i++)
    {
        // update the total sum to the right of the current element
        total_sum -= arr[i];
        cout << "total sum = " << total_sum << endl;

        // check if the left sum equals to the right sum

        if (left_sum == total_sum) {
            cout << "index " << i << endl;
            return i; // the equilibrium_point is found at index i
        }

        // update left_sum for the next iteration
        left_sum += arr[i];
        cout << "left_sum = " << left_sum << endl;
    }
    return -1; // no equilibrium_point found
}
int main()
{

    int arr[] = { 1 ,3 ,5, 2, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = equilibrium_point(arr, n);
    cout << "result = " << result << endl;

    return 0;
}

