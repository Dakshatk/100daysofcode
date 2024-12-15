#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int d, k, l, m, n;
        cin >> d >> k >> l >> m >> n;

        bool occupied[d + 1] = {false};

        for (int i = k; i <= d; i += k){
            occupied[i] = true;
        }

        for (int i = l; i <= d; i += l){
            occupied[i] = true;
        }

        for (int i = m; i <= d; i += m){
            occupied[i] = true;
        }

        for (int i = n; i <= d; i += n){
            occupied[i] = true;
        }

        int count = 0;
        for (int i = 1; i <= d; i++){
            if (occupied[i]){
                count++;
            }
        }

        cout<<count<<endl;
    }

    return 0;
}