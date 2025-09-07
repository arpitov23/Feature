// Longest_Substring_With_Unique_or_Without_repeating_character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest substring with unique characters

int longestUniqueSubstring(const string& str) {
	vector<int> vec(256, -1); // Store the last index of each character
	int maxLength = 0;
	int start = 0; // Start index of the current substring

	for (int i = 0; i < str.length(); i++) {
		if (vec[str[i]] >= start) {  // -  vec['g'] = -1,because in first iterate all set to -1. So vec['g'] = vec[-1] >= start
										// which is less than start = 0 (no previous occurrence).

			start = vec[str[i]] + 1; // Move start to the next position after the last occurrence
		}
		vec[str[i]] = i; // vec['g'] = vec[0] - In first iteration- then Update the last index of the character
		maxLength = max(maxLength, i - start + 1); // Update max length
	}

	return maxLength;
}


int longest_substr( string& str)
{
	if (str.length() == 0 || str.length() == 1)
		return str.length();
	int res=0; 
	int left = 0; 
	int right = 0;
	vector <bool> vec(26, false);

	while (right < str.length())
	{
		// If character is repeated, move left pointer marking
		   // visited characters as false until the repeating 
		   // character is no longer part of the current window
		while (vec[str[right] - 'a'] == true) {

			vec[str[left] - 'a'] = false;
			left++;
		}

		vec[str[right] - 'a'] = true;

		res = max(res, (right - left + 1));
		right++;
	}
	return res;

}
int main()
{
	string input = "geeksforgeeks";
	
	//int result = longestUniqueSubstring(input);
	int result = longest_substr(input);
	cout << "Length of the longest substring with unique characters: " << result << endl;
	return 0;
}

