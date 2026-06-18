#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while (first != NULL && sec != NULL) {
            ListNode* third = sec->next;

            sec->next = first;
            first->next = third;

            if (prev != NULL) {
                prev->next = sec;
            } else {
                head = sec;
            }

            // update
            prev = first;
            first = third;
            if (third != NULL) {
                sec = third->next;
            } else {
                sec = NULL;
            }
        }

        return head;
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
    ListNode* head = buildList({1, 2, 3, 4});
    cout << "Original:  "; print(head);

    Solution sol;
    ListNode* result = sol.swapPairs(head);
    cout << "Swapped:   "; print(result);

    // odd length test
    ListNode* head2 = buildList({1, 2, 3, 4, 5});
    cout << "Original:  "; print(head2);
    ListNode* result2 = sol.swapPairs(head2);
    cout << "Swapped:   "; print(result2);

    return 0;
}