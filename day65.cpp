#include <bits/stdc++.h>
using namespace std;

bool hasRedundantVines(const string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == ')') {
            char top = st.top();
            st.pop();
            bool hasOperator = false;
            
            while (!st.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
                top = st.top();
                st.pop();
            }
            
            if (!hasOperator) return true; // Redundant pair found
        } else {
            st.push(ch);
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << (hasRedundantVines(s) ? "true" : "false") << endl;
    }
    return 0;
}