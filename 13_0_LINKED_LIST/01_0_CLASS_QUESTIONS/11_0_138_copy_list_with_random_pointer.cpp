#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        // Create head of copied list
        Node* newHead = new Node(head->val);

        // Map original head to copied head
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // Create copied nodes and next links
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);

            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Set random pointers
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Print list with random pointers
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << "Node(" << temp->val << ") ";

        if (temp->random)
            cout << "Random->" << temp->random->val;
        else
            cout << "Random->NULL";

        cout << endl;

        temp = temp->next;
    }
}

int main() {

    // Creating nodes
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Random pointers
    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List:\n";
    printList(n1);

    Solution obj;
    Node* copiedHead = obj.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}