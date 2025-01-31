#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> heights;
    
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        if (h > 0) {
            heights.insert(h);
        }
    }
    
    cout << heights.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}