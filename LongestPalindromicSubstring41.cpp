#include <iostream>

using namespace std;

// Helper function to expand around the center and find the longest palindrome
int expandAroundCenter(const char* s, int left, int right, const int length, int& startIndex) {
    while (left >= 0 && right < length && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;
}

void longestPalindrome(const char* s) {
    int length = 0;
    
    // Find the length of the string manually (since we're not using <cstring>)
    while (s[length] != '\0') {
        length++;
    }

    int maxLength = 0;
    int startIndex = 0;

    for (int i = 0; i < length; i++) {
        // Check for odd-length palindromes (single center)
        int len1 = expandAroundCenter(s, i, i, length, startIndex);

        // Check for even-length palindromes (pair center)
        int len2 = expandAroundCenter(s, i, i + 1, length, startIndex);

        // Choose the longest length palindrome
        if (len1 > maxLength) {
            maxLength = len1;
            startIndex = i - len1 / 2;
        }
        if (len2 > maxLength) {
            maxLength = len2;
            startIndex = i - len2 / 2 + 1;
        }
    }

    // Output the longest palindromic substring
    for (int i = 0; i < maxLength; i++) {
        cout << s[startIndex + i];
    }
    cout << endl;
}

int main() {
    // Input: C-style string
    char s[11];
    cin >> s;  // Read string of length 10 or less

    // Find and print the longest palindrome substring
    longestPalindrome(s);

    return 0;
}
