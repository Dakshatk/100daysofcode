#include <iostream>
using namespace std;

// Function to determine if you can win the round
string canWin(int n) {
    // If n % 4 is 0, you lose; otherwise, you win
    return (n % 4 == 0) ? "No" : "Yes";
}

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int n; // Number of seconds left
        cin >> n;

        // Output the result for each test case
        cout << canWin(n) << endl;
    }

    return 0;
}