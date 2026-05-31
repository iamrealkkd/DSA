#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
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

    // Find index of value in inorder array
    int search(vector<int>& inorder,
               int left,
               int right,
               int val) {

        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }

    // Recursive function to build tree
    TreeNode* helper(vector<int>& preorder,
                     vector<int>& inorder,
                     int& preIdx,
                     int left,
                     int right) {

        // Base Case
        if(left > right) {
            return NULL;
        }

        // Create root from preorder
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Find root position in inorder
        int inIdx = search(inorder,
                           left,
                           right,
                           root->val);

        preIdx++;

        // Build left subtree
        root->left = helper(preorder,
                            inorder,
                            preIdx,
                            left,
                            inIdx - 1);

        // Build right subtree
        root->right = helper(preorder,
                             inorder,
                             preIdx,
                             inIdx + 1,
                             right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int preIdx = 0;

        return helper(preorder,
                      inorder,
                      preIdx,
                      0,
                      inorder.size() - 1);
    }
};

// Level Order Printing (LeetCode style)
void printTree(TreeNode* root) {
    if(root == NULL) return;

    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if(curr) {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        }
        else {
            result.push_back("null");
        }
    }

    // Remove trailing nulls
    while(!result.empty() && result.back() == "null") {
        result.pop_back();
    }

    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i != result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main() {

    // Input:
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution obj;

    TreeNode* root = obj.buildTree(preorder, inorder);

    printTree(root);

    return 0;
}