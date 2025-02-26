#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty()) {
        auto [word, steps] = q.front(); q.pop();
        if (word == endWord) return steps;
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;
                word[i] = c;
                if (wordSet.count(word)) {
                    q.push({word, steps + 1});
                    wordSet.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string beginWord, endWord;
        int n;
        cin >> beginWord >> endWord >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++) cin >> wordList[i];
        cout << ladderLength(beginWord, endWord, wordList) << "\n";
    }
    return 0;
}