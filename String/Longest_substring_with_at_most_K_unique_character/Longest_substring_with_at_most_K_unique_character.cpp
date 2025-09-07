// Longest_substring_with_at_most_K_unique_character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

#include <string>
using namespace std;


int longest_substr_Kth_unique_character(const string& str, int k)
{
	if (str.empty()) return 0;
	int n = str.length();

	int start = 0;
	int max_len = -1;
	int unique_count = 0;

	unordered_map<char, int> freq;

	for (int i = 0; i < n; i++) {

		// include current character in window
		char current_char = str[i];

		freq[current_char]++;

		// if this is the first occurrence of the character then increment the unique count

		if (freq[current_char] == 1) {
			unique_count++;
		}

		// if unique count exceeds k, then shrink the window from the left
		while (unique_count > k)
		{
			char left_char = str[start];
			freq[left_char]--;

			// if the frequency of the left character becomes zero, then it means we have removed a unique character
			if (freq[left_char] == 0) {
				unique_count--;
			}
			start++; // shrink the window from the left
		}
		// if we have exactly k unique characters, then update the max length
		if (unique_count == k)
		{
			max_len = max(max_len, i - start + 1);
		}

	}
	return max_len;

}
int main()
{
    
	string str = "aabacbebebe";
	int k = 3; // Number of unique characters allowed
	int result = longest_substr_Kth_unique_character(str,k);
	cout << "Length of the longest substring with at most " << k << " unique characters: " << result << endl;
	return 0;
}
