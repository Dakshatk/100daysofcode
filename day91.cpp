#include <iostream>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        long long num1, num2;
        cin >> num1 >> num2;
        
        // If num2 is 0, we simply need to represent num1 as a sum of powers of 2.
        if(num2 == 0) {
            cout << __builtin_popcountll(num1) << "\n";
            continue;
        }
 
        int ans = -1;
        // Try x = number of spells from 1 to 60
        for(int x = 1; x <= 60; x++){
            // S is the total contributed by the 2^i parts: it must equal num1 - x * num2.
            long long S = num1 - num2 * x;
            if(S < x || S < 0) continue; // Cannot have S smaller than x, because each spell contributes at least 1.
 
            // Count number of ones in S (minimum spells needed to form S as sum of powers of 2)
            int cnt = __builtin_popcountll(S);
            if(cnt <= x && x <= S){
                ans = x;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
