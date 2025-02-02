#include <iostream>
#include <string>
using namespace std;

int getMinLandLength(string s) {
    while (true) {
        size_t posGR = s.find("GR");
        size_t posWL = s.find("WL");
        
        if (posGR == string::npos && posWL == string::npos) {
            break;
        }
        
        if (posGR != string::npos) {
            s.erase(posGR, 2);
        } else if (posWL != string::npos) {
            s.erase(posWL, 2);
        }
    }
    return s.length();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << getMinLandLength(s) << endl;
    }
    return 0;
}