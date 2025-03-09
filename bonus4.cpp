#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int minSteps(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return 0;
    
    // Map each value to all indices where it appears.
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < n; i++) {
        graph[arr[i]].push_back(i);
    }
    
    vector<bool> visited(n, false);
    visited[0] = true;
    
    queue<int> q;
    q.push(0);
    
    int steps = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int i = q.front();
            q.pop();
            
            if(i == n - 1) return steps;
            
            // Move one step backward
            if(i - 1 >= 0 && !visited[i - 1]) {
                visited[i - 1] = true;
                q.push(i - 1);
            }
            
            // Move one step forward
            if(i + 1 < n && !visited[i + 1]) {
                visited[i + 1] = true;
                q.push(i + 1);
            }
            
            // Teleport to all other chambers with the same magical number.
            for (int j : graph[arr[i]]) {
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
            // Clear the list to avoid redundant future processing.
            graph[arr[i]].clear();
        }
        steps++;
    }
    
    return -1; // If last chamber is not reachable.
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cout << minSteps(arr) << "\n";
    }
    
    return 0;
}
