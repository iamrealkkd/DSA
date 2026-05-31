#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* leftLCA =
            lowestCommonAncestor(root->left, p, q);

        TreeNode* rightLCA =
            lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA) {
            return root;
        }
        else if(leftLCA != NULL) {
            return leftLCA;
        }
        else {
            return rightLCA;
        }
    }
};

int main() {

    // root = [3,5,1,6,2,0,8,null,null,7,4]

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);



    // p = 5
    // q = 1

    TreeNode* p = root->left;
    TreeNode* q = root->right;



    Solution obj;

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << ans->val << endl;

    return 0;
}