#include <iostream>
#include <vector>
using namespace std;

int countNeighbors(const vector<vector<int>>& grid, int x, int y, int m, int n) {
    int count = 0;
    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    for (auto& dir : directions) {
        int nx = x + dir[0];
        int ny = y + dir[1];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
            count++;
        }
    }

    return count;
}

vector<vector<int>> nextState(const vector<vector<int>>& grid, int m, int n) {
    vector<vector<int>> newGrid(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int neighbors = countNeighbors(grid, i, j, m, n);

            if (grid[i][j] == 1) {
                if (neighbors == 2 || neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
    }

    return newGrid;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> grid(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> result = nextState(grid, m, n);

        for (const auto& row : result) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
