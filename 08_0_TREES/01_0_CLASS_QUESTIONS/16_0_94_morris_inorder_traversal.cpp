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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // find the IP (inorder predecessor)
                TreeNode* IP = curr->left;
                while(IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if(IP->right == NULL) {
                    IP->right = curr; // create thread
                    curr = curr->left;
                } else {
                    IP->right = NULL; // destroy thread
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main() {
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder: ";
    for(int x : result) cout << x << " ";
    cout << endl;
    // Output: 1 3 2

    return 0;
}