#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<set<int>> adj; // Adjacency list using sets for quick lookup
vector<bool> visited;

// Perform BFS to get the connected component
vector<int> getComponent(int start) {
    vector<int> component;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        component.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return component;
}

// Check if a component forms a complete group
bool isCompleteGroup(const vector<int>& component) {
    int size = component.size();
    int expectedEdges = (size * (size - 1)) / 2;
    int actualEdges = 0;

    for (int node : component) {
        actualEdges += adj[node].size();
    }
    actualEdges /= 2; // Each edge was counted twice

    return actualEdges == expectedEdges;
}

int main() {
    int m, n;
    cin >> m >> n;

    adj.resize(n);
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int completeGroups = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component = getComponent(i);
            if (isCompleteGroup(component)) {
                completeGroups++;
            }
        }
    }

    cout << completeGroups << endl;
    return 0;
}
