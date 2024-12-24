#include <iostream>
#include <vector>
using namespace std;

void spiralTraverse(vector<vector<int>>& matrix, int m, int n) {
    vector<int> result;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) 
            result.push_back(matrix[top][i]);
        top++;

        for (int i = top; i <= bottom; i++) 
            result.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) 
                result.push_back(matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) 
                result.push_back(matrix[i][left]);
            left++;
        }
    }

    for (std::size_t i = 0; i < result.size(); i++) {
        if (i > 0) 
            cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                cin >> matrix[i][j];
        spiralTraverse(matrix, m, n);
    }
    return 0;
}