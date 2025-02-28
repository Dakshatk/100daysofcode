#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build the binary tree from level order tokens
TreeNode* buildTree(const vector<string>& tokens) {
    if(tokens.empty() || tokens[0] == "null")
        return nullptr;
        
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    size_t i = 1;  // using size_t to avoid signed/unsigned comparison warnings
    while(!q.empty() && i < tokens.size()){
        TreeNode* curr = q.front();
        q.pop();
        
        // Process left child
        if(i < tokens.size() && tokens[i] != "null"){
            curr->left = new TreeNode(stoi(tokens[i]));
            q.push(curr->left);
        }
        i++;
        
        // Process right child
        if(i < tokens.size() && tokens[i] != "null"){
            curr->right = new TreeNode(stoi(tokens[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Recursive function to check for a root-to-leaf path with the given sum.
bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root)
        return false;
    // If it's a leaf, check if the remaining sum equals the node's value.
    if(!root->left && !root->right)
        return root->val == targetSum;
    // Recursively check the left and right subtree with the updated sum.
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

// Helper function to free memory allocated for the tree.
void freeTree(TreeNode* root) {
    if(!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<string> tokens;
        tokens.reserve(n);
        
        // Read the level-order tokens. They may be integers or "null".
        for (int i = 0; i < n; i++){
            string token;
            cin >> token;
            tokens.push_back(token);
        }
        
        int targetSum;
        cin >> targetSum;
        
        TreeNode* root = buildTree(tokens);
        cout << (hasPathSum(root, targetSum) ? "true" : "false") << "\n";
        
        freeTree(root);
    }
    
    return 0;
}
