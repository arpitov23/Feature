// 2Sum_difference_equal_to_target.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to count pair with absolute difference K

int count_pair_with_diff_K(vector<int>& arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    int cnt = 0;

    for (int i = 0; i < n; i++) {

        // Check if the complement (arr[i] + k)
        // exists in the map. If yes, increment count
		if (freq.find(arr[i] + k) != freq.end()) // check if the key exists
			cnt += freq[arr[i] + k];  // increment count by the frequency of the complement

        // Check if the complement (arr[i] - k)
        // exists in the map. If yes, increment count
		if (freq.find(arr[i] - k) != freq.end()) // check if the key exists
            cnt += freq[arr[i] - k];

        // Increment the frequency of arr[i]
        freq[arr[i]]++;
    }
    return cnt;
}

int main()
{
	// Example usage
	vector<int> arr = { 1, 5, 3, 4, 2 };
	int k = 2;

	cout << "Number of pairs with absolute difference " << k << ": ";
	cout << count_pair_with_diff_K(arr, k) << endl;

	return 0;
}

