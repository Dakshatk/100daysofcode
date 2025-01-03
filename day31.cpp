#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Function to check if a phrase is a palindrome
bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        // Compare characters after converting to lowercase
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int T; // Number of test cases
    cin >> T;
    cin.ignore(); // Ignore the newline character after the number of test cases

    for (int t = 0; t < T; ++t) {
        string s;
        getline(cin, s);

        // Check if the phrase is a palindrome and print the result
        if (isPalindrome(s)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}