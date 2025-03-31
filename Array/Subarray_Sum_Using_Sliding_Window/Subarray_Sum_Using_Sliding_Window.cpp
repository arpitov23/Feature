// Subarray_Sum_Using_Sliding_Window.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool subarray_sum_sliding_window(int arr[], int n, int target, int& start_index, int& end_index)
{

	int start = 0;
	
	int current_sum = 0;

	for (int i = 0; i < n; i++)
	{
		current_sum = current_sum + arr[i]; // add current element to current sum

	    // shrink the window 
		while (current_sum > target && start <= i)
		{
			current_sum = current_sum - arr[start];
			start++;
		}

		// current sum matches
		if (current_sum == target)
		{
			start_index = start;
			end_index = i;
			return true;
		}
	}
	return false;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 12;
	int start_index , end_index = -1;
	if (subarray_sum_sliding_window(arr, n, target, start_index , end_index)) {
		cout << "Subarray with the given sum exists with index value " << start_index <<" to "<< end_index << endl;
	}
	else {
		cout << "No subarray with the given sum." << endl;
	}

	return 0;
}

