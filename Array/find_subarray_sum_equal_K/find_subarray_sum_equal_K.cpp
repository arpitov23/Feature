// find_subarray_sum_equal_K.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*

Input - 3, 1, 2, 4
K - 6

output - number of subarray is 2 (index 2nd and 3rd)

Input - 1, 1, 1
K = 2;

output - number of subarray is 2 (index 1st and 2nd )

-------- approach ------------
In this approach, we are going to use the concept of the prefix sum to solve this problem. Here, the prefix sum of a subarray ending 
at index i simply means the sum of all the elements of that subarray.

->  First, we will declare a map to store the prefix sums and their counts.
->  Then, we will set the value of 0 as 1 on the map.
->  Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
->  For each index i, we will do the following:
->  We will add the current element i.e. arr[i] to the prefix sum.
->  We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
->  We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
->  Then we will store the current prefix sum in the map increasing its occurrence by 1.


*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// sliding window technique

void find_all_subarray_or_count_subarray(vector<int>& arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int start = 0;
    int count = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
		while (sum > k && start < i) {
			sum = sum - arr[start];
			start++;
		}

		if (sum == k) {
            count++;
			found = true;
			cout << "Subarray found from index " << start << " to " << i << "\n";
		}

        
    }
	cout << "Total subarrays with sum " << k << ": " << count << "\n";
}


int main()
{
    vector <int>arr = { 11,12,5,6,3,2,9,-1};
    int k = 11;
    find_all_subarray_or_count_subarray(arr,  k);

    return 0;
}

