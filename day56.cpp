#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int minChargingTime(vector<int>& amount) {
    // Calculate the total number of vehicles
    int totalVehicles = amount[0] + amount[1] + amount[2];
    
    // Find the maximum number of vehicles needing a single type of charger
    int maxVehicles = max({amount[0], amount[1], amount[2]});
    
    // The minimum time required is the maximum of:
    // 1. The ceiling of totalVehicles / 2 (since we can charge two vehicles at a time)
    // 2. The maximum number of vehicles needing a single type of charger
    return max((totalVehicles + 1) / 2, maxVehicles);
}

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        vector<int> amount(3);
        cin >> amount[0] >> amount[1] >> amount[2]; // Read the amount for each charger type
        cout << minChargingTime(amount) << endl; // Output the minimum time required
    }
    return 0;
}