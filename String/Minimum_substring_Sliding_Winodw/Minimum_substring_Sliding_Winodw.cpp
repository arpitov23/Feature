// Minimum_substring_Sliding_Winodw.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// input - timetopractice
// substr - toc
// output - toprac


#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX
#include <unordered_map>
using namespace std;

string min_substring(string str, string ptr) {
    // Edge cases
    if (str.empty() || ptr.empty() || str.length() < ptr.length()) {
        return "";
    }

    // frequency map for character in ptr
    unordered_map<char, int> freq_ptr;
    for (char c : ptr)
        freq_ptr[c]++;

    //variable for sliding window
    int required = freq_ptr.size(); // number of unique char in ptr
    int formed = 0; // number of character formed
    unordered_map<char, int> window_freq;  // frequency map for window

    // window boundaries
    int left = 0;
    int right = 0;
    int min_len = INT_MAX;
    int min_left = 0;

    // slide the window
    while (right < str.size()) {

        // add right character to window
        char c = str[right];
        window_freq[c]++;

        // check if current character contrinut to matching ptr
        if (freq_ptr.count(c) && window_freq[c] == freq_ptr[c]) {
            formed++;
        }

        // try to shrink the window from left to right
        while (left <= right && formed == required) {
            // update minimum window
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            // remove left character from window
            char left_char = str[left];
            window_freq[left_char]--;

            // check if removing leftchar break the match
            if (window_freq[left_char] < freq_ptr[left_char] && freq_ptr.count(left_char)) {
                formed--;
            }
            left++;
        }
        right++;
    }

    return min_len == INT_MAX ? "" : str.substr(min_left, min_len);



}

string small_substring(string str, string ptr) {
    // Edge cases
    if (str.empty() || ptr.empty() || str.length() < ptr.length()) {
        return "";
    }

    // Frequency arrays for ASCII characters (256 size for simplicity)
    vector<int> count_ptr(256, 0); // Frequency of characters in ptr
    vector<int> count_str(256, 0); // Frequency of characters in current window

    // Store frequency of each character in ptr
    for (char c : ptr) {
        count_ptr[c]++;
    }

    int len1 = str.length();
    int len2 = ptr.length();
    int required = 0; // Count of unique characters in ptr
    for (int i = 0; i < 256; ++i) {
        if (count_ptr[i] > 0) {
            required++;
        }
    }

    int start = 0; // Left pointer of window
    int start_index = -1; // Start index of minimum window
    int min_len = INT_MAX; // Length of minimum window
    int formed = 0; // Number of characters matched

    // Slide the window
    for (int j = 0; j < len1; ++j) {
        // Add current character to window
        char c = str[j];
        count_str[c]++;

        // Check if current character contributes to matching ptr
        if (count_ptr[c] > 0 && count_str[c] == count_ptr[c]) {
            formed++;
        }

        // Shrink the window from the left while maintaining a valid window
        while (start <= j && formed == required) {
            // Update minimum window
            int curr_len = j - start + 1;
            if (curr_len < min_len) {
                min_len = curr_len;
                start_index = start;
            }

            // Remove leftmost character
            char left_char = str[start];
            count_str[left_char]--;

            // Check if removing left_char breaks the match
            if (count_ptr[left_char] > 0 && count_str[left_char] < count_ptr[left_char]) {
                formed--;
            }
            start++;
        }
    }

    // Return the minimum window or empty string if not found
    return start_index == -1 ? "" : str.substr(start_index, min_len);
}

int main() {
    // Test cases
    vector<pair<string, string>> testCases = {
        {"timetopractice", "toc"}, // Expected: "toprac"
        {"ADOBECODEBANC", "ABC"}, // Expected: "BANC"
        {"a", "a"},               // Expected: "a"
        {"a", "b"},               // Expected: ""
        {"aa", "aa"},             // Expected: "aa"
        {"", "a"},                // Expected: ""
        {"ab", "a"}               // Expected: "a"
    };

    for (const auto& test : testCases) {
        string str = test.first;
        string ptr = test.second;
        string res = small_substring(str, ptr);
        string min_substr = min_substring(str, ptr);
        cout << "minimum substring using sliding window: " << min_substr<<endl; 
        cout << "Input: str = \"" << str << "\", ptr = \"" << ptr << "\"\n";
        cout << "Output: \"" << res << "\"\n\n";
    }

    return 0;
}