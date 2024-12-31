#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    string s1 = "qwertyuiop";
    string s2 = "asdfghjkl";
    string s3 = "zxcvbnm";
    while (t--) {
        string s;
        cin >> s;
        bool flag = false;
        for (size_t i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        if (s.find_first_not_of(s1) == string::npos) {
            flag = true;
        } else if (s.find_first_not_of(s2) == string::npos) {
            flag = true;
        } else if (s.find_first_not_of(s3) == string::npos) {
            flag = true;
        }
        if (flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;

}