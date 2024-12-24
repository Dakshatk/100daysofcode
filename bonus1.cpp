#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortestSubarrayWithSumAtLeastK(vector<int>& nums, int n, int k) {
    int minLength = INT_MAX, currentSum = 0, start = 0;

    for (int end = 0; end < n; end++) {
        currentSum += nums[end];

        while (currentSum >= k) {
            minLength = min(minLength, end - start + 1);
            currentSum -= nums[start];
            start++;
        }
    }

    return minLength == INT_MAX ? -1 : minLength;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        
        for (int i = 0; i < n; i++) 
            cin >> nums[i];

        cout << shortestSubarrayWithSumAtLeastK(nums, n, k) << endl;
    }

    return 0;
}
