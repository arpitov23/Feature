// Detect_all_unique_or_non_repeat_character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

void find_all_unique_character(const string& str)
{
    unordered_map<char, int> freq;

    for (char ch : str)
	{
		freq[ch]++;

	}
	cout << "Unique characters in the string: ";
	for (const auto& pair : freq)
	{
		if (pair.second == 1)
		{
			cout << pair.first << " ";
			
		}
	}
	cout << endl;
}
int main()
{
 
	string input = "leetcode";
	find_all_unique_character(input);

	return 0;
}

