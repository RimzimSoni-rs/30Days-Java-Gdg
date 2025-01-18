#include <iostream>
#include <algorithm>
using namespace std;

// Function to check if it's possible to eat all bananas in 'k' hours at a speed of 'speed'
bool canFinish(int piles[], int N, int K, int speed) {
    int hours = 0;
    for (int i = 0; i < N; i++) {
        hours += (piles[i] + speed - 1) / speed;  // Calculate the number of hours needed to finish this pile
    }
    return hours <= K;  // Check if the total hours is within the given limit
}

int main() {
    int N;  // Number of piles
    cin >> N;

    int piles[N];  // Array to store the number of bananas in each pile
    for (int i = 0; i < N; i++) {
        cin >> piles[i];  // Read the number of bananas in each pile
    }

    int K;  // Number of hours available to finish eating
    cin >> K;

    // Binary search for the minimum speed
    int left = 1, right = piles[0];
    for (int i = 1; i < N; i++) {
        right = max(right, piles[i]);  // Find the maximum pile size
    }
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, N, K, mid)) {
            result = mid;  // If it's possible to finish, try for a smaller speed
            right = mid - 1;
        } else {
            left = mid + 1;  // If it's not possible, try for a larger speed
        }
    }

    cout << result << endl;  // Output the minimum speed
    return 0;
}
