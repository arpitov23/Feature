// Minimum_Consecutive_Flips.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int min_flip(int arr[], int n)
{

	if (n == 0)
		return 0;  // if array is empty, no flip

	// initialize the counts of flips

		int flip_to_zeros = 0;
		int flip_to_ones = 0;

		// Track the previous element for comparasion

		for (int i = 1; i < n; ++i)
		{

			// count block of 1's to flip to 0

			if (arr[i] == 1 && arr[i - 1] == 0)
			{
				flip_to_zeros++;
				cout << "flips_to_zeros : " << flip_to_zeros<<endl ;
			}

			// count block of 0's to flip tp 1

			if (arr[i] == 0 && arr[i - 1] == 1)
			{
				flip_to_ones++;
				cout << "flips_to_ones : " << flip_to_ones << endl;
			}
		}

		// check for a block at the start of the array 

		if (arr[0] == 1) {
			flip_to_zeros++; // if the first element is 1, it's a new block
			cout << "first element is 1 then flip to zero- " << flip_to_zeros << endl;
		}


		if (arr[0] == 0) {
			flip_to_ones++; // if the first element is 0, it's a new block
			cout << "first element is 0 then flip to one - " << flip_to_ones << endl;
		}

		// Return the minmium number of flips is needed

		return (flip_to_zeros < flip_to_ones) ? flip_to_zeros : flip_to_ones;

}

int main()
{
	int arr[] = { 1, 0, 1, 0, 1 ,0};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum flips required: " << min_flip(arr, n) << endl;

	return 0;
}

