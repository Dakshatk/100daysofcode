#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int movesToChessboard(vector<vector<int>>& board) {
    int n = board.size();
    // Check if the board can be transformed into a checkerboard.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // For a valid transformation, we must have:
            // board[i][j] == board[0][0] ^ board[i][0] ^ board[0][j]
            if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0)
                return -1;
        }
    }
    
    int rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
    // Calculate rowSum and colSum for the first row and first column.
    // Also count how many rows and columns already match the ideal alternating pattern.
    for (int i = 0; i < n; i++) {
        rowSum += board[0][i];
        colSum += board[i][0];
        if (board[i][0] == i % 2)
            rowDiff++;
        if (board[0][i] == i % 2)
            colDiff++;
    }
    
    // For a valid transformation, the number of 1's in the first row and first column must be appropriate.
    if (n / 2 > rowSum || rowSum > (n + 1) / 2)
        return -1;
    if (n / 2 > colSum || colSum > (n + 1) / 2)
        return -1;
    
    int moves = 0;
    // Calculate minimal swaps for rows and columns.
    if (n % 2 == 1) { // For odd n, the parity counts must be adjusted.
        if (rowDiff % 2 == 1)
            rowDiff = n - rowDiff;
        if (colDiff % 2 == 1)
            colDiff = n - colDiff;
        moves = (rowDiff + colDiff) / 2;
    } else { // For even n, take the minimum of swapping based on the current or complementary count.
        rowDiff = min(rowDiff, n - rowDiff);
        colDiff = min(colDiff, n - colDiff);
        moves = (rowDiff + colDiff) / 2;
    }
    
    return moves;
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        cout << movesToChessboard(board) << "\n";
    }
    return 0;
}
