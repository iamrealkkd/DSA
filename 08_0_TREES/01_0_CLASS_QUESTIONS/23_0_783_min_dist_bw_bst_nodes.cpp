#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
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

    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {

        if(root == NULL) {
            return INT_MAX;
        }

        int ans = INT_MAX;

        // Left Subtree
        if(root->left != NULL) {
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        // Current Node
        if(prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        // Right Subtree
        if(root->right != NULL) {
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
    }
};

int main() {

    /*
            4
           / \
          2   6
         / \
        1   3

        Min Difference = 1
    */

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    cout << obj.minDiffInBST(root);

    return 0;
}