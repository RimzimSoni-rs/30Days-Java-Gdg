#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<char*> &strs, int n) {
    if (n == 0) {
        return "";
    }

    // Assume the first string is the common prefix initially
    char* prefix = strs[0];

    // Loop through the rest of the strings
    for (int i = 1; i < n; i++) {
        int j = 0;
        // Compare the current prefix with each string character by character
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }

        // Terminate the prefix at the common part
        prefix[j] = '\0';

        // If at any point, the prefix becomes empty, return empty string
        if (prefix[0] == '\0') {
            return "";
        }
    }

    return string(prefix); // Convert char* to string before returning
}

int main() {
     int n;
    cin >> n;  // Input the number of strings

    vector<char*> strs(n);
    for (int i = 0; i < n; i++) {
        char* str = new char[201]; // Allocate memory for each string
        cin >> str;  // Input the string
        strs[i] = str;
    }

    // Output the longest common prefix
    cout << longestCommonPrefix(strs, n) << endl;

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] strs[i];
    } 
    return 0;
}
