#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

    void solveTestCase(int n, vector<long long>& loadCapacity) {
        sort(loadCapacity.begin(), loadCapacity.end());
        long long maxGroupLoad = 0;
        for (int i = 0; i < n / 2; ++i) {
            long long pairLoad = loadCapacity[i] + loadCapacity[n - 1 - i];   
            maxGroupLoad = max(maxGroupLoad, pairLoad);
        }   
        cout << maxGroupLoad << endl;
    }
    int main() {
         int T;
        cin >> T; 
        while (T--) {
            int n;
            cin >> n;
            vector<long long> loadCapacity(n);
            for (int i = 0; i < n; ++i){
                cin >> loadCapacity[i];
            }
            solveTestCase(n, loadCapacity);
        }
        return 0;
    }