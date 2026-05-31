#include <iostream>
#include <vector>
#include <string>
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

    void allPaths(TreeNode* root,
                  string path,
                  vector<string>& ans) {

        // Leaf node reached
        if(root->left == nullptr &&
           root->right == nullptr) {

            ans.push_back(path);
            return;
        }

        // Go left
        if(root->left) {
            allPaths(root->left,
                     path + "->" +
                     to_string(root->left->val),
                     ans);
        }

        // Go right
        if(root->right) {
            allPaths(root->right,
                     path + "->" +
                     to_string(root->right->val),
                     ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;

        if(root == nullptr)
            return ans;

        string path = to_string(root->val);

        allPaths(root, path, ans);

        return ans;
    }
};

int main() {

    // root = [1,2,3,null,5]

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    Solution obj;

    vector<string> paths =
        obj.binaryTreePaths(root);

    for(string s : paths) {
        cout << s << endl;
    }

    return 0;
}