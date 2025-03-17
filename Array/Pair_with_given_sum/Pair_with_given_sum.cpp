// Pair_with_given_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*----------------Using 2 pointer approach----------------
-> Sort the array: First, sort the array so that we can use two pointers.
-> Initialize two pointers: Place one pointer at the beginning (left) and the other at the end (right) of the array.
-> Check the sum: Check the sum of the elements at the two pointers:
-> If the sum is equal to K, you’ve found the pair.
-> If the sum is less than K, move the left pointer to the right to increase the sum.
-> If the sum is greater than K, move the right pointer to the left to decrease the sum.
-> Repeat until the pointers cross: Continue until the left pointer is no longer less than the right pointer.

*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

pair<int, int> find_pair_with_sum(vector<int>& arr, int k)
{
    // step 1 : Sort the array 
    sort(arr.begin(), arr.end());

    // step 2 : Initialize 2 pointer
    int left = 0;
    int right = arr.size() - 1;

    //step 3 : Use the 2 pointer technique
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == k)        
            return { arr[left],arr[right] };  

        else if (sum < k)
            left++; //Increase the pair

        else
            right--;
    }
    return { -1, - 1 }; // No pair found

}
int main()
{
    vector<int> arr = { 10, 2, 3, 5, 7, 4 };
    int K = 12;

    pair<int, int> result = find_pair_with_sum(arr, K);

    if (result.first != -1 && result.second != -1) {
        cout << "Pair found: (" << result.first << ", " << result.second << ")\n";
    }
    else {
        cout << "No pair found\n";
    }

    return 0;
}


/*
   Approach 2 - Using Hash_Set


pair<int, int> findPairWithSum(const vector<int>& arr, int K) {
    unordered_set<int> seen;

    for (int num : arr) {
        int target = K - num;
        if (seen.find(target) != seen.end()) {
            // Pair found
            return {num, target};
        }
        seen.insert(num);
    }

    // No pair found
    return {-1, -1};  // return a pair indicating no pair was found
}


*/