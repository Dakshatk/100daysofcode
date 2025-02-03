#include <iostream>
#include <vector>
using namespace std;

// Structure to hold the value and corresponding Roman numeral
struct RomanNumeral {
    int value;
    string numeral;
};

// Array of Roman numeral mappings sorted from highest to lowest
const vector<RomanNumeral> romanMap = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

// Function to convert an integer to a Roman numeral string
string intToRoman(int num) {
    string result = "";
    for (const auto& entry : romanMap) {
        while (num >= entry.value) {
            result += entry.numeral;
            num -= entry.value;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int num;
        cin >> num;
        cout << intToRoman(num) << endl;
    }
    return 0;
}