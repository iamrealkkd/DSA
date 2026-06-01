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
    TreeNode* helper(vector<int> nums, int st, int end) {
        if (st > end) return NULL;

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left  = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// BFS level-order print (null for missing nodes)
void printLevelOrder(TreeNode* root) {
    if (!root) { cout << "[]"; return; }

    queue<TreeNode*> q;
    q.push(root);
    vector<string> res;

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();

        if (node == NULL) {
            res.push_back("null");
        } else {
            res.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }
    }

    // trim trailing nulls
    while (res.back() == "null") res.pop_back();

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    printLevelOrder(root);  // [0,-3,9,-10,null,5]

    return 0;
}