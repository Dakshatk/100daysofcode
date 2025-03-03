#include <iostream>
#include <cmath>
using namespace std;

bool isMagical(int C) {
    int a = 0, b = sqrt(C);
    while (a <= b) {
        int sum = a * a + b * b;
        if (sum == C) return true;
        else if (sum < C) a++;
        else b--;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int C;
        cin >> C;
        cout << (isMagical(C) ? "yes" : "no") << endl;
    }
    return 0;
}