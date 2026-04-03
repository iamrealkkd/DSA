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

/*
DELETE MIDDLE ELEMENT OF STACK USING RECURSION

Goal:
Stack ka middle element delete karna hai bina extra data structure use kiye.
Sirf recursion use karenge.

-----------------------------------------------------

Example Stack (bottom → top)

1 2 3 4 5

Top element = 5

Middle element = 3

After deleting middle:

1 2 4 5

-----------------------------------------------------

STEP 1 — FIND MIDDLE POSITION

k = (size / 2) + 1

For size = 5

k = (5 / 2) + 1
k = 2 + 1
k = 3

Matlab 3rd element from top remove karna hai.

Stack view from top:

Top
5  ← position 1
4  ← position 2
3  ← position 3 (delete this)
2
1

-----------------------------------------------------

STEP 2 — RECURSION PROCESS

solve(stack, k)

Idea:
Top elements ko temporarily remove karte jayenge
jab tak middle element na mil jaye.

-----------------------------------------------------

CALL FLOW

Initial stack

1 2 3 4 5

Call

solve(s,3)

-----------------------------------------------------

First call

temp = 5
pop()

Stack

1 2 3 4

call

solve(s,2)

-----------------------------------------------------

Second call

temp = 4
pop()

Stack

1 2 3

call

solve(s,1)

-----------------------------------------------------

BASE CASE

k == 1

Top element remove

pop()

Stack becomes

1 2

Middle element (3) delete ho gaya.

-----------------------------------------------------

STEP 3 — RESTORE ELEMENTS

Recursion reverse direction me aayegi.

push back stored elements.

push 4

Stack

1 2 4

push 5

Stack

1 2 4 5

-----------------------------------------------------

FINAL STACK

1 2 4 5

-----------------------------------------------------

PROGRAM FLOW

main()
 |
deleteMiddle()
 |
solve(s,3)
 |
solve(s,2)
 |
solve(s,1)
 |
delete middle
 |
push 4
 |
push 5

-----------------------------------------------------

RECURSION PATTERN USED

1. Pop element
2. Solve smaller problem
3. Push element back

-----------------------------------------------------

TIME COMPLEXITY

O(n)

Reason:
Stack ke elements ek baar pop aur ek baar push hote hain.

-----------------------------------------------------

SPACE COMPLEXITY

O(n)

Reason:
Recursion call stack depth n tak ja sakti hai.

-----------------------------------------------------

INTERVIEW ONE LINE EXPLANATION

We recursively pop elements until reaching the middle
position, remove the middle element, and then push the
stored elements back to restore the stack order.
*/