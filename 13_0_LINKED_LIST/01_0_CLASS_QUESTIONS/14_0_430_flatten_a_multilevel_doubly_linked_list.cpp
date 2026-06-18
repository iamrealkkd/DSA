#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int v) {
        val = v;
        prev = next = child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                // flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                // find tail
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // attach tail with next ptr
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};

// helper to print the flattened list
void print(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Build: 1 <-> 2 <-> 3
    //                |
    //                4 <-> 5

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;

    n2->child = n4;
    n4->next = n5; n5->prev = n4;

    Solution sol;
    Node* result = sol.flatten(n1);

    print(result);  // 1->2->4->5->3

    return 0;
}
// Time Complexity: O(N)
// Each node is visited and processed once

// Space Complexity: O(D)
// D = Maximum child depth (recursion stack)
// Worst Case: O(N) when every node has a child

// Auxiliary Space: O(D)
// Due to recursive function calls