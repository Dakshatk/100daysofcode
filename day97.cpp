#include <iostream>
#include <vector>
using namespace std;

int knapsack(int N, int W, vector<int> &values, vector<int> &weights) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, W;
        cin >> N >> W;
        vector<int> values(N), weights(N);
        for (int i = 0; i < N; i++) {
            cin >> values[i] >> weights[i];
        }
        cout << knapsack(N, W, values, weights) << endl;
    }
    return 0;
}