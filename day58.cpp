#include <iostream>
#include <algorithm>
using namespace std;

int minSecondsToFillCups(int amount[]) {
    sort(amount, amount + 3, greater<int>());
    
    if (amount[0] >= amount[1] + amount[2]) {
        return amount[0];
    } else {
        return (amount[0] + amount[1] + amount[2] + 1) / 2;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int amount[3];
        cin >> amount[0] >> amount[1] >> amount[2];
        cout << minSecondsToFillCups(amount) << endl;
    }
    return 0;
}