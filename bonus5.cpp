#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Helper function to generate sentences starting from index 'start'
vector<string> wordBreakHelper(const string &s, const unordered_set<string> &dict, size_t start, unordered_map<size_t, vector<string>> &memo) {
    // If we already computed the result for this starting index, return it.
    if (memo.find(start) != memo.end()) 
        return memo[start];
    
    vector<string> result;
    
    // If we've reached the end of the string, add an empty string as a valid segmentation.
    if (start == s.size()) {
        result.push_back("");
        return result;
    }
    
    // Try every possible substring starting from 'start'
    for (size_t end = start + 1; end <= s.size(); ++end) {
        string word = s.substr(start, end - start);
        // If the substring is a valid dictionary word, recursively process the remaining string.
        if (dict.find(word) != dict.end()) {
            vector<string> subSentences = wordBreakHelper(s, dict, end, memo);
            for (const string &sub : subSentences) {
                // If sub is empty, no extra space is needed.
                string space = sub.empty() ? "" : " ";
                result.push_back(word + space + sub);
            }
        }
    }
    
    memo[start] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        
        int N;
        cin >> N;
        
        unordered_set<string> dict;
        for (int i = 0; i < N; i++) {
            string word;
            cin >> word;
            dict.insert(word);
        }
        
        unordered_map<size_t, vector<string>> memo;
        vector<string> sentences = wordBreakHelper(S, dict, 0, memo);
        
        // If no valid segmentation exists, print an empty line.
        if (sentences.empty()) {
            cout << "\n";
        } else {
            for (const string &sentence : sentences) {
                cout << sentence << "\n";
            }
        }
    }
    
    return 0;
}
