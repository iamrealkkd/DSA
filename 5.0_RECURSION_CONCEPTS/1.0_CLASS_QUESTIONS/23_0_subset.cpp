#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op) {
  // Base case
  if (ip.length() == 0) {
    cout << op << endl;
    return;
  }

  // Choice 1: include first character
  string op1 = op;
  op1.push_back(ip[0]);

  // Choice 2: exclude first character
  string op2 = op;

  // Reduce input
  ip.erase(ip.begin());

  // Recursive calls
  solve(ip, op1); // include
  solve(ip, op2); // exclude
}

int main() {
  string ip = "abc";
  string op = "";

  solve(ip, op);

  return 0;
}
/*
PROBLEM: PRINT ALL SUBSEQUENCES (POWER SET) OF A STRING

Input:
"abc"

Output:
abc
ab
ac
a
bc
b
c
""

(empty string bhi ek valid subsequence hai)

------------------------------------------------------

CORE IDEA

Har character ke liye 2 choices hoti hain:

1) Include karo (character lo)
2) Exclude karo (character skip karo)

Isliye total subsequences:

2^n  (n = length of string)

------------------------------------------------------

FUNCTION PARAMETERS

solve(ip, op)

ip → input string (remaining characters)
op → output string (jo ab tak bana hai)

------------------------------------------------------

BASE CASE

if(ip.length() == 0)

Matlab saare characters process ho gaye
→ op print karo

------------------------------------------------------

STEP-BY-STEP DRY RUN (ip = "abc")

Initial Call:

solve("abc", "")

------------------------------------------------------

LEVEL 1 (character = 'a')

Two choices:

1) Include 'a'
2) Exclude 'a'

            ""
           /  \
         "a"   ""

------------------------------------------------------

LEVEL 2 (character = 'b')

From "a":

→ include b → "ab"
→ exclude b → "a"

From "":

→ include b → "b"
→ exclude b → ""

Tree now:

            ""
           /  \
         "a"   ""
        /  \   /  \
     "ab" "a" "b" ""

------------------------------------------------------

LEVEL 3 (character = 'c')

Now for each node:

From "ab":
→ include c → "abc"
→ exclude c → "ab"

From "a":
→ include c → "ac"
→ exclude c → "a"

From "b":
→ include c → "bc"
→ exclude c → "b"

From "":
→ include c → "c"
→ exclude c → ""

------------------------------------------------------

FINAL RECURSION TREE

                    ""
                 /       \
               "a"       ""
             /    \     /    \
          "ab"   "a"  "b"    ""
         /   \   / \  / \    / \
     "abc" "ab" "ac" "a" "bc" "b" "c" ""

------------------------------------------------------

PRINT ORDER (DFS order)

abc
ab
ac
a
bc
b
c
""

------------------------------------------------------

HOW CODE WORKS LINE BY LINE

string op1 = op;
op1.push_back(ip[0]);

→ Include current character

--------------------------------

string op2 = op;

→ Exclude current character

--------------------------------

ip.erase(ip.begin());

→ Current character remove kar diya
→ Ab recursion next character pe kaam karega

--------------------------------

solve(ip, op1); // include
solve(ip, op2); // exclude

→ Dono choices explore karte hain

------------------------------------------------------

IMPORTANT OBSERVATION

Order matters:

Include call pehle hai → isliye output me
pehle wo subsequences aate hain jisme characters included hain

------------------------------------------------------

TIME COMPLEXITY

O(2^n)

Reason:
Har character ke liye 2 recursive calls

------------------------------------------------------

SPACE COMPLEXITY

O(n)

Reason:
Recursion stack depth max n tak ja sakti hai

------------------------------------------------------

INTERVIEW ONE-LINE ANSWER

This recursion generates all subsequences by making
two choices at each step: include the current character
or exclude it.
*/