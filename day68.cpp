#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Kadane's algorithm to find max subarray sum
int kadane(vector<int>& arr) {
    int max_sum = arr[0], current_sum = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

// Function to find the max circular subarray sum
int maxCircularSubarraySum(vector<int>& arr) {
    int max_kadane = kadane(arr); // Max subarray sum in linear form
    int total_sum = 0;

    // Invert array values and find the min subarray sum
    for (int& num : arr) {
        total_sum += num;
        num = -num;
    }

    int min_kadane = kadane(arr); // Finding min subarray sum using Kadane

    // Restore original values
    for (int& num : arr) {
        num = -num;
    }

    // If all elements are negative, max circular sum is just max_kadane
    if (total_sum == -min_kadane) return max_kadane;

    // Max of normal subarray sum and circular subarray sum
    return max(max_kadane, total_sum + min_kadane);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> happiness(n);
        for (int i = 0; i < n; i++) {
            cin >> happiness[i];
        }
        cout << maxCircularSubarraySum(happiness) << "\n";
    }

    return 0;
}