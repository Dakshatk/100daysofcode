#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> colors(n);
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }
        
        long long profit = 0;
        // For each day, if the next day's price is higher, add the difference to the profit.
        for (int i = 1; i < n; i++) {
            if (colors[i] > colors[i - 1]) {
                profit += colors[i] - colors[i - 1];
            }
        }
        
        cout << profit << "\n";
    }
    
    return 0;
}
