#include <iostream>
#include <vector>
using namespace std;

int timeToBuyTickets(vector<int>& tickets, int k) {
    int time = 0;
    for (size_t i = 0; i < tickets.size(); i++) {  // Changed int to size_t
        if (i <= static_cast<size_t>(k))
            time += min(tickets[i], tickets[k]);
        else
            time += min(tickets[i], tickets[k] - 1);
    }
    return time;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> tickets(n);
        for (int i = 0; i < n; i++) {
            cin >> tickets[i];
        }
        cout << timeToBuyTickets(tickets, k) << endl;
    }
    return 0;
}