#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int k) {
    // Base case: when k = 1, remove middle element
    if (k == 1) {
        s.pop();
        return;
    }

    // Store top element
    int temp = s.top();
    s.pop();

    // Recursive call
    solve(s, k - 1);

    // Push back the stored element
    s.push(temp);
}

void deleteMiddle(stack<int> &s) {
    int k = (s.size() / 2) + 1;   // middle position
    solve(s, k);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMiddle(s);

    // Print stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
