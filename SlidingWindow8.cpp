#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

void maxSlidingWindow(int nums[], int n, int k) {
    deque<int> dq; // To store indices of useful elements in the window
    
    for (int i = 0; i < n; ++i) {
        // Remove elements from deque that are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove all elements smaller than the current element nums[i]
        // from the back of the deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add current element index to the deque
        dq.push_back(i);

        // If we've processed at least 'k' elements, the front of the deque is the largest element in the window
        if (i >= k - 1) {
            cout << nums[dq.front()] << " ";
        }
    }
}


int main() {
    int n, k;
    cin >> n;
    int nums[n];  // Raw array for input
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> k;

    maxSlidingWindow(nums, n, k);   
    return 0;
}