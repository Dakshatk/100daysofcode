#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<long long> IDs(n);
        for (int i = 0; i < n; i++) {
            cin >> IDs[i];
        }
        
        // Sort the array so that duplicates are adjacent.
        sort(IDs.begin(), IDs.end());
        
        long long moves = 0;
        for (int i = 1; i < n; i++) {
            // If the current ID is not strictly greater than the previous unique one,
            // increment it to previous ID + 1.
            if (IDs[i] <= IDs[i - 1]) {
                long long required = IDs[i - 1] + 1;
                moves += required - IDs[i];
                IDs[i] = required;
            }
        }
        
        cout << moves << "\n";
    }
    
    return 0;
}
