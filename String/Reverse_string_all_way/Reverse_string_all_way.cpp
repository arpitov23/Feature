// Reverse_string_all_way.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void rev(string& str, int start, int end)
{
    while (start < end)
    {
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
    }
}

string rev_whole_word(string& str)   // arpit sharma - sharma arpit
{
	rev(str, 0, str.length() - 1); // Reverse the entire string
	int n = str.length();
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == n || str[i] == ' ')
		{
			rev(str, start, i - 1); // Reverse the word
			start = i + 1; // Move to the next word
		}
	}
	return str;
}


string rev_in_place(string& str) // arpit sharma - tipra amrahs
{
	
	int n = str.length();
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		// if we find a space or end of string reverse the word 
		if (i == n || str[i] == ' ')
		{
			
			rev(str, start, i - 1); // swap character from start to end of word 
			start = i + 1;   // move to next word
			
			
		}
	}
	return str;
}

int main()
{
	string str = "i love programming";
	cout << "Original string: " << str << endl;
	string reversed = rev_whole_word(str);  // programming love i
	cout << "Reversed string: " << reversed << endl;
	string str2 = "hello world";
	string str_2 = rev_in_place(str2);  // programming love i
	cout << "Reversed in place string: " << str_2 << endl;
}

