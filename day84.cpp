#include <iostream>
#include <string>
using namespace std;

int getMaxValue(string num) {
    int n = num.size();
    int last[10] = {0};
    for (int i = 0; i < n; i++) last[num[i] - '0'] = i;
    for (int i = 0; i < n; i++) {
        for (int d = 9; d > num[i] - '0'; d--) {
            if (last[d] > i) {
                swap(num[i], num[last[d]]);
                return stoi(num);
            }
        }
    }
    return stoi(num);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int tokenNumber;
        cin >> tokenNumber;
        cout << getMaxValue(to_string(tokenNumber)) << endl;
    }
    return 0;
}