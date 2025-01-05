#include <iostream>
#include <vector>
using namespace std;

vector<int> findLanterns(const vector<int>& brightness, int target) {
    int left = 0;
    int right = brightness.size() - 1;
    while (left < right) {
        int sum = brightness[left] + brightness[right];
        if (sum == target) {
            return {left + 1, right + 1}; // 1-based indices
        } 
        else if (sum < target) {
            left++;
        } 
        else {
            right--;
        }
    }
    return {}; // This will never be reached since there is exactly one solution
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, target;
        cin >> n;
        vector<int> brightness(n);
        for (int i = 0; i < n; i++) {
            cin >> brightness[i];
        }
        cin >> target;
        vector<int> result = findLanterns(brightness, target);
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}