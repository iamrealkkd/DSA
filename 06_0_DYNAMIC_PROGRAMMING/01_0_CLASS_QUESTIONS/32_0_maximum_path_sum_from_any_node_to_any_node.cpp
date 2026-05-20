#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:

    int solve(TreeNode* root, int &res)
    {
        // Base Case
        if(root == NULL)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(max(l, r) + root->val, root->val);

        int ans = max(temp, l + r + root->val);

        res = max(res, ans);

        return temp;
    }

    int maxPathSum(TreeNode* root) {

        int res = INT_MIN;

        solve(root, res);

        return res;
    }
};

int main() {

    /*
            1
           / \
          2   3

    Input: root = [1,2,3]

    Maximum Path Sum = 6
    Path = 2 -> 1 -> 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;

    cout << obj.maxPathSum(root);

    return 0;
}