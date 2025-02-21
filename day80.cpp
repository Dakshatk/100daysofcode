#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(vector<vector<int>>& dist, int N) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> T(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> T[i][j];
            if (T[i][j] == 0 && i != j) {
                T[i][j] = INF;
            }
        }
    }
    
    floydWarshall(T, N);
    
    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i) {
        int S, G, D;
        cin >> S >> G >> D;
        
        int timeViaGym = T[S][G] + T[G][D];
        int timeDirect = T[S][D];
        
        cout << timeViaGym << " " << (timeViaGym - timeDirect) << endl;
    }
    
    return 0;
}