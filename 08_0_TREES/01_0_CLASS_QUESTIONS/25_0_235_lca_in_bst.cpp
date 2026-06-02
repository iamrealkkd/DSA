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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

TreeNode* buildTree() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    TreeNode* root = buildTree();
    Solution sol;

    TreeNode* p = root->left;
    TreeNode* q = root->right;
    cout << "LCA(2, 8) = " << sol.lowestCommonAncestor(root, p, q)->val << endl;

    p = root->left;
    q = root->left->right;
    cout << "LCA(2, 4) = " << sol.lowestCommonAncestor(root, p, q)->val << endl;

    p = root->left->right->left;
    q = root->left->right->right;
    cout << "LCA(3, 5) = " << sol.lowestCommonAncestor(root, p, q)->val << endl;

    return 0;
}