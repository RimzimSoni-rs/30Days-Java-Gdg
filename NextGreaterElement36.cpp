#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  // Initialize the result vector with -1
    stack<int> s;  // Stack to store elements while finding the next greater element

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are smaller or equal to the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the top element is the next greater element
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;  // Input the size of the array
    vector<int> arr(n);

    // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the result array with the next greater elements
    vector<int> result = nextGreaterElement(arr);

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
