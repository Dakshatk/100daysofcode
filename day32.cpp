#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if s is a subsequence of t
bool isSubsequence(const string& s, const string& t) {
    string::size_type i = 0, j = 0; // Use std::string::size_type for indices
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.length();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline character after reading T
    vector<string> results;

    for (int test = 0; test < T; ++test) {
        string s, t;
        getline(cin, s);
        getline(cin, t);
        if (isSubsequence(s, t)) {
            results.push_back("true");
        } 
        else {
            results.push_back("false");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
