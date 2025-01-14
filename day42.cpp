#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int minPopulationDifference(int n, const vector<vector<int>>& grid) {
    int total_cells = n * n;
    vector<int> populations(total_cells);
    
    int total_population = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int index = i * n + j;
            populations[index] = grid[i][j];
            total_population += grid[i][j];
        }
    }
    
    int target = total_population / 2;
    
    vector<bool> dp(target + 1, false);
    dp[0] = true; 
    
    for (int i = 0; i < total_cells; ++i) {
        for (int s = target; s >= populations[i]; --s) {
            dp[s] = dp[s] || dp[s - populations[i]];
        }
    }

    int closest_sum = 0;
    for (int s = target; s >= 0; --s) {
        if (dp[s]) {
            closest_sum = s;
            break;
        }
    }

    int diff = abs(total_population - 2 * closest_sum);
    return diff;
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

        cout << minPopulationDifference(n, grid) << endl;
    }

    return 0;
}