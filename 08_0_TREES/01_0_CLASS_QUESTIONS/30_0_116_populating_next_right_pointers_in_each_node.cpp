#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) {
        val = _val;
        left = right = next = NULL;
    }
};

class Solution {
public:
    Node* connect(Node* root) {

        if(root == NULL)
            return NULL;

        queue<Node*> q;

        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while(!q.empty()) {

            Node* curr = q.front();
            q.pop();

            if(curr == NULL) {

                if(q.empty())
                    break;

                q.push(NULL);
                prev = NULL;
            }
            else {

                if(prev != NULL)
                    prev->next = curr;

                prev = curr;

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
        }

        return root;
    }
};

void printLevels(Node* root) {

    Node* levelStart = root;

    while(levelStart) {

        Node* curr = levelStart;

        while(curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }

        cout << "# ";

        levelStart = levelStart->left;
    }
}

int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4  5  6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    obj.connect(root);

    printLevels(root);

    return 0;
}