// Frequency_count_in_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Time Complexity: O(n + max_val)
				O(n) for counting the frequencies.
				O(max_val) for printing the frequencies of elements.

Space Complexity: O(n + max_val)
				O(n) for the input array.
				O(max_val) for the frequency array.

*/
#include <iostream>
using namespace std;
int main()
{
	int arr[] = { 3,2,2,3,3,4,4,4,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int count = 0;

	const int max_val = 1000; // maximum possible value in array (we can adjust based on user input)

	int freq[max_val + 1] = { 0 }; // for value between 0 and max_val

	//count the frequency of each element 
	for (int i = 0; i < n; i++)
	{
		freq[arr[i]]++;
	}


	// Display the frequency of each element 

	for (int i = 0; i <= max_val; i++)
	{
		if (freq[i] > 0)
		{
			cout << "Element: " << i << ", Frequency: " << freq[i] << endl;
		}
	}
	return 0;
}

/*
Time Complexity : O(n)
Auxiliary Space : O(n)

void count_fre(int arr[], int size)
{
    unordered_map<int, int>mp;

    for (int i 0 ; i < n ; i++)
	{
	   mp[arr[i]]++;
	}

	// display frequency
	for (auto x:mp)
	  cout <<x.first <<" " <<x.second<<endl;
}




*/