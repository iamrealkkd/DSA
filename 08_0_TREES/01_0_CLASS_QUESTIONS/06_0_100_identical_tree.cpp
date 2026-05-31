#include <iostream>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both NULL or one NULL
        if (p == NULL || q == NULL)
            return p == q;

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame &&
               isRightSame &&
               (p->val == q->val);
    }
};

int main() {

    // p = [1,2,3]
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // q = [1,2,3]
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    bool ans = obj.isSameTree(p, q);

    cout << boolalpha << ans << endl;

    return 0;
}