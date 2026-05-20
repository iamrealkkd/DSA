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

    int diameter(TreeNode* root, int &res)
    {
        // Base Case
        if(root == NULL)
            return 0;

        int l = diameter(root->left, res);
        int r = diameter(root->right, res);

        int temp = max(l, r) + 1;

        int ans = max(temp, l + r + 1);

        res = max(res, ans);

        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int res = INT_MIN;

        diameter(root, res);

        return res - 1;
    }
};

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5

    Diameter = 3
    Path = 4 -> 2 -> 1 -> 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << obj.diameterOfBinaryTree(root);

    return 0;
}