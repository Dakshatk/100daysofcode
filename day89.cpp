#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        // Initialize answer vector with 0s.
        vector<long long> ans(n, 0);
        
        // Group indices for each lamp post ID.
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; i++){
            positions[arr[i]].push_back(i);
        }
        
        // Process each group separately.
        for (auto &entry : positions) {
            auto &pos = entry.second;
            // Sort positions so that we can efficiently compute distances.
            sort(pos.begin(), pos.end());
            int k = pos.size();
            
            // Build prefix sum array of positions.
            vector<long long> prefix(k, 0);
            prefix[0] = pos[0];
            for (int i = 1; i < k; i++){
                prefix[i] = prefix[i-1] + pos[i];
            }
            
            // For each position in the sorted group, calculate the sum of distances.
            for (int i = 0; i < k; i++){
                // Sum of distances from all positions to the left.
                long long left = (long long) pos[i] * i - (i > 0 ? prefix[i-1] : 0);
                // Sum of distances from all positions to the right.
                long long right = (prefix[k-1] - prefix[i]) - (long long) pos[i] * (k - 1 - i);
                long long total = left + right;
                // Map the computed total back to the original index.
                ans[pos[i]] = total;
            }
        }
        
        // Output the results for this test case.
        for (int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
