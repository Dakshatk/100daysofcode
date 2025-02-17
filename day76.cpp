#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (isConnected[node][i] == 1 && !visited[i]) {
            dfs(i, isConnected, visited, n);
        }
    }
}

int countGreatKingdoms(vector<vector<int>> &isConnected, int n) {
    vector<bool> visited(n, false);
    int kingdoms = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited, n);
            kingdoms++;
        }
    }
    return kingdoms;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> isConnected(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> isConnected[i][j];
        cout << countGreatKingdoms(isConnected, n) << endl;
    }
    return 0;
}