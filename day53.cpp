#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generate(int limit) {
    set<int> pp;
    
    for (int p = 2; p <= sqrt(limit); ++p) {
        if (is_prime(p)) {
            long long power = p;
            while (power <= limit) {
                pp.insert(power);
                if (power > limit / p) break; 
                power *= p;
            }
        }
    }
    
    vector<int> result(pp.begin(), pp.end());
    return result;
}

vector<string> solve_game(int T, vector<int>& test_cases) {
    int max_n = *max_element(test_cases.begin(), test_cases.end());  
    
    vector<int> pp = generate(max_n);
    
    const int max_limit = 1000;  
    
    vector<bool> dp(max_limit + 1, false);
    dp[0] = false; 
    
    for (int i = 1; i <= max_limit; ++i) {
        for (int move : pp) {
            if (move > i) break;
            if (!dp[i - move]) {
                dp[i] = true;
                break;
            }
        }
        
        if (!dp[i - 1]) {
            dp[i] = true;
        }
    }
    
    vector<string> results;
    for (int N : test_cases) {
        if (N <= max_limit) {
            if (dp[N]) {
                results.push_back("BarbarianKing");
            } else {
                results.push_back("ArcherQueen");
            }
        } else {
            
            if (N % 6 == 0) {
                results.push_back("ArcherQueen");
            } else {
                results.push_back("BarbarianKing");
            }
        }
    }
    
    return results;
}

int main() {
    int T;
    cin >> T;
    
    vector<int> test_cases(T);
    for (int i = 0; i < T; ++i) {
        cin >> test_cases[i];
    }
    
    vector<string> results = solve_game(T, test_cases);
    
    for (const string& result : results) {
        cout << result << endl;
    }
    
    return 0;
}