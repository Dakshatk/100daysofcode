#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& fares, int query) {
    int left = 0, right = fares.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        if (fares[mid] == query) {
            return mid; // Found the fare, return the index
        } 
        else if (fares[mid] < query) {
            left = mid + 1; // Search in the right half
        } 
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Query not found
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Number of fares recorded
        vector<int> fares(n);
        for (int i = 0; i < n; ++i) {
            cin >> fares[i]; // Input fares
        }
        int query;
        cin >> query; // Fare amount to search for
        cout << binarySearch(fares, query) << endl; // Output result
    }
    return 0;
}
