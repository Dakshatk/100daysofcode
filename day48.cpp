#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& heights, int desired_height) {
    int left = 0, right = heights.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (heights[mid] == desired_height) {
            return mid; // Return 0-based index if found
        } else if (heights[mid] < desired_height) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of skyscrapers
        cin >> n;

        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        int desired_height;
        cin >> desired_height;

        // Perform binary search and output the result
        cout << binarySearch(heights, desired_height) << endl;
    }

    return 0;
}
