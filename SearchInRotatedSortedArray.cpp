#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int search(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) return mid;
        
        if (nums[left] <= nums[mid]) {
            // Left part is sorted
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            // Right part is sorted
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n, target;
    cin >> n;
    int nums[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cin >> target;
    
    int result = search(nums, n, target);
    cout << result << endl;
    
    return 0;

}
