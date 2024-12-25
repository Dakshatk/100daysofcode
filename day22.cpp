#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int minOperationsToUniValueGrid(vector<vector<int>>& grid, int m, int n, int x) {
    vector<int> values;
    int base = grid[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int diff = grid[i][j] - base;
            if (abs(diff) % x != 0) return -1;
            values.push_back(grid[i][j]);
        }
    }
    sort(values.begin(), values.end());
    int median = values[values.size() / 2], operations = 0;
    for (int v : values) operations += abs(v - median) / x;
    return operations;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n, x;
        cin >> m >> n >> x;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cin >> grid[i][j];
        }
        cout << minOperationsToUniValueGrid(grid, m, n, x) << endl;
    }
    return 0;
}