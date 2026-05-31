#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

static int idx = -1;

Node* buildTree(vector<int>& preorder) {
    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void kthLevel(Node* root, int K){
    if(root == NULL) return;
    if(K == 1){
        cout << root ->data << " ";
        return;
    }
    kthLevel(root -> left, K -1);
    kthLevel(root -> right, K -1);
    
}


int main() {

    vector<int> preorder ={1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    kthLevel(root, 3);
    cout << endl;
    kthLevel(root, 2);

    

    return 0;
}