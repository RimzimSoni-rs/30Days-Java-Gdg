#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


//function to sort the array according to colors.
    void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
     int n;
    cin >> n;  
    int nums[n];
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    
    sortColors(nums, n);  
    
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";  
    }
     
    return 0;
}