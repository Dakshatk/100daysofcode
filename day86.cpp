#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;
vector<vector<char>> grid;

bool dfs(int i, int j, int index, const string &word, vector<vector<bool>> &visited) {
    if (index == static_cast<int>(word.size())) return true;
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (visited[i][j] || grid[i][j] != word[index]) return false;
    
    visited[i][j] = true;
    bool found = dfs(i + 1, j, index + 1, word, visited) ||
                 dfs(i - 1, j, index + 1, word, visited) ||
                 dfs(i, j + 1, index + 1, word, visited) ||
                 dfs(i, j - 1, index + 1, word, visited);
    visited[i][j] = false;  // Backtrack
    
    return found;
}

int main() {
    cin >> m >> n;
    grid.resize(m, vector<char>(n));
    
    // Input grid letters
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    string word;
    cin >> word;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    bool canFind = false;
    
    // Start DFS from every cell that matches the first character of the word
    for (int i = 0; i < m && !canFind; i++) {
        for (int j = 0; j < n && !canFind; j++) {
            if (grid[i][j] == word[0] && dfs(i, j, 0, word, visited)) {
                canFind = true;
            }
        }
    }
    
    cout << (canFind ? "true" : "false") << endl;
    return 0;
}
