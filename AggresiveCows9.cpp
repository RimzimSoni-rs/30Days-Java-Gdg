#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int count = 1; // First cow is placed in the first stall
    int lastPlaced = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPlaced >= minDist) {
            count++;
            lastPlaced = stalls[i];
            if (count == k) return true; // All cows are placed
        }
    }
    return false;
}


int main() {
   int n, k;
    cin >> n;
    
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    
    cin >> k;
    
    // Sort the stall positions
    sort(stalls.begin(), stalls.end());
    
    // Binary search for the maximum minimum distance
    int low = 0, high = stalls[n-1] - stalls[0], result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canPlaceCows(stalls, k, mid)) {
            result = mid;  // We can place cows with at least 'mid' distance
            low = mid + 1; // Try for a larger minimum distance
        } else {
            high = mid - 1; // Try for a smaller minimum distance
        }
    }
    
    cout << result << endl;
    return 0;
}
