// First_repeat_and_Non-Repeat_character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Function to find the first non-repeating character in a string
int first_non_repeat(const string& str)
{
	vector<int> freq(256, 0); // Assuming ASCII characters

	// Count occurrences of each character
	for (char ch : str) {
		freq[ch]++;
	}

	// Find the first non-repeating character
	for(char ch:str){
		if (freq[ch] == 1) {
			cout << "First non-repeating character: " << ch << endl;
			return ch; // Return index of first non-repeating character
		}
		
	}

	return -1; // No non-repeating character found
}

int first_repeat(const string& str)
{
	vector<int> freq(256, 0); // Assuming ASCII characters

	// Count occurrences of each character
	for (char ch : str) {
		freq[ch]++;
	}

	// Find the first repeating character
	for (char ch : str) {
		if (freq[ch] > 1) {
			cout << "First repeating character: " << ch << endl;
			return ch; // Return index of first repeating character
		}
	}

	return -1; // No repeating character found
}


int reverse_array(int arr[], int n)
{
	int start = 0;
	int end = n - 1;

	while (start < end) {
		// Swap the elements at start and end
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		// Move towards the middle
		start++;
		end--;
	}

	return 0; // Return 0 to indicate successful reversal
}

int main()
{
	string str = "geeksforgeeks";
	int result = first_non_repeat(str);
	int result_repeat = first_repeat(str);
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	reverse_array(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;

}