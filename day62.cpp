#include <iostream>
#include <string>
using namespace std;

// Function to check if s1 is a subsequence of s2
bool isSubsequence(const string &s1, const string &s2) {
    size_t i = 0, j = 0;
    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++; // Move in s1 when characters match
        }
        j++; // Always move in s2
    }
    return i == s1.length(); // If i reaches the end, s1 is a subsequence of s2
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string L1, L2;
        cin >> L1 >> L2;
        
        // Check if either string is a subsequence of the other
        if (isSubsequence(L1, L2) || isSubsequence(L2, L1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}