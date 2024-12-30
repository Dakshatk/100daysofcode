#include <iostream>
using namespace std;

bool isDiagonal(int matrix[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j || i + j == m - 1) && matrix[i][j] == 0) {
                return false;
            }
            if ((i != j && i + j != m - 1) && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int matrix[100][100];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        if (isDiagonal(matrix, m, n)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}