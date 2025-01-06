#include <iostream>
#include <vector>
using namespace std;

void rearrangeNetPieces(vector<int>& net) {
    int lastNonZeroIndex = 0;
    for (size_t i = 0; i < net.size(); i++) {
        if (net[i] != 0) {
            swap(net[lastNonZeroIndex], net[i]);
            lastNonZeroIndex++;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> net(n);
        for (int i = 0; i < n; i++) {
            cin >> net[i];
        }
        rearrangeNetPieces(net);
        for (int i = 0; i < n; i++) {
            cout << net[i] << " ";
        }
        cout << endl;
    }
    return 0;
}