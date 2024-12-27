#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

// Function to check if a subset of rows is stable
bool is_stable_subset(const vector<vector<int>>& grid, int subset_mask, int m, int n) {
    int subset_size = __builtin_popcount(subset_mask);
    if (subset_size == 0) return false;

    int max_particles_per_column = subset_size / 2;
    vector<int> column_sums(n, 0);

    for (int i = 0; i < m; ++i) {
        if (subset_mask & (1 << i)) {
            for (int col = 0; col < n; ++col) {
                column_sums[col] += grid[i][col];
            }
        }
    }

    for (int col_sum : column_sums) {
        if (col_sum > max_particles_per_column) {
            return false;
        }
    }

    return true;
}

// Function to find a stable subset of rows
vector<int> find_stable_subset(const vector<vector<int>>& grid, int m, int n) {
    for (int subset_size = 1; subset_size <= m; ++subset_size) {
        for (int subset_mask = 1; subset_mask < (1 << m); ++subset_mask) {
            if (__builtin_popcount(subset_mask) == subset_size) {
                if (is_stable_subset(grid, subset_mask, m, n)) {
                    vector<int> subset_indices;
                    for (int i = 0; i < m; ++i) {
                        if (subset_mask & (1 << i)) {
                            subset_indices.push_back(i);
                        }
                    }
                    return subset_indices;
                }
            }
        }
    }

    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

        vector<int> stable_subset = find_stable_subset(grid, m, n);
        if (!stable_subset.empty()) {
            cout << "[";
            for (size_t i = 0; i < stable_subset.size(); ++i) {
                cout << stable_subset[i];
                if (i != stable_subset.size() - 1) cout << ",";
            }
            cout << "]\n";
        } else {
            cout << "[]\n";
        }
    }

    return 0;
}