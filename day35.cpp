#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxPairs(vector<int>& dishes, int k) {
    unordered_map<int, int> freq;
    int pairs = 0;

    for (int taste : dishes) {
        freq[taste]++;
    }

    for (int taste : dishes) {
        int complement = k - taste;
        if (freq[taste] > 0 && freq[complement] > 0) {
            if (taste == complement) {
                pairs += freq[taste] / 2;
                freq[taste] = 0;
            } 
            else {
                int count = min(freq[taste], freq[complement]);
                pairs += count;
                freq[taste] -= count;
                freq[complement] -= count;
            }
        }
    }
    return pairs;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> dishes(n);
        for (int i = 0; i < n; i++){
            cin >> dishes[i];
        }
        cout << maxPairs(dishes, k) << endl;
    }
    return 0;
}