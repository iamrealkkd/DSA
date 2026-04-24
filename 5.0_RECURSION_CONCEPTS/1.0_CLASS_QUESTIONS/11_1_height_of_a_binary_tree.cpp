#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to calculate height
int height(Node* root) {

    // Base Case
    if (root == NULL) {
        return 0;
    }

    // Left subtree height
    int lh = height(root->left);

    // Right subtree height
    int rh = height(root->right);

    // Return maximum + current node
    return 1 + max(lh, rh);
}

int main() {

    // Creating tree manually
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    cout << "Height of Tree: " << height(root);

    return 0;
}