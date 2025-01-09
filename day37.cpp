#include <iostream>
#include <vector>
using namespace std;

int findSmallestWindow(vector<int>& lights, int n, int k) {
    int onCount = 0;
    for (int i = 0; i < k; ++i) onCount += lights[i];
    if (onCount == k) return 0;
    for (int i = k; i < n; ++i) {
        onCount += lights[i] - lights[i - k];
        if (onCount == k) return i - k + 1;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        vector<int> lights(n);
        for (int i = 0; i < n; ++i) cin >> lights[i];
        cin >> k;
        cout << findSmallestWindow(lights, n, k) << endl;
    }
    return 0;
}