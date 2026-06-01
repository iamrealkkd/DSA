#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {

        if(root == NULL) {
            return true;
        }

        if(min != NULL && root->val <= min->val) {
            return false;
        }

        if(max != NULL && root->val >= max->val) {
            return false;
        }

        return helper(root->left, min, root) &&
               helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};

int main() {

    // root = [2,1,3]

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution obj;

    if(obj.isValidBST(root)) {
        cout << "Valid BST";
    }
    else {
        cout << "Not a Valid BST";
    }

    return 0;
}