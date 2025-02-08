#include <bits/stdc++.h>
using namespace std;

void printMaxInWindow(vector<int>& arr, int n, int k) {
    deque<int> dq;
    
    for (int i = 0; i < n; i++) {
        // Remove elements that are out of the current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        
        // Add current element index at the back
        dq.push_back(i);
        
        // Print max of the window
        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N, k;
        cin >> N >> k;
        vector<int> arr(N);
        
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        printMaxInWindow(arr, N, k);
    }
    
    return 0;
}
