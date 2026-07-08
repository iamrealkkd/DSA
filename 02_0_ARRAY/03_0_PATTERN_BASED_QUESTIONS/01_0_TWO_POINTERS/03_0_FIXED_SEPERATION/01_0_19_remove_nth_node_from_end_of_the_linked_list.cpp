#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Create a dummy node.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Step 2: Initialize slow and fast.
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Step 3: Move fast (n + 1) steps ahead.
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4: Move both pointers.
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 5: Delete the target node.
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        // Step 6: Return new head.
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};

// Function to insert at end
void insert(ListNode*& head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return;
    }

    ListNode* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new ListNode(val);
}

// Function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

    // Create: 1 -> 2 -> 3 -> 4 -> 5
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    int n = 2;

    Solution obj;
    head = obj.removeNthFromEnd(head, n);

    cout << "After Removing " << n << "th Node From End: ";
    printList(head);

    return 0;
}