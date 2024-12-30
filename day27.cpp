#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canDivideSandPatterns(const vector<int>& S){
    unordered_map<int, int> freq;
    
    for (int pattern : S) {
        freq[pattern]++;
    }
    
    for (const auto& entry : freq) {
        if (entry.second % 2 != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> S(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }
        
        if (canDivideSandPatterns(S)) {
            cout << "yes" << endl;
        } 
        else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
