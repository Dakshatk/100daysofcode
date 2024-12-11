#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int M, X;
        cin >> M >> X;
        
        vector<int> L(M);
        
        for (int i = 0; i < M; i++) {
            cin >> L[i];
        }
        
        sort(L.begin(), L.end());
        
        int count = 0;
        int totalCost = 0;
        
        for (int i = 0; i < M; i++) {
            if (totalCost + L[i] <= X) {
                totalCost += L[i];
                count++;
            } else {
                break;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
