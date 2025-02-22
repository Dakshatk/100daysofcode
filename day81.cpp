#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, int m, int n, vector<vector<char>>& grid) {
    // Boundary and validity check
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
        return;
    
    // Mark the current cell as visited
    grid[i][j] = '2';
    
    // Explore all four adjacent directions
    dfs(i + 1, j, m, n, grid);
    dfs(i - 1, j, m, n, grid);
    dfs(i, j + 1, m, n, grid);
    dfs(i, j - 1, m, n, grid);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int m, n;
        cin >> m >> n;
        
        // Read the grid
        vector<vector<char>> grid(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int villages = 0;
        // Iterate over every cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    // New village found, use DFS to mark the entire village
                    villages++;
                    dfs(i, j, m, n, grid);
                }
            }
        }
        
        // Output the number of villages for the current test case
        cout << villages << "\n";
    }
    
    return 0;
}