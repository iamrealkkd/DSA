#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if(root == NULL)
            return;

        inorder(root->left);

        if(prev != NULL && prev->val > root->val) {

            if(first == NULL)
                first = prev;

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

void printInorder(TreeNode* root) {
    if(root == NULL)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    // Tree: [1,3,null,null,2]

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    Solution obj;
    obj.recoverTree(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}