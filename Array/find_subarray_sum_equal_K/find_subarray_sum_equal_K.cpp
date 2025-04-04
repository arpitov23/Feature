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

int find_all_subarray_with_given_sum(vector<int>& arr, int target)
{
    int n = arr.size();
    map<int, int> mpp;
    int preSum = 0;
    int cnt = 0;

    mpp[0] = 1; // setting 0 in the map

    for (int i = 0; i < n; i++)
    {
        // add current element to prefix sum
        preSum = preSum + arr[i];

        // calculate x-target

        int remove = preSum - target;

        // add the number of subarrays to be removed
        cnt = cnt + mpp[remove];

        //update the count of prefix sum in the map 

        mpp[preSum] = mpp[preSum] + 1;
    }
    return cnt;
}

int main()
{
    vector <int>arr = { 3, 1, 2, 4 };
    int k = 6;
    int cnt = find_all_subarray_with_given_sum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

