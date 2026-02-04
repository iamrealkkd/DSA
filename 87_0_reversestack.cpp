#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int temp) {
    // Base case: stack empty
    if (s.empty()) {
        s.push(temp);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, temp);

    s.push(top);
}

void reverseStack(stack<int> &s) {
    // Base case
    if (s.size() == 1) {
        return;
    }

    int temp = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
