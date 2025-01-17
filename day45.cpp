#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
    int x, y, civilians;
};

int dx[] = {-1, 1, 0, 0}; // Directions for moving up, down, left, and right
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 2 && !visited[x][y];
}

int maxCiviliansRescued(vector<vector<int>>& grid, int n) {
    int maxCivilians = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                // BFS to calculate civilians rescued from this starting point
                queue<State> q;
                q.push({i, j, 0});
                vector<vector<bool>> localVisited(n, vector<bool>(n, false));
                localVisited[i][j] = true;

                int civilians = 0;

                while (!q.empty()) {
                    State current = q.front();
                    q.pop();

                    if (grid[current.x][current.y] == 1) {
                        civilians++;
                    }

                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = current.x + dx[dir];
                        int ny = current.y + dy[dir];

                        if (isValid(nx, ny, n, grid, localVisited)) {
                            localVisited[nx][ny] = true;
                            q.push({nx, ny, civilians});
                        }
                    }
                }

                maxCivilians = max(maxCivilians, civilians);
            }
        }
    }

    return maxCivilians;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << maxCiviliansRescued(grid, n) << endl;
    }

    return 0;
}
