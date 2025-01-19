#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    
    while (t--) {
        int n;
        cin >> n; // Number of permits

        vector<int> permits(n);
        for (int i = 0; i < n; i++) {
            cin >> permits[i]; // Input permit IDs
        }

        int target;
        cin >> target; // Target permit ID to search for

        // Perform binary search
        int index = lower_bound(permits.begin(), permits.end(), target) - permits.begin();

        if (index < n && permits[index] == target) {
            cout << index << endl; // Output the index if found
        } 
        else {
            cout << -1 << endl; // Output -1 if not found
        }
    }

    return 0;
}