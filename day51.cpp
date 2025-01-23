#include <iostream>
#include <string>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        string num;
        cin >> num;
        int n = num.length();
        
        int leftSum = 0, rightSum = 0;
        int leftQuestion = 0, rightQuestion = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQuestion++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQuestion++;
            else
                rightSum += num[i] - '0';
        }

        int diff = leftQuestion - rightQuestion;
        int deltaSum = leftSum - rightSum;

        // Shinchan starts, and they both play optimally
        if (diff == 0) {
            if (deltaSum == 0)
                cout << "Aichan\n";
            else
                cout << "Shinchan\n";
        } else if (diff > 0) {
            // More '?' on the left side
            int maxLeft = diff / 2 * 9;
            if (deltaSum + maxLeft == 0)
                cout << "Aichan\n";
            else
                cout << "Shinchan\n";
        } else {
            // More '?' on the right side
            int maxRight = (-diff) / 2 * 9;
            if (deltaSum - maxRight == 0)
                cout << "Aichan\n";
            else
                cout << "Shinchan\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}