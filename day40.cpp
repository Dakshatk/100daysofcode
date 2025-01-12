#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int findLargestOasis(const vector<int>& water, int n, long long T) {
    // Prefix sum and sliding window using deque
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + water[i - 1];
    }

    deque<int> dq;
    int maxLength = -1;

    for (int i = 0; i <= n; ++i) {
        // Remove elements from the front if their sum meets the condition
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= T) {
            maxLength = max(maxLength, i - dq.front());
            dq.pop_front();
        }

        // Maintain the deque order: remove elements from the back that won't help
        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return maxLength;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> water(n);
        for (int i = 0; i < n; ++i) {
            cin >> water[i];
        }

        long long T;
        cin >> T;

        int result = findLargestOasis(water, n, T);
        cout << result << endl;
    }

    return 0;
}