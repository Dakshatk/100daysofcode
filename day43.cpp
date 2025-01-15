#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void generatePermutations(vector<int>& heights, int k, set<vector<int>>& uniqueSkylines, int depth = 0) {
    if (depth == k) {
        uniqueSkylines.insert(heights);
        return;
    }

    for (int i = depth; i < heights.size(); ++i) {
        swap(heights[depth], heights[i]);
        generatePermutations(heights, k, uniqueSkylines, depth + 1);
        swap(heights[depth], heights[i]);
    }

    if (depth < heights.size()) {
        uniqueSkylines.insert(heights);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n;
        vector<int> heights(n);

        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        cin >> k;
        set<vector<int>> uniqueSkylines;

        generatePermutations(heights, k, uniqueSkylines);

        cout << uniqueSkylines.size() << endl;
    }

    return 0;
}