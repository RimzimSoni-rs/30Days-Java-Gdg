#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Interval { int start; int end; };

bool compare(Interval a, Interval b) { return a.end < b.end; }


int eraseOverlapIntervals(Interval intervals[], int n) {
    if (n == 0) return 0; // If there are no intervals, return 0
    sort(intervals, intervals + n, compare); // Sort intervals based on their end times
    int count = 0;
    int end = intervals[0].end; // Start with the first interval's end time
    for (int i = 1; i < n; ++i) {
        if (intervals[i].start < end) { // If there's overlap
            count++; // Increment the removal count
        } else {
            end = intervals[i].end; // Update the end time for the next interval
        }
    }
    return count; // Return the number of intervals to remove
}

int main() {
     int n;
    cin >> n; 
    Interval intervals[n]; 
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].start >> intervals[i].end; 
    }
    cout << eraseOverlapIntervals(intervals, n) << endl; 
    return 0;
    
}
