#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return helper(root, k, count);
    }

private:
    int helper(TreeNode* root, int k, int& count) {
        if (root == NULL) return -1;

        int leftAns = helper(root->left, k, count);
        if (leftAns != -1) return leftAns;

        count++;
        if (count == k) return root->val;

        return helper(root->right, k, count);
    }
};

// Build tree: [3,1,4,null,2]
//     3
//    / \
//   1   4
//    \
//     2
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    return root;
}

int main() {
    TreeNode* root = buildTree();
    int k = 1;

    Solution sol;
    int ans = sol.kthSmallest(root, k);

    cout << "K = " << k << endl;
    cout << "Kth Smallest = " << ans << endl;

    return 0;
}