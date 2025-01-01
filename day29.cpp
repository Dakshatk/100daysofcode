#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int n; // Number of fossils in the collection
        cin >> n;
        vector<int> fossils(n);
        map<int, int> frequency;

        // Input fossils and calculate frequency
        for (int i = 0; i < n; i++) {
            cin >> fossils[i];
            frequency[fossils[i]]++;
        }

        vector<int> rareFossils;

        // Identify rare fossils
        for (auto &entry : frequency) {
            if (entry.first == entry.second) {
                rareFossils.push_back(entry.first);
            }
        }

        // Output rare fossils in ascending order
        if (rareFossils.empty()) {
            cout << -1 << endl;
        } else {
            sort(rareFossils.begin(), rareFossils.end());
            for (size_t i = 0; i < rareFossils.size(); i++) {
                if (i > 0) cout << " ";
                cout << rareFossils[i];
            }
            cout << endl;
        }
    }

    return 0;
}