#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string removeKdigits(string num, int k) {
    int n = num.length();
    string result = "";
    
    // Loop through each character in the input string
    for (int i = 0; i < n; i++) {
        // Try to remove digits to make the number smaller
        while (k > 0 && !result.empty() && result.back() > num[i]) {
            result.pop_back();
            k--;
        }
        result.push_back(num[i]);
    }
    
    // Remove any remaining digits if k is still greater than 0
    while (k > 0) {
        result.pop_back();
        k--;
    }
    
    // Remove leading zeros
    int i = 0;
    while (i < result.length() && result[i] == '0') {
        i++;
    }
    
    result = result.substr(i);  // Substring without leading zeros
    
    // If the result is empty, return "0"
    return result.empty() ? "0" : result;
}

int main() {
 string num;
    int k;
    
    // Read input
    cin >> num;
    cin >> k;
    
    // Get the result and print it
    cout << removeKdigits(num, k) << endl;    return 0;
}