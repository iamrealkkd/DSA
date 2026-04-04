#include<iostream>
using namespace std;

void solve(int s, int d, int h, int n){
    if(n == 1){
        cout << "Moving Plate " << n << " from " << s << " to " << d << endl;
        return;
    }

    solve(s, h, d, n-1);
    cout << "Moving Plate " << n << " from " << s << " to " << d << endl;
    solve(h, d, s, n-1);
}

int main(){
    int n;
    cout << "Enter number of plates: ";
    cin >> n;

    int s = 1, h = 2, d = 3;
    solve(s, d, h, n);
}
/*
TOWER OF HANOI USING RECURSION

Problem:
Hume n plates ko Source rod (s) se Destination rod (d) tak move karna hai
using Helper rod (h).

Rules:
1. Ek time par sirf ek plate move kar sakte hain
2. Badi plate choti plate ke upar nahi rakh sakte
3. Sirf top plate hi move ho sakti hai

Rods:
s = Source
h = Helper
d = Destination

Example rods numbering:
1 → Source
2 → Helper
3 → Destination

------------------------------------------------------

RECURSION IDEA

To move n plates from source → destination

Step 1:
Move first (n-1) plates from Source → Helper

Step 2:
Move nth plate from Source → Destination

Step 3:
Move (n-1) plates from Helper → Destination

This pattern continues recursively.

------------------------------------------------------

FUNCTION PARAMETERS

solve(s, d, h, n)

s → source rod
d → destination rod
h → helper rod
n → number of plates

------------------------------------------------------

BASE CASE

if(n == 1)

Agar sirf 1 plate hai to directly
Source se Destination move kar do.

Example output:
Moving Plate 1 from 1 to 3

------------------------------------------------------

RECURSION FLOW

solve(s, h, d, n-1)

First move n-1 plates
Source → Helper

------------------------------------------------------

PRINT MOVE

cout << "Moving Plate " << n << " from " << s << " to " << d << endl;

Move the largest plate to destination.

------------------------------------------------------

FINAL STEP

solve(h, d, s, n-1)

Now move remaining plates
Helper → Destination

------------------------------------------------------

EXAMPLE (n = 3)

Initial rods

Source:      3 2 1
Helper:
Destination:

Moves:

Move Plate 1 from 1 to 3
Move Plate 2 from 1 to 2
Move Plate 1 from 3 to 2
Move Plate 3 from 1 to 3
Move Plate 1 from 2 to 1
Move Plate 2 from 2 to 3
Move Plate 1 from 1 to 3

------------------------------------------------------

TOTAL MOVES FORMULA

Minimum moves required:

Moves = 2^n - 1

Example

n = 3

Moves = 2^3 - 1
Moves = 7

------------------------------------------------------

TIME COMPLEXITY

O(2^n)

Reason:
Each recursive call splits into two more calls.

------------------------------------------------------

SPACE COMPLEXITY

O(n)

Reason:
Recursion stack depth n tak ja sakti hai.

------------------------------------------------------

INTERVIEW ONE LINE ANSWER

Tower of Hanoi recursively moves n-1 disks to the helper rod,
moves the largest disk to the destination rod,
and then moves the n-1 disks from helper to destination.
*/

