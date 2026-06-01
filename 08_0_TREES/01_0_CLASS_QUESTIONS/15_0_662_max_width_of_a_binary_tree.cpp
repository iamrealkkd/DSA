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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while(q.size() > 0) {
            int currLevelSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for(int i = 0; i < currLevelSize; i++) {
                auto curr = q.front();
                q.pop();

                if(curr.first->left) {
                    q.push({curr.first->left, curr.second * 2 + 1});
                }
                if(curr.first->right) {
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }

        return maxWidth;
    }
};

int main() {
    //        1
    //       / \
    //      3   2
    //     / \   \
    //    5   3   9

    TreeNode* root = new TreeNode(1);
    root->left      = new TreeNode(3);
    root->right     = new TreeNode(2);
    root->left->left  = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    cout  << sol.widthOfBinaryTree(root) << endl;
    // Expected output: 4

    return 0;
}