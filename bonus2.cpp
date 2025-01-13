#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string genders;
        cin >> genders;

        int males = 0, females = 0;

        // Count the number of males and females
        for (char gender : genders) {
            if (gender == 'M') {
                males++;
            } else if (gender == 'F') {
                females++;
            }
        }

        // Calculate the maximum number of valid teams
        // Each team needs at least 1 female and 3 others (can be males or females)
        int maxTeams = 0;

        while (females > 0 && (females + males) >= 4) {
            maxTeams++;
            females--;  // One female for inclusivity
            // Remove the remaining 3 members from the available pool
            if (males >= 3) {
                males -= 3;
            } else {
                int remaining = 3 - males;
                males = 0;
                females -= remaining;
            }
        }

        cout << maxTeams << endl;
    }

    return 0;
}
