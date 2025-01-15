#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findFloor(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x) {
            result = mid;  // update result to mid since arr[mid] <= x
            left = mid + 1; // search the right half for a potentially larger floor
        } else {
            right = mid - 1; // search the left half
        }
    }

    return result;
}


int main() {
      int n, x;
    cin >> n;
    
    if (n == 0) {
        cout << -1 << endl; // No elements in the array
        return 0;
    }

    int arr[n]; // Declare the array of size n
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Input elements in the array
    }

    cin >> x; // Input the target value to find the floor

    int index = findFloor(arr, n, x);
    cout << index << endl; // Output the index of the floor value (or -1 if no floor is found)

   
    return 0;
}
