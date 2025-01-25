#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

// Directions to move: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to check if the position is inside the grid
bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

// Function to perform BFS and find the minimum time for all fresh oranges to rot
int minTimeToRot(int grid[MAX][MAX], int m, int n) {
    int time = -1;
    bool freshOrangesExist = false;
    int rottenCount = 0;

    // Queue to store coordinates of rotten oranges
    int queue[MAX * MAX][2]; // (x, y) positions
    int front = 0, rear = 0;

    // Enqueue all the initial rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            } else if (grid[i][j] == 1) {
                freshOrangesExist = true;
            }
        }
    }

    // If no fresh oranges exist, return 0 as all are already rotten
    if (!freshOrangesExist) return 0;

    // Perform BFS
    while (front < rear) {
        int currLevelSize = rear - front;
        time++; // Increment the time at each level of BFS

        for (int i = 0; i < currLevelSize; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;

            // Check all 4 possible directions
            for (int dir = 0; dir < 4; dir++) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                if (isValid(newX, newY, m, n) && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Make the fresh orange rotten
                    queue[rear][0] = newX;
                    queue[rear][1] = newY;
                    rear++;
                }
            }
        }
    }

    // Check if there are any remaining fresh oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                return -1; // There are still fresh oranges left
            }
        }
    }

    return time;
}


int main() {
 int m, n;
    cin >> m >> n;

    int grid[MAX][MAX];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = minTimeToRot(grid, m, n);
    cout << result << endl;    return 0;
}
