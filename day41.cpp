#include <iostream>
#include <vector>

using namespace std;

// Helper function for DFS to find all paths
void dfs(int current, int target, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, vector<vector<int>>& allPaths) {
    visited[current] = true;
    path.push_back(current);

    if (current == target) {
        allPaths.push_back(path);
    } else {
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                dfs(neighbor, target, graph, visited, path, allPaths);
            }
        }
    }

    // Backtrack
    visited[current] = false;
    path.pop_back();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1); // Adjacency list for the graph

        // Read edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        vector<vector<int>> allPaths;
        vector<bool> visited(n + 1, false);
        vector<int> path;

        // Find all paths using DFS
        dfs(1, n, graph, visited, path, allPaths);

        // Output all paths
        for (const auto& p : allPaths) {
            for (size_t i = 0; i < p.size(); i++) {
                cout << p[i];
                if (i != p.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}