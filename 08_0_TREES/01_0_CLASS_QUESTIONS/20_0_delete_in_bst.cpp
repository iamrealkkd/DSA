#include <iostream>
#include <vector>
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

// Insert into BST
Node* insert(Node* root, int val) {

    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Build BST
Node* buildBST(vector<int>& arr) {

    Node* root = NULL;

    for(int val : arr) {
        root = insert(root, val);
    }

    return root;
}

// Find Inorder Successor
Node* getInorderSuccessor(Node* root) {

    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Delete Node
Node* delNode(Node* root, int key) {

    // Base Case
    if(root == NULL)
        return NULL;

    // Search in Left Subtree
    if(key < root->data) {
        root->left = delNode(root->left, key);
    }

    // Search in Right Subtree
    else if(key > root->data) {
        root->right = delNode(root->right, key);
    }

    // Node Found
    else {

        // Case 1: No Left Child
        if(root->left == NULL) {

            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No Right Child
        else if(root->right == NULL) {

            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two Children
        else {

            Node* IS = getInorderSuccessor(root->right);

            root->data = IS->data;

            root->right = delNode(root->right, IS->data);
        }
    }

    return root;
}

int main() {

    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);

    cout << "Before Deletion: ";
    inorder(root);
    cout << endl;

    int key = 5;

    root = delNode(root, key);

    cout << "After Deletion of " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
} 