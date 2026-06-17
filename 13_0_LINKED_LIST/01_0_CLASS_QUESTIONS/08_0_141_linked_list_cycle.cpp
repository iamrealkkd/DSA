#include <iostream>
using namespace std;

// LeetCode Definition
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main() {
    // Creating linked list:
    // 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating cycle:
    // -4 points back to node with value 2
    fourth->next = second;

    Solution obj;

    if (obj.hasCycle(head))
        cout << "true" << endl;
    else
        cout << "No false" << endl;

    return 0;
}