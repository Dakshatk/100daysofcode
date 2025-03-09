#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minJumps(vector<int>& nums) {
    int n = nums.size();
    // If there's only one element, no jumps are needed.
    if(n == 1) return 0;
    
    int jumps = 0, currentEnd = 0, furthest = 0;
    
    // Traverse the array until the second last element.
    for (int i = 0; i < n - 1; i++) {
        // If we cannot move forward from i, then it's impossible.
        if (i > furthest) return -1;
        
        // Update the furthest position that can be reached.
        furthest = max(furthest, i + nums[i]);
        
        // If we reached the end of the current jump range,
        // we make another jump.
        if (i == currentEnd) {
            jumps++;
            currentEnd = furthest;
            // If currentEnd reaches or passes the last index, break out.
            if (currentEnd >= n - 1)
                break;
        }
    }
    
    // If the end is not reachable, return -1.
    return (currentEnd < n - 1) ? -1 : jumps;
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        vector<int> nums(N);
        
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        
        cout << minJumps(nums) << "\n";
    }
    
    return 0;
}
