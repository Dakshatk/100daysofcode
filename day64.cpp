#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

bool hasRailwayDipPattern(const vector<int>& heights) {
    int n = heights.size();
    if (n < 3) return false;

    vector<int> min_left(n);
    min_left[0] = heights[0];
    for (int i = 1; i < n; ++i) {
        min_left[i] = min(min_left[i - 1], heights[i]);
    }

    stack<int> s;
    for (int j = n - 1; j >= 0; --j) {
        if (heights[j] > min_left[j]) {
            while (!s.empty() && s.top() <= min_left[j]) {
                s.pop();
            }
            if (!s.empty() && s.top() < heights[j]) {
                return true;
            }
            s.push(heights[j]);
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        if (hasRailwayDipPattern(heights)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}