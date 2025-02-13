#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int val) {
    if (root == nullptr) {
        return createNode(val);
    }
    // Insert duplicate values into the left subtree
    if (val <= root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

// Global variable to store the maximum ZigZag length found.
int ans = 0;

// DFS function to compute the longest ZigZag path.
// 'isLeft' indicates the direction of the last move:
//    true  -> last move was to the left (so next must go right)
//    false -> last move was to the right (so next must go left)
// 'len' is the current number of turns in the path.
void dfs(Node* node, bool isLeft, int len) {
    if (!node)
        return;
    ans = max(ans, len);
    if (isLeft) {
        // Last move was left, so continue by going right.
        if (node->right)
            dfs(node->right, false, len + 1);
        // Also, restart the zigzag from the left child.
        if (node->left)
            dfs(node->left, true, 1);
    } else {
        // Last move was right, so continue by going left.
        if (node->left)
            dfs(node->left, true, len + 1);
        // Restart the zigzag from the right child.
        if (node->right)
            dfs(node->right, false, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        Node* root = nullptr;
        
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            root = insertNode(root, val);
        }
        
        ans = 0; // Reset answer for the current test case.
        
        // Start DFS from the root's children if available.
        if (root) {
            if (root->left)
                dfs(root->left, true, 1);
            if (root->right)
                dfs(root->right, false, 1);
        }
        
        cout << ans << "\n";
        
        freeTree(root);
    }
    
    return 0;
}
