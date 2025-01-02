#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Function to calculate the maximum palindrome length
vector<int> maxPalindromeLengths(const vector<string>& testCases){
    vector<int> results;
    
    for (const string& s : testCases) {
        unordered_map<char, int> charCount;
        
        // Count frequencies of each character
        for (char c : s) {
            charCount[c]++;
        }
        
        int palindromeLength = 0;
        bool oddFound = false;
        
        // Calculate the maximum palindrome length
        for (const auto& pair : charCount) {
            int count = pair.second;
            if(count % 2 == 0){
                palindromeLength += count;
            } 
            else{
                palindromeLength += count - 1;
                oddFound = true;
            }
        }
        
        // Add one if an odd count exists
        if (oddFound) {
            palindromeLength += 1;
        }
        
        results.push_back(palindromeLength);
    }
    
    return results;
}

int main() {
    int T;
    cin >> T;
    vector<string> testCases(T);
    
    // Input the test cases
    for (int i = 0; i < T; ++i) {
        cin >> testCases[i];
    }
    
    // Get the results
    vector<int> results = maxPalindromeLengths(testCases);
    
    // Output the results
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}
