#include <iostream>
using namespace std;

int maxItems(int n, int maxSum, int banned[], int bannedSize) {
    bool isBanned[10001] = {false};
    for (int i = 0; i < bannedSize; i++) {
        isBanned[banned[i]] = true;
    }

    int count = 0, currentSum = 0;
    for (int i = 1; i <= n; i++) {
        if (!isBanned[i] && currentSum + i <= maxSum) {
            currentSum += i;
            count++;
        } else if (currentSum + i > maxSum) {
            break;
        }
    }

    return count;
}

int main() {
    int n, maxSum, bannedSize;
    cin >> n >> maxSum >> bannedSize;
    int banned[bannedSize];
    for (int i = 0; i < bannedSize; i++) {
        cin >> banned[i];
    }
    cout << maxItems(n, maxSum, banned, bannedSize) << endl;
    return 0;
}