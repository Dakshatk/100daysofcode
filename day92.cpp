#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> temperatures(n);
        for (int i = 0; i < n; i++) {
            cin >> temperatures[i];
        }
        
        // This will store the result for each day.
        vector<int> result(n, 0);
        // Stack to store indices of temperatures.
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            // While stack is not empty and current temperature is higher
            // than the temperature at the index stored at the top of the stack:
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                result[idx] = i - idx; // Calculate days difference.
            }
            st.push(i);
        }
        
        // Print the results.
        for (int days : result) {
            cout << days << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
