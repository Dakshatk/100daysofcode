#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    if (n == 1) {
        cout << "0\n";
        return;
    }
    
    sort(nums.begin(), nums.end());
    int minHeight = nums[0] + k;
    int maxHeight = nums[n - 1] - k;
    int result = nums[n - 1] - nums[0];
    
    for (int i = 0; i < n - 1; i++) {
        int newMin = min(nums[0] + k, nums[i + 1] - k);
        int newMax = max(nums[n - 1] - k, nums[i] + k);
        result = min(result, newMax - newMin);
    }
    
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}