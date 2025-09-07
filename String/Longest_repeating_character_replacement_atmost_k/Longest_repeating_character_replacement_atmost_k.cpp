#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0); // Frequency array for uppercase letters A-Z
    int maxLen = 0;          // Length of longest valid substring
    int maxFreq = 0;         // Maximum frequency of any character in current window
    int left = 0;            // Left pointer of sliding window

    for (int right = 0; right < s.length(); ++right) {
        // Increment frequency of current character
        freq[s[right] - 'A']++;
        // Update max frequency in current window
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // If window size minus max frequency exceeds k, we need more than k replacements
        // Shrink the window
        if ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        // Update max length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    string s = "XYYX";
    int k = 2;

    int res = characterReplacement(s, k);
    cout << "longest repeat character replacement with atmost k : " << res;
    
    return 0;
}