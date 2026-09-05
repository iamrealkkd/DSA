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
# REVERSE A STACK USING RECURSION (WITHOUT USING EXTRA DATA STRUCTURE)

### Goal:

Stack ko reverse karna hai sirf recursion use karke.

### Example Stack (bottom → top)

```text
1 2 3 4
```

```text
Top = 4
```

### After reversing

```text
4 3 2 1
```

---

# MAIN IDEA

Reverse stack 2 steps me hota hai:

1. Top element remove karo
2. Remaining stack ko reverse karo
3. Removed element ko stack ke **bottom** me insert karo

Isliye do functions use ho rahe hain:

```text
reverseStack()      → stack ko reverse karta hai
insertAtBottom()    → element ko bottom me insert karta hai
```

---

# STEP 1 — RECURSIVE REMOVAL (reverseStack)

### Initial stack

```text
bottom → 1 2 3 4 → top
```

Call:

```text
reverseStack(s)
```

### First call

```text
temp = 4
pop()
```

Stack:

```text
bottom → 1 2 3 → top
```

Call:

```text
reverseStack(s)
```

---

### Second call

```text
temp = 3
pop()
```

Stack:

```text
bottom → 1 2 → top
```

Call:

```text
reverseStack(s)
```

---

### Third call

```text
temp = 2
pop()
```

Stack:

```text
bottom → 1 → top
```

Call:

```text
reverseStack(s)
```

---

# BASE CASE

```cpp
if (s.size() == 1) {
    return;
}
```

Current stack:

```text
bottom → 1 → top
```

Ab recursion **reverse direction me return** karegi.

---

# STEP 2 — INSERT ELEMENTS AT BOTTOM

Current stack:

```text
bottom → 1 → top
```

### insertAtBottom(2)

Stack ke saare elements temporarily remove karenge.

```text
remove 1

stack = []
```

Push `2`:

```text
stack = [2]
```

Ab recursion return hone par removed `1` ko wapas push karenge:

```text
bottom → 2 1 → top
```

---

### insertAtBottom(3)

Current:

```text
bottom → 2 1 → top
```

Remove `1`:

```text
bottom → 2 → top
```

Remove `2`:

```text
stack = []
```

Push `3`:

```text
stack = [3]
```

Push back `2`:

```text
bottom → 3 2 → top
```

Push back `1`:

```text
bottom → 3 2 1 → top
```

---

### insertAtBottom(4)

Current:

```text
bottom → 3 2 1 → top
```

Remove `1`:

```text
bottom → 3 2 → top
```

Remove `2`:

```text
bottom → 3 → top
```

Remove `3`:

```text
stack = []
```

Push `4`:

```text
stack = [4]
```

Push back `3`:

```text
bottom → 4 3 → top
```

Push back `2`:

```text
bottom → 4 3 2 → top
```

Push back `1`:

```text
bottom → 4 3 2 1 → top
```

---

# FINAL STACK

```text
bottom → 4 3 2 1 → top
```

### Important:

Agar `main()` me:

```cpp
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

use karoge, to output hoga:

```text
1 2 3 4
```

Kyunki `s.top()` **top se bottom** print karta hai.

So:

```text
Final stack (bottom → top) = 4 3 2 1

Printed output (top → bottom) = 1 2 3 4
```

---

# PROGRAM FLOW

```text
main()
  |
  ↓
reverseStack(1,2,3,4)
  |
  ↓
reverseStack(1,2,3)
  |
  ↓
reverseStack(1,2)
  |
  ↓
reverseStack(1)
  |
  ↓
insertAtBottom(2)
  |
  ↓
insertAtBottom(3)
  |
  ↓
insertAtBottom(4)
```

---

# RECURSION PATTERN USED

```text
1. Remove element
2. Solve smaller problem
3. Insert removed element at the correct place
```

---

# TIME COMPLEXITY

```text
O(n²)
```

### Reason:

`reverseStack()` har element ko ek baar remove karta hai.

Phir har removed element ko `insertAtBottom()` ke through bottom me insert kiya jata hai.

`insertAtBottom()` worst case me stack ke `n` elements ko pop/push kar sakta hai.

Therefore:

```text
1 + 2 + 3 + ... + n
= O(n²)
```

---

# SPACE COMPLEXITY

```text
O(n)
```

### Reason:
# REVERSE A STACK USING RECURSION (WITHOUT USING EXTRA DATA STRUCTURE)

### Goal:

Stack ko reverse karna hai sirf recursion use karke.

### Example Stack (bottom → top)

```text
1 2 3 4
```

```text
Top = 4
```

### After reversing

```text
4 3 2 1
```

---

# MAIN IDEA

Reverse stack 2 steps me hota hai:

1. Top element remove karo
2. Remaining stack ko reverse karo
3. Removed element ko stack ke **bottom** me insert karo

Isliye do functions use ho rahe hain:

```text
reverseStack()      → stack ko reverse karta hai
insertAtBottom()    → element ko bottom me insert karta hai
```

---

# STEP 1 — RECURSIVE REMOVAL (reverseStack)

### Initial stack

```text
bottom → 1 2 3 4 → top
```

Call:

```text
reverseStack(s)
```

### First call

```text
temp = 4
pop()
```

Stack:

```text
bottom → 1 2 3 → top
```

Call:

```text
reverseStack(s)
```

---

### Second call

```text
temp = 3
pop()
```

Stack:

```text
bottom → 1 2 → top
```

Call:

```text
reverseStack(s)
```

---

### Third call

```text
temp = 2
pop()
```

Stack:

```text
bottom → 1 → top
```

Call:

```text
reverseStack(s)
```

---

# BASE CASE

```cpp
if (s.size() == 1) {
    return;
}
```

Current stack:

```text
bottom → 1 → top
```

Ab recursion **reverse direction me return** karegi.

---

# STEP 2 — INSERT ELEMENTS AT BOTTOM

Current stack:

```text
bottom → 1 → top
```

### insertAtBottom(2)

Stack ke saare elements temporarily remove karenge.

```text
remove 1

stack = []
```

Push `2`:

```text
stack = [2]
```

Ab recursion return hone par removed `1` ko wapas push karenge:

```text
bottom → 2 1 → top
```

---

### insertAtBottom(3)

Current:

```text
bottom → 2 1 → top
```

Remove `1`:

```text
bottom → 2 → top
```

Remove `2`:

```text
stack = []
```

Push `3`:

```text
stack = [3]
```

Push back `2`:

```text
bottom → 3 2 → top
```

Push back `1`:

```text
bottom → 3 2 1 → top
```

---

### insertAtBottom(4)

Current:

```text
bottom → 3 2 1 → top
```

Remove `1`:

```text
bottom → 3 2 → top
```

Remove `2`:

```text
bottom → 3 → top
```

Remove `3`:

```text
stack = []
```

Push `4`:

```text
stack = [4]
```

Push back `3`:

```text
bottom → 4 3 → top
```

Push back `2`:

```text
bottom → 4 3 2 → top
```

Push back `1`:

```text
bottom → 4 3 2 1 → top
```

---

# FINAL STACK

```text
bottom → 4 3 2 1 → top
```

### Important:

Agar `main()` me:

```cpp
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

use karoge, to output hoga:

```text
1 2 3 4
```

Kyunki `s.top()` **top se bottom** print karta hai.

So:

```text
Final stack (bottom → top) = 4 3 2 1

Printed output (top → bottom) = 1 2 3 4
```

---

# PROGRAM FLOW

```text
main()
  |
  ↓
reverseStack(1,2,3,4)
  |
  ↓
reverseStack(1,2,3)
  |
  ↓
reverseStack(1,2)
  |
  ↓
reverseStack(1)
  |
  ↓
insertAtBottom(2)
  |
  ↓
insertAtBottom(3)
  |
  ↓
insertAtBottom(4)
```

---

# RECURSION PATTERN USED

```text
1. Remove element
2. Solve smaller problem
3. Insert removed element at the correct place
```

---

# TIME COMPLEXITY

```text
O(n²)
```

### Reason:

`reverseStack()` har element ko ek baar remove karta hai.

Phir har removed element ko `insertAtBottom()` ke through bottom me insert kiya jata hai.

`insertAtBottom()` worst case me stack ke `n` elements ko pop/push kar sakta hai.

Therefore:

```text
1 + 2 + 3 + ... + n
= O(n²)
```

---

# SPACE COMPLEXITY

```text
O(n)
```

### Reason:

Recursion call stack ki maximum depth `O(n)` hoti hai.

`reverseStack()` ke recursive calls:

```text
reverseStack(4)
reverseStack(3)
reverseStack(2)
reverseStack(1)
```

Aur `insertAtBottom()` bhi recursion use karta hai.

Overall auxiliary space:

```text
O(n)
```

---

# INTERVIEW ONE-LINE EXPLANATION

We recursively remove the top element, reverse the remaining stack, and insert the removed element at the bottom to achieve stack reversal.

Recursion call stack ki maximum depth `O(n)` hoti hai.

`reverseStack()` ke recursive calls:

```text
reverseStack(4)
reverseStack(3)
reverseStack(2)
reverseStack(1)
```

Aur `insertAtBottom()` bhi recursion use karta hai.

Overall auxiliary space:

```text
O(n)
```

---

# INTERVIEW ONE-LINE EXPLANATION

We recursively remove the top element, reverse the remaining stack, and insert the removed element at the bottom to achieve stack reversal.
*/
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