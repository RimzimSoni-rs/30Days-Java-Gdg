#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, int n, int maze[][10], bool visited[][10]) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMaze(int x, int y, int n, int maze[][10], bool visited[][10], pair<int, int> path[], int& pathIndex) {
    // Base condition: If we reach the bottom-right corner (n-1, n-1)
    if (x == n - 1 && y == n - 1) {
        path[pathIndex++] = {x, y};
        return true;
    }

    // If the current position is safe, mark it as visited
    if (isSafe(x, y, n, maze, visited)) {
        visited[x][y] = true;
        path[pathIndex++] = {x, y};

        // Move right
        if (solveMaze(x, y + 1, n, maze, visited, path, pathIndex))
            return true;

        // Move down
        if (solveMaze(x + 1, y, n, maze, visited, path, pathIndex))
            return true;

        // If neither move works, backtrack and remove the current cell from the path
        pathIndex--;
        visited[x][y] = false;
    }

    return false;
}

int main() {
int n;
    cin >> n;

    int maze[10][10];
    bool visited[10][10] = {false};

    // Read the maze
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    pair<int, int> path[100];  // Maximum path size (in the worst case, the path length could be n*n)
    int pathIndex = 0;

    // Start solving from the top-left corner (0, 0)
    if (solveMaze(0, 0, n, maze, visited, path, pathIndex)) {
        cout << "YES" << endl;
    } 
           
     else {
        cout << "NO" << endl;
    }    return 0;
}