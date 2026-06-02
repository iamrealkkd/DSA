#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Info {
public:
    int mini;
    int maxi;
    int size;

    Info(int mn, int mx, int sz) {
        mini = mn;
        maxi = mx;
        size = sz;
    }
};

class Solution {
public:

    Info helper(Node* root) {

        // Empty tree
        if(root == NULL) {
            return Info(INT_MAX, INT_MIN, 0);
        }

        Info left = helper(root->left);
        Info right = helper(root->right);

        // Current subtree is BST
        if(left.maxi < root->data &&
           root->data < right.mini) {

            return Info(
                min(root->data, left.mini),
                max(root->data, right.maxi),
                left.size + right.size + 1
            );
        }

        // Not a BST
        return Info(
            INT_MIN,
            INT_MAX,
            max(left.size, right.size)
        );
    }

    int largestBst(Node *root) {
        return helper(root).size;
    }
};

int main() {

    /*
              50
            /    \
          30      60
         /  \    /  \
        5   20  45   70
                     / \
                    65 80

        Largest BST:
              60
             /  \
            45   70
                /  \
               65  80

        Size = 5
    */

    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    Solution obj;

    cout << "Largest BST Size = "
         << obj.largestBst(root);

    return 0;
}