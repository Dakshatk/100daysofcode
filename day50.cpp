#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

// Function to calculate the total height after applying the height limit
long long calculateTotalHeight(const vector<int>& heights, int limit) {
    long long total = 0;
    for (int height : heights) {
        total += min(height, limit);
    }
    return total;
}

// Function to find the smallest height limit
int findHeightLimit(const vector<int>& heights, int target) {
    int left = 0, right = *max_element(heights.begin(), heights.end());
    int bestLimit = 0;
    long long closestDiff = LLONG_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long total = calculateTotalHeight(heights, mid);
        long long diff = abs(total - target);

        if (diff < closestDiff || (diff == closestDiff && mid < bestLimit)) {
            closestDiff = diff;
            bestLimit = mid;
        }

        if (total < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return bestLimit;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, target;
        cin >> n >> target;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        cout << findHeightLimit(heights, target) << endl;
    }

    return 0;
}
