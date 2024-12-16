#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long n, k;
        cin >> n >> k;

        vector<long> team_lineup(n);
        for (long i = 0; i < n; ++i) {
            cin >> team_lineup[i];
        }

        sort(team_lineup.begin(), team_lineup.end());
        team_lineup.erase(unique(team_lineup.begin(), team_lineup.end()), team_lineup.end());

        long cost = 0, next_missing = 1;
        size_t i = 0;

        while(i < team_lineup.size() && k > 0){
            if (team_lineup[i] > next_missing){
                cost += next_missing;
                next_missing++;
                k--;
            } 
            else{
                next_missing = team_lineup[i] + 1;
                i++;
            }
        }

        while(k > 0){
            cost += next_missing;
            next_missing++;
            k--;
        }

        cout << cost << "\n";
    }

    return 0;
}