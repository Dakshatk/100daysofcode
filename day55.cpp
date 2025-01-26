#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to determine the winner of the game
string determine_winner(int n, string starting_player, vector<int>& power_ups) {
    int even_count = 0, odd_count = 0;

    // Count the number of stations with even and odd power-ups
    for (int i = 0; i < n; ++i) {
        if (power_ups[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Determine the winner based on the starting player and counts
    if (starting_player == "Mario") {
        // Mario wins if he can make the last move
        return (even_count > odd_count) ? "Luigi" : (even_count < odd_count) ? "Mario" : "Luigi";
    } else {
        // Luigi wins if he can make the last move
        return (odd_count > even_count) ? "Mario" : (odd_count < even_count) ? "Luigi" : "Mario";
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        string starting_player;
        cin >> n >> starting_player;

        vector<int> power_ups(n);
        for (int i = 0; i < n; ++i) {
            cin >> power_ups[i];
        }

        // Determine the winner for the current test case
        cout <<determine_winner(n,starting_player,power_ups)<< endl;
    }

    return 0;
}