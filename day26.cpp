#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<unordered_map>
using namespace std;

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        unordered_map<char, int> freqMap;

        for (char c : s) {
            freqMap[c]++;
        }

        vector<pair<char, int>> vec(freqMap.begin(), freqMap.end());

        sort(vec.begin(), vec.end(), compare);

        for (auto& it : vec) {
            cout << string(it.second, it.first);
        }
        cout << endl;
    }

    return 0;
}