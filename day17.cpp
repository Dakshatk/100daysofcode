#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPickWithDifference(const vector<int>& rarity, int k, int mid) {
    int count = 1;
    int lastPicked = rarity[0];

    for (int i = 1; i < rarity.size(); i++) {
        if (rarity[i] - lastPicked >= mid) {
            count++;
            lastPicked = rarity[i];
        }
        if (count >= k) {
            return true;
        }
    }
    return false;
}

int findMaxBestMatch(const vector<int>& rarity, int k) {
    int low = 0, high = rarity.back() - rarity[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPickWithDifference(rarity, k, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, k;
        cin >> N >> k;
        vector<int> rarity(N);
        for (int i = 0; i < N; i++) {
            cin >> rarity[i];
        }
        sort(rarity.begin(), rarity.end());
        cout << findMaxBestMatch(rarity, k) << endl;
    }
    return 0;
}