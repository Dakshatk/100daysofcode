#include <iostream>
#include <list>
using namespace std;

int findLastFriend(int n, int k) {
    list<int> friends;
    for (int i = 1; i <= n; i++) {
        friends.push_back(i);
    }
    
    auto it = friends.begin();
    while (friends.size() > 1) {
        for (int i = 1; i < k; i++) {
            it++;
            if (it == friends.end()) it = friends.begin();
        }
        
        auto toErase = it;
        it++;
        if (it == friends.end()) it = friends.begin();
        
        friends.erase(toErase);
    }
    
    return friends.front();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << findLastFriend(n, k) << endl;
    }
    return 0;
}