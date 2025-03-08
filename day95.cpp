#include <bits/stdc++.h>
using namespace std;

int findMaxDeadline(vector<pair<int, int>>& tasks) {
    int maxDeadline = 0;
    for (auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.first);
    }
    return maxDeadline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> tasks(N);
        for (int i = 0; i < N; i++) {
            cin >> tasks[i].first >> tasks[i].second;
        }
        
        sort(tasks.begin(), tasks.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        });
        
        int maxDeadline = findMaxDeadline(tasks);
        vector<bool> slot(maxDeadline + 1, false);
        int maxProfit = 0, tasksCompleted = 0;
        
        for (auto& task : tasks) {
            for (int d = task.first; d > 0; d--) {
                if (!slot[d]) {
                    slot[d] = true;
                    maxProfit += task.second;
                    tasksCompleted++;
                    break;
                }
            }
        }
        
        cout << maxProfit << " " << tasksCompleted << "\n";
    }
    return 0;
}