#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        queue<int> q;
        int brr[n];

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        for (int i = 0; i < n; i++) cin >> brr[i];

        int j = 0, rotations = 0, max_rotations = n * n; 

        while (!q.empty() && j < n && rotations < max_rotations) {
            if (q.front() == brr[j]) {
                q.pop();
                j++;
                rotations = 0;
            } else {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }
        cout << q.size() << endl;
    }
    return 0;
}