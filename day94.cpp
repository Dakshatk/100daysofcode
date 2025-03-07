#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N, X;
        cin >> N >> X;
        vector<int> coins(N);
        for (int i = 0; i < N; i++) {
            cin >> coins[i];
        }
        
        // Initialize dp array: dp[i] is the minimum coins to form amount i.
        const int INF = 1e9;
        vector<int> dp(X + 1, INF);
        dp[0] = 0; // 0 coins needed to form 0
        
        // Compute minimum coins for each amount from 1 to X
        for (int i = 1; i <= X; i++) {
            for (int j = 0; j < N; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INF) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        
        // Output result: if X can't be formed, dp[X] remains INF.
        cout << (dp[X] == INF ? -1 : dp[X]) << "\n";
    }
    
    return 0;
}
