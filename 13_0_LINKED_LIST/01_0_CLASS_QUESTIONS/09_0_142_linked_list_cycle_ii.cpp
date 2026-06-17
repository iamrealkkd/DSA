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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool isCycle = false;

        // Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return NULL;
        }

        // Find start of cycle
        slow = head;
        // ListNode* prev = NULL; for remove cycle
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        // prev -> next = NULL; for remove cycle
        return slow;
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

    // Create cycle
    // -4 -> 2
    fourth->next = second;

    Solution obj;

    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle starts at node with value: "
             << cycleStart->val << endl;
    } else {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}