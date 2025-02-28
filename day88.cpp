#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level-order tokens
TreeNode* buildTree(const vector<string>& tokens) {
    if(tokens.empty() || tokens[0] == "null")
        return nullptr;
    
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;  // Changed to size_t to match tokens.size()
    
    while(!q.empty() && i < tokens.size()){
        TreeNode* curr = q.front();
        q.pop();
        
        // Process left child
        if(i < tokens.size()){
            if(tokens[i] != "null"){
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
        }
        
        // Process right child
        if(i < tokens.size()){
            if(tokens[i] != "null"){
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
    }
    
    return root;
}

// Check if two trees are mirror images
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Check if the tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<string> tokens(n);
        for (int i = 0; i < n; i++) {
            cin >> tokens[i];
        }
        
        TreeNode* root = buildTree(tokens);
        cout << (isSymmetric(root) ? "true" : "false") << "\n";
    }
    
    return 0;
}
