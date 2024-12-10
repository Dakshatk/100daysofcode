#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    set<char> delimiters = {'~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while (T--) {
        string S;
        getline(cin, S);
        
        vector<string> greetings;
        string currentGreeting;

        for (char c : S) {
            if (delimiters.find(c) != delimiters.end()) {
                if (!currentGreeting.empty()) {
                    greetings.push_back(currentGreeting);
                    currentGreeting.clear();
                }
            } else {
                currentGreeting += c;
            }
        }
        
        if (!currentGreeting.empty()) {
            greetings.push_back(currentGreeting);
        }
        
        for (const string& greeting : greetings) {
            cout << greeting << endl;
        }
    }
    
    return 0;
}
