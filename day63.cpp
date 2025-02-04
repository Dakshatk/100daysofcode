#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countCollisions(const string& directions) {
    int collisions = 0;
    int movingRight = 0;
    bool hasStationary = false;
    
    for (char dir : directions) {
        if (dir == 'R') {
            movingRight++;
        } else if (dir == 'S') {
            collisions += movingRight;
            movingRight = 0;
            hasStationary = true;
        } else if (dir == 'L') {
            if (movingRight > 0) {
                collisions += movingRight + 1;
                movingRight = 0;
                hasStationary = true;
            } else if (hasStationary) {
                collisions++;
            }
        }
    }
    return collisions;
}

int main() {
    int T;
    cin >> T;
    vector<int> results(T);
    
    for (int i = 0; i < T; i++) {
        string directions;
        cin >> directions;
        results[i] = countCollisions(directions);
    }
    
    for (int result : results) {
        cout << result << "\n";
    }
    
    return 0;
}