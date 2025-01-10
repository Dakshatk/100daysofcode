#include <iostream>
#include <vector>
using namespace std;

int longestNonDecreasingSubarray(vector<int>& flow) {
    int n = flow.size();
    int maxLength = 1, currentLength = 1;

    for (int i = 1; i < n; ++i) {
        if (flow[i] >= flow[i - 1]) {
            currentLength++;
        } else {
            currentLength = 1;
        }
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of points along the Nile
        cin >> n;

        vector<int> flow(n);
        for (int i = 0; i < n; ++i) {
            cin >> flow[i];
        }

        // Calculate and output the result for this test case
        cout << longestNonDecreasingSubarray(flow) << endl;
    }

    return 0;
}