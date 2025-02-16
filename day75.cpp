#include <iostream>
#include <vector>
#include <climits>
#include <functional>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if(root == nullptr)
        return new Node(x);
    if(x <= root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void dfs(Node* root, int level, vector<long long>& levelSum) {
    if(!root)
        return;
    // Cast level to size_t to match vector size type
    if(levelSum.size() < static_cast<size_t>(level))
        levelSum.resize(level, 0);
    levelSum[level - 1] += root->val;
    dfs(root->left, level + 1, levelSum);
    dfs(root->right, level + 1, levelSum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    
    while(T--){
        int n; 
        cin >> n;
        Node* root = nullptr;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(root == nullptr)
                root = new Node(x);
            else
                insert(root, x);
        }
        
        // Compute the sum of employee IDs for each floor (level)
        vector<long long> levelSum;
        dfs(root, 1, levelSum);
        
        // Find the smallest level with the maximum sum
        long long maxSum = LLONG_MIN;
        int ansLevel = 0;
        for(size_t i = 0; i < levelSum.size(); i++){
            if(levelSum[i] > maxSum){
                maxSum = levelSum[i];
                ansLevel = i + 1; // converting 0-indexed to level number
            }
        }
        cout << ansLevel << "\n";
        
        // Free memory (delete the BST)
        function<void(Node*)> cleanup = [&](Node* node){
            if(!node) return;
            cleanup(node->left);
            cleanup(node->right);
            delete node;
        };
        cleanup(root);
    }
    return 0;
}
