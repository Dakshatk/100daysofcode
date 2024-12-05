#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        int H[1000], A[1000];
        for (int i = 0; i < N; i++){ 
            cin >> H[i];
        }
        for (int i = 0; i < M; i++){
            cin >> A[i];
        }
        int divisor_count[100001] = {0};
        for (int i = 0; i < N; i++) {
            for (int d = 1; d * d <= H[i]; d++) {
                if (H[i] % d == 0) {
                    divisor_count[d]++;
                    if (d != H[i] / d) divisor_count[H[i] / d]++;
                }
            }
        }

        int max_count = 0;
        int best_luckiness = 100001;
        for (int i = 0; i < M; i++) {
            int count = divisor_count[A[i]];
            if (count > max_count || (count == max_count && A[i] < best_luckiness)) {
                max_count = count;
                best_luckiness = A[i];
            }
        }

        cout << best_luckiness << endl;
    }

    return 0;
}
