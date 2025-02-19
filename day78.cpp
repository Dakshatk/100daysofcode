#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// Function to compute the Manhattan distance between two points
int manhattanDist(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

// Function to find the Minimum Spanning Tree using Prim's algorithm
int minEffortToConnect(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); // {cost, index}
    int totalEffort = 0, edgesUsed = 0;
    
    while (!pq.empty() && edgesUsed < n) {
        pii topElement = pq.top();  // Extract the pair
        pq.pop();
        int cost = topElement.first;
        int u = topElement.second;

        if (inMST[u]) continue;

        inMST[u] = true;
        totalEffort += cost;
        edgesUsed++;

        for (int v = 0; v < n; v++) {
            if (!inMST[v]) {
                int dist = manhattanDist(points[u], points[v]);
                pq.push({dist, v});
            }
        }
    }
    
    return totalEffort;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }

        cout << minEffortToConnect(points) << "\n";
    }

    return 0;
}
