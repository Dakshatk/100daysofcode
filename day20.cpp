#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> masses(n);
        for (int i = 0; i < n; i++) {
            cin >> masses[i];
        }

        unordered_map<int, int> freq;
        int maxPairs = 0;

        for (size_t i = 0; i < masses.size(); i++){
            int complement = k - masses[i];

            if (freq[complement] > 0){
                maxPairs++;
                freq[complement]--;
            } 
            else {
                freq[masses[i]]++;
            }
        }

        cout << maxPairs << endl;
    }

    return 0;
}
