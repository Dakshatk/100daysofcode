#include <iostream>
using namespace std;

int findDeliveryPosition(int n, int time) {
    int cycle_length = 2 * (n - 1);
    time = time % cycle_length;
    
    if (time < n - 1) {
        return time + 1;
    } else {
        return 2 * (n - 1) - time + 1;
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, time;
        cin >> n >> time;
        cout << findDeliveryPosition(n, time) << endl;
    }
    
    return 0;
}
