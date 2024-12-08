#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;

    const int MAX_SIZE = 10000;
    int L[MAX_SIZE];
    
    while (T--){
        int N;
        cin >> N;

        for (int i = 0; i < N; i++){
            cin >> L[i];
        }

        int rightsum = 0, leftsum = 0;

        for (int i = 0; i < N; i++){
            rightsum = rightsum + L[i];
        }

        int result = -1;
        for (int i = 0; i < N; i++){
            rightsum = rightsum - L[i];

            if (leftsum == rightsum){
                result = i;
                break;
            }
            
            leftsum = leftsum + L[i];
        }
        
        cout << result << endl;
    }
    
    return 0;
}