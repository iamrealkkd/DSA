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
    TreeNode* helper(vector<int>& preorder, int &i, int bound) {
        if(i >= preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};

// print inorder to verify BST is correct
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Preorder input : ";
    for(int x : preorder) cout << x << " ";
    cout << endl;

    cout << "Inorder output : ";
    inorder(root);
    cout << endl;

    return 0;
}