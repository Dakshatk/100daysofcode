#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double calculate_distance(int x, int y, const string& instructions) {
    int n = instructions.length();
    int i = 0;

    while (i<n) {
        char direction = instructions[i];
        int distance = 0;
        i++;
        while (i<n && isdigit(instructions[i])) {
            distance = distance * 10 + (instructions[i] - '0');
            i++;
        }
        if (direction == 'U') {
            y += distance;
        } 
        else if (direction == 'D') {
            y -= distance;
        } 
        else if (direction == 'R') {
            x += distance;
        } 
        else if (direction == 'L') {
            x -= distance;
        }
    }

    return sqrt(1.0 * x * x + 1.0 * y * y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x, y;
        string instructions;
        cin >> x >> y >> instructions;
        cout << fixed << setprecision(2) << calculate_distance(x, y, instructions) << '\n';
    }

    return 0;
}