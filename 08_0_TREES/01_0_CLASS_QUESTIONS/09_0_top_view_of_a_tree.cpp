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

void topView(Node* root) {

    if(root == NULL)
        return;

    queue<pair<Node*, int>> q;   // node, horizontal distance
    map<int, int> m;             // hd -> node value

    q.push({root, 0});

    while(!q.empty()) {

        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        // first node at this HD
        if(m.find(hd) == m.end()) {
            m[hd] = curr->data;
        }

        if(curr->left) {
            q.push({curr->left, hd - 1});
        }

        if(curr->right) {
            q.push({curr->right, hd + 1});
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }

    cout << endl;
}

int main() {

    vector<int> preorder =
    {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    topView(root);

    return 0;
}