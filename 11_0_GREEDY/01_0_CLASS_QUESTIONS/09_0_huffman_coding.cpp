#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data  = d;
        left  = NULL;
        right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min-heap
    }
};

class Solution {
public:
    void traverse(Node* root, vector<string>& ans, string temp) {
        // Base case: leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }
        traverse(root->left,  ans, temp + '0');
        traverse(root->right, ans, temp + '1');
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;

        // Push all freq nodes into min-heap
        for (int i = 0; i < N; i++) {
            Node* temp = new Node(f[i]);
            pq.push(temp);
        }

        // Build Huffman tree
        while (pq.size() > 1) {
            Node* left  = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* newNode   = new Node(left->data + right->data);
            newNode->left   = left;
            newNode->right  = right;
            pq.push(newNode);
        }

        // Traverse tree to get codes
        vector<string> ans;
        traverse(pq.top(), ans, "");
        return ans;
    }
};

int main() {
    Solution obj;

    string S      = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N         = 6;

    vector<string> result = obj.huffmanCodes(S, f, N);

    for (auto& code : result)
        cout << code << " ";
    cout << endl;
    // Expected: 0 100 101 1100 1101 111

    return 0;
}