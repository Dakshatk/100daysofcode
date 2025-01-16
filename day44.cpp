#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to check if there's a path from top-left to bottom-right
bool canEscape(const vector<vector<int>>& grid, int n) {
    // Directions for moving up, down, left, and right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Edge case: If the starting or ending cell is blocked
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return false;
    }

    // Queue for BFS
    queue<pair<int, int>> q;
    q.push({0, 0});

    // Visited grid to prevent re-visiting cells
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // If we reach the bottom-right corner, return true
        if (x == n - 1 && y == n - 1) {
            return true;
        }

        // Explore all possible directions
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            // Check if the new position is within bounds, not blocked, and not visited
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0 && !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }

    // If we exhaust all possibilities and do not reach the bottom-right corner, return false
    return false;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Size of the grid

        // Read the grid
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        // Check if escape is possible and print the result
        if (canEscape(grid, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
