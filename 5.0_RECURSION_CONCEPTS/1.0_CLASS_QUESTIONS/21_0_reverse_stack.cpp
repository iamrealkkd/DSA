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
/*
REVERSE A STACK USING RECURSION (WITHOUT USING EXTRA DATA STRUCTURE)

Goal:
Stack ko reverse karna hai sirf recursion use karke.

Example Stack (bottom → top)

1 2 3 4

Top = 4

After reversing

4 3 2 1

-----------------------------------------------------

MAIN IDEA

Reverse stack 2 steps me hota hai:

1. Top element remove karo
2. Remaining stack ko reverse karo
3. Removed element ko stack ke bottom me insert karo

Isliye do functions use ho rahe hain:

reverseStack()      → stack ko reverse karta hai
insertAtBottom()    → element ko bottom me insert karta hai

-----------------------------------------------------

STEP 1 — RECURSIVE REMOVAL (reverseStack)

Initial stack

1 2 3 4

Call

reverseStack(s)

temp = 4
pop()

Stack

1 2 3

call reverseStack(s)

--------------------------------

temp = 3
pop()

Stack

1 2

call reverseStack(s)

--------------------------------

temp = 2
pop()

Stack

1

call reverseStack(s)

--------------------------------

BASE CASE

stack size = 1

return

Ab recursion reverse direction me chalegi.

-----------------------------------------------------

STEP 2 — INSERT ELEMENTS AT BOTTOM

Current stack

1

insertAtBottom(2)

Stack empty hone tak pop karte hain.

remove 1

stack = []

push 2

stack = [2]

push back removed element

stack = [2,1]

--------------------------------

insertAtBottom(3)

remove 1
remove 2

stack = []

push 3

stack = [3]

push 2

stack = [3,2]

push 1

stack = [3,2,1]

--------------------------------

insertAtBottom(4)

remove 1
remove 2
remove 3

stack = []

push 4

stack = [4]

push 3

stack = [4,3]

push 2

stack = [4,3,2]

push 1

stack = [4,3,2,1]

-----------------------------------------------------

FINAL STACK

4 3 2 1

-----------------------------------------------------

PROGRAM FLOW

main()
 |
reverseStack(1,2,3,4)
 |
reverseStack(1,2,3)
 |
reverseStack(1,2)
 |
reverseStack(1)
 |
insertAtBottom(2)
 |
insertAtBottom(3)
 |
insertAtBottom(4)

-----------------------------------------------------

RECURSION PATTERN USED

1. Remove element
2. Solve smaller problem
3. Insert element at correct place

-----------------------------------------------------

TIME COMPLEXITY

O(n²)

Reason:
Har element ke liye insertAtBottom operation
stack ke sab elements ko pop/push kar sakta hai.

-----------------------------------------------------

SPACE COMPLEXITY

O(n)

Reason:
Recursion call stack depth n tak ja sakti hai.

-----------------------------------------------------

INTERVIEW ONE LINE EXPLANATION

We recursively remove the top element, reverse the remaining
stack, and insert the removed element at the bottom to achieve
stack reversal.
*/