#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // check if k nodes exist
        while (cnt < k) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // recursively call for rest of LL
        ListNode* prevNode = reverseKGroup(temp, k);

        // reverse current group
        temp = head; cnt = 0;
        while (cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }

        return prevNode;
    }
};

// helpers
ListNode* buildList(initializer_list<int> vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

void print(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = buildList({1, 2, 3, 4, 5});
    cout << "Original:  "; print(head);

    Solution sol;
    ListNode* result = sol.reverseKGroup(head, 2);
    cout << "k=2 result: "; print(result);

    return 0;
}