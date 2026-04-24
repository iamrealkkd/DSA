#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1 && k == 1)
            return 0;

        int mid = pow(2, n - 1) / 2;

        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !kthGrammar(n - 1, k - mid);
        }
    }
};

int main() {
    Solution obj;
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    cout << "Kth Grammar Value: " << obj.kthGrammar(n, k) << endl;

    return 0;
}
/*
K-TH GRAMMAR PROBLEM (RECURSION)

Problem:
We are given a grammar sequence defined as:

Row 1: 0
Row 2: 0 1
Row 3: 0 1 1 0
Row 4: 0 1 1 0 1 0 0 1
...

Rule:
0 → 01
1 → 10

We need to find the K-th symbol in N-th row.

----------------------------------------------------

CORE IDEA

Each row doubles in size.

Length of nth row = 2^(n-1)

Instead of building the full row (which is expensive),
we use recursion to trace back to previous rows.

----------------------------------------------------

PATTERN OBSERVATION

Every row can be divided into 2 halves:

Left half  → same as previous row
Right half → complement (flip) of previous row

----------------------------------------------------

LOGIC USED

1️⃣ Find mid of current row

mid = (2^(n-1)) / 2

2️⃣ If k lies in left half:
→ Answer same as previous row

kthGrammar(n, k) = kthGrammar(n-1, k)

3️⃣ If k lies in right half:
→ Answer is complement of previous row

kthGrammar(n, k) = !kthGrammar(n-1, k - mid)

----------------------------------------------------

BASE CASE

if(n == 1 && k == 1)
return 0

Because first row always contains only '0'

----------------------------------------------------

DRY RUN EXAMPLE

Find kthGrammar(4,5)

Row 4 = 0 1 1 0 1 0 0 1

Answer = 1

--------------------------------

Step 1:

n = 4, k = 5

length = 2^(4-1) = 8
mid = 4

k > mid → right half

So:

kthGrammar(4,5)
= !kthGrammar(3, 5-4)
= !kthGrammar(3,1)

--------------------------------

Step 2:

kthGrammar(3,1)

k <= mid → left half

= kthGrammar(2,1)

--------------------------------

Step 3:

kthGrammar(2,1)

k <= mid → left half

= kthGrammar(1,1)

--------------------------------

Step 4 (BASE CASE)

kthGrammar(1,1) = 0

--------------------------------

Backtracking:

kthGrammar(2,1) = 0
kthGrammar(3,1) = 0
kthGrammar(4,5) = !0 = 1

FINAL ANSWER = 1

----------------------------------------------------

WHY '!' IS USED

'!' flips the bit:

!0 = 1
!1 = 0

Because right half is complement of left half.

----------------------------------------------------

TIME COMPLEXITY

O(n)

Because recursion depth goes from n → 1

----------------------------------------------------

SPACE COMPLEXITY

O(n)

Due to recursion stack

----------------------------------------------------

IMPORTANT NOTE

pow(2, n-1) gives length of row
mid = half of that

Better alternative (faster):

int mid = 1 << (n-2);

----------------------------------------------------

INTERVIEW ONE-LINE

The problem is solved by recursively determining whether
k lies in the left or right half of the row, where the right
half is the complement of the left half.
*/