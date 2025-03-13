#include <iostream>
#include <vector>
using namespace std;

int maxCoinBag, targetTreasure;
vector<int> dp;

// Returns true if the current player can force a win given the current state.
bool canWin(int used, int currentTotal) {
    if (dp[used] != -1)
        return dp[used];
    
    // Try each coin (numbered 1 to maxCoinBag)
    for (int i = 0; i < maxCoinBag; i++) {
        // If coin (i+1) has not been used
        if (!(used & (1 << i))) {
            int coin = i + 1;
            // If choosing this coin reaches or exceeds the target, current player wins.
            if (currentTotal + coin >= targetTreasure) {
                dp[used] = 1;
                return true;
            }
            // Otherwise, choose this coin and see if the opponent loses.
            if (!canWin(used | (1 << i), currentTotal + coin)) {
                dp[used] = 1;
                return true;
            }
        }
    }
    dp[used] = 0;
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> maxCoinBag >> targetTreasure;
        
        // If target is 0 or less, the first adventurer wins by default.
        if (targetTreasure <= 0) {
            cout << "yes" << "\n";
            continue;
        }
        
        // Quick check: if the sum of all coins is less than the target, no one can win.
        int sum = maxCoinBag * (maxCoinBag + 1) / 2;
        if (sum < targetTreasure) {
            cout << "no" << "\n";
            continue;
        }
        
        dp.assign(1 << maxCoinBag, -1);
        bool res = canWin(0, 0);
        cout << (res ? "yes" : "no") << "\n";
    }
    return 0;
}
