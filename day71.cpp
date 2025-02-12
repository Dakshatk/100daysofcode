#include <iostream>
#include <vector>
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
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        root = createNode(val);
        return root;
    }

    if (val <= root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }

    return root;
}

int findHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Node* root = NULL;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            root = insertNode(root, val);
        }

        cout << findHeight(root) << endl;
    }

    return 0;
}