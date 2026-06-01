#include <iostream>
using namespace std;

// Definition for Binary Tree
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

    TreeNode* nextRight = NULL;

    void flatten(TreeNode* root) {

        // Base Case
        if(root == NULL)
            return;

        // Reverse Preorder
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;

        nextRight = root;
    }
};

int main() {

    /*
            1
           / \
          2   5
         / \   \
        3   4   6

    Input:
    [1,2,5,3,4,null,6]

    Flattened Output:
    1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    Solution obj;

    obj.flatten(root);

    // Print Flattened Linked List
    TreeNode* curr = root;

    while(curr != NULL) {
        cout << curr->val;

        if(curr->right != NULL)
            cout << " -> ";

        curr = curr->right;
    }

    cout << endl;

    return 0;
}