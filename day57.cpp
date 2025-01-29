#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void largestPossibleNumber(int num) {
    string s = to_string(num);
    vector<char> odd, even;
    
    for (char c : s) {
        if ((c - '0') % 2 == 0)
            even.push_back(c);
        else
            odd.push_back(c);
    }
    
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    
    int oddIdx = 0, evenIdx = 0;
    for (char &c : s) {
        if ((c - '0') % 2 == 0)
            c = even[evenIdx++];
        else
            c = odd[oddIdx++];
    }
    
    cout << s << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int num;
        cin >> num;
        largestPossibleNumber(num);
    }
    return 0;
}
