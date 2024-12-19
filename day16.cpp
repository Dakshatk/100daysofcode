#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSpirit(int maxNum) {
    vector<int> spirit(maxNum + 1);
    for (int i = 0; i <= maxNum; ++i) {
        spirit[i] = __builtin_popcount(i);
    }
    return spirit;
}

void solve(vector<int>& spirit) {
    int t;
    cin >> t;
    while (t--) {
        int n, maxVal = 0;
        cin >> n;
        vector<int> arr(n);
        for (int &x : arr) {
            cin >> x;
            maxVal = max(maxVal, x);
        }

        if (maxVal >= (int)spirit.size()) {
            int curSize = spirit.size();
            spirit.resize(maxVal + 1);
            for (int i = curSize; i <= maxVal; ++i) 
                spirit[i] = __builtin_popcount(i);
        }

        stable_sort(arr.begin(), arr.end(), [&](int a, int b) {
            return spirit[a] != spirit[b] ? spirit[a] < spirit[b] : a < b;
        });

        for (int x : arr) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> spirit = getSpirit(1e6);
    solve(spirit);

    return 0;
}
