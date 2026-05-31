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

    bool isIdentical(TreeNode* p, TreeNode* q) {

        if(p == nullptr || q == nullptr)
            return p == q;

        return p->val == q->val &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == nullptr)
            return true;

        if(root == nullptr)
            return false;

        if(isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main() {

    // root = [3,4,5,1,2]

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);



    // subRoot = [4,1,2]

    TreeNode* subRoot = new TreeNode(4);

    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);



    Solution obj;

    bool ans = obj.isSubtree(root, subRoot);

    cout << boolalpha << ans << endl;

    return 0;
}