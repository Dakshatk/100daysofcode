#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int n, k; // Number of locations and required number of oases
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        // Transform nums into a binary array (1 for odd, 0 for even)
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] % 2;
        }

        // Use prefix sum and hashmap for counting pleasant paths
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Initial prefix sum is 0 (base case)
        int prefixSum = 0, pleasantPaths = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];

            // Check if there exists a previous prefix sum equal to (prefixSum - k)
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                pleasantPaths += prefixCount[prefixSum - k];
            }

            // Increment the count of the current prefix sum
            prefixCount[prefixSum]++;
        }

        // Output the number of pleasant paths for this test case
        cout << pleasantPaths << endl;
    }

    return 0;
}