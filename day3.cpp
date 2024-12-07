#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;

    while (T--) {
        int direction, noofrotation, N;
        cin >> direction >> noofrotation >> N;

        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        noofrotation %= N; 

        if (direction == 0) {
        
            int temp[noofrotation];
            for (int i = 0; i < noofrotation; i++) {
                temp[i] = arr[i];
            }
            for (int i = noofrotation; i < N; i++) {
                arr[i - noofrotation] = arr[i];
            }
            for (int i = 0; i < noofrotation; i++) {
                arr[N - noofrotation + i] = temp[i];
            }
        } else if (direction == 1) {
            
            int temp[noofrotation];
            for (int i = 0; i < noofrotation; i++) {
                temp[i] = arr[N - noofrotation + i];
            }
            for (int i = N - noofrotation - 1; i >= 0; i--) {
                arr[i + noofrotation] = arr[i];
            }
            for (int i = 0; i < noofrotation; i++) {
                arr[i] = temp[i];
            }
        }

        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}