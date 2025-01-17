#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int findKthMissingPositiveNumber(int arr[], int n, int k) {
    int missingCount = 0;
    int current = 1;
    int i = 0;
    
    while (missingCount < k) {
        if (i < n && arr[i] == current) {
            // Skip the number in the array
            i++;
        } else {
            // The current number is missing from the array
            missingCount++;
            if (missingCount == k) {
                return current;
            }
        }
        current++;
    }
    
    return -1; // In case no solution is found, though this is unlikely with the given constraints
}

int main() {
    int n, k;
    
    // Input size of the array
    cin >> n;
    
    // Create an array to store the elements
    int arr[n];
    
    // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Input the value of k
    cin >> k;
    
    // Find the kth missing positive integer
    cout << findKthMissingPositiveNumber(arr, n, k) << endl;
    
    return 0;
}
