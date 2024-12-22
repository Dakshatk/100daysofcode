#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTargetIndices(const vector<int>& arr, int target) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    vector<int> targetIndices;
    for (size_t i = 0; i < sortedArr.size(); ++i) {
        if (sortedArr[i] == target) {
            targetIndices.push_back(i);
        }
    }

    return targetIndices;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, target;
        cin >> N >> target;

        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        vector<int> result = findTargetIndices(arr, target);

        if (result.empty()) {
            cout << "" << endl;
        } else {
            for (size_t i = 0; i < result.size(); ++i) {
                cout << result[i];
                if (i != result.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}