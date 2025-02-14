#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void findMaxDifference(TreeNode* root, int minVal, int maxVal, int &maxDiff) {
    if (!root) return;
    
    maxDiff = max(maxDiff, max(abs(root->val - minVal), abs(root->val - maxVal)));
    
    minVal = min(minVal, root->val);
    maxVal = max(maxVal, root->val);
    
    findMaxDifference(root->left, minVal, maxVal, maxDiff);
    findMaxDifference(root->right, minVal, maxVal, maxDiff);
}

int getMaxMagicalDifference(vector<int>& nums) {
    if (nums.empty()) return 0;
    TreeNode* root = nullptr;
    for (int num : nums) {
        root = insert(root, num);
    }
    
    int maxDiff = 0;
    findMaxDifference(root, root->val, root->val, maxDiff);
    return maxDiff;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << getMaxMagicalDifference(nums) << endl;
    }
    return 0;
}