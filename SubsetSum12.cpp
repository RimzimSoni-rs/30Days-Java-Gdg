#include <iostream>
using namespace std;

// Bubble sort function to sort the sums
void bubbleSort(int sums[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sums[j] > sums[j + 1]) {
                // Swap the elements if they're in the wrong order
                int temp = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = temp;
            }
        }
    }
}

int* subsetSums(int n, int arr[], int& resultSize) {
    int numSubsets = 1 << n;  // 2^n subsets
    int* sums = new int[numSubsets]; // Dynamically allocated array for storing sums
    resultSize = numSubsets;  // Store the number of sums (subsets)

    // Generate all subsets and calculate their sums
    for (int mask = 0; mask < numSubsets; ++mask) {
        int sum = 0;
        
        // For each bit in the bitmask, add the corresponding element if the bit is set
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        
        sums[mask] = sum;  // Store the sum of the current subset
    }
    
    // Sort the sums using bubble sort
    bubbleSort(sums, numSubsets);
    
    return sums;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // Read the array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int resultSize;
    int* result = subsetSums(n, arr, resultSize);
    
    // Output the result
    for (int i = 0; i < resultSize; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    // Free dynamically allocated memory
    delete[] result;

    return 0;
}
