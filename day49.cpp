#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the smallest tunnel clearance greater than or equal to train_height
int find_min_clearance(const vector<int>& clearances, int train_height) {
    int left = 0, right = clearances.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (clearances[mid] >= train_height) {
            result = clearances[mid];
            right = mid - 1; // Look for a smaller valid clearance
        } else {
            left = mid + 1; // Look for a larger clearance
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> clearances(n);
        for (int i = 0; i < n; ++i) {
            cin >> clearances[i];
        }

        int train_height;
        cin >> train_height;

        // Find and output the result
        int result = find_min_clearance(clearances, train_height);
        cout << result << endl;
    }

    return 0;
}