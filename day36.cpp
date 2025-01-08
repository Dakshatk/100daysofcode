#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int n, k;
        cin >> n; // Number of chests
        vector<int> gold(n);

        // Input the gold array
        for (int i = 0; i < n; i++) {
            cin >> gold[i];
        }

        cin >> k; // Size of the sliding window

        // Sliding window to find the maximum sum of k consecutive chests
        long long current_sum = 0, max_sum = 0;

        // Compute the sum of the first window of size k
        for (int i = 0; i < k; i++) {
            current_sum += gold[i];
        }
        max_sum = current_sum;

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            current_sum += gold[i] - gold[i - k];
            max_sum = max(max_sum, current_sum);
        }

        cout << max_sum << endl; // Output the result for this test case
    }

    return 0;
}
