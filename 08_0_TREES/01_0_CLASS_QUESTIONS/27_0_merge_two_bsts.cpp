#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// insert into BST
Node* insert(Node* root, int val) {
    if(root == NULL) return new Node(val);
    if(val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// build BST from array
Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    for(int x : arr) root = insert(root, x);
    return root;
}

// inorder traversal → sorted array
void inorder(Node* root, vector<int>& arr) {
    if(root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// build BST from sorted array (balanced)
Node* buildBSTFromSorted(vector<int>& arr, int st, int end) {
    if(st > end) return NULL;

    int mid = st + (end - st) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBSTFromSorted(arr, st, mid - 1);
    root->right = buildBSTFromSorted(arr, mid + 1, end);

    return root;
}

// merge two BSTs
Node* merge2BST(Node* root1, Node* root2) {
    // step 1: inorder of both trees
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    // step 2: merge two sorted arrays
    vector<int> temp;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) temp.push_back(arr1[i++]);
        else temp.push_back(arr2[j++]);
    }
    while(i < arr1.size()) temp.push_back(arr1[i++]);
    while(j < arr2.size()) temp.push_back(arr2[j++]);

    // step 3: build balanced BST from sorted merged array
    return buildBSTFromSorted(temp, 0, temp.size() - 1);
}

int main() {
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = buildBST(arr1);
    Node* root2 = buildBST(arr2);

    Node* root = merge2BST(root1, root2);

    vector<int> seq;
    inorder(root, seq);

    cout << "Merged BST inorder: ";
    for(int v : seq) cout << v << " ";
    cout << endl;

    return 0;
}