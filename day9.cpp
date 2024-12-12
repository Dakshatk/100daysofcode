#include <iostream>
#include <string>
using namespace std;

string nice(string s) {
    int n = s.length();
    if (n == 1) return "-1"; 
    
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != 'a') {
            s[i] = 'a';
            return s;
        }
    }
    
    s[n - 1] = 'b';
    return s;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        cout << nice(s) << endl;
    }

    return 0;
}
