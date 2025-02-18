#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(int node, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited) {
    visited.insert(node);
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, vector<int>> graph;
    int u, v;
    
    for (int i = 0; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int source, destination;
    cin >> source >> destination;
    
    unordered_set<int> visited;
    dfs(source, graph, visited);
    
    if (visited.find(destination) != visited.end()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}