#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int open, int close, string op, vector<string> &v) {
        if(open == 0 && close == 0) {
            v.push_back(op);
            return;
        }

        if(open != 0) {
            string op1 = op;
            op1.push_back('(');
            solve(open - 1, close, op1, v);
        }

        if(close > open) {
            string op2 = op;
            op2.push_back(')');
            solve(open, close - 1, op2, v);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string op = "";      // start with empty string
        solve(n, n, op, v);
        return v;
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(auto x : res) cout << x << endl;
}
/*
PROBLEM: GENERATE ALL VALID (BALANCED) PARENTHESES

Given n pairs of parentheses,
generate all valid combinations.

Example:
n = 3

Output:
((()))
(()())
(())()
()(())
()()()

------------------------------------------------------

CORE IDEA

We have:
n opening brackets '('
n closing brackets ')'

We must generate only VALID combinations.

------------------------------------------------------

RULES FOR VALID PARENTHESES

1) At any point:
   closing brackets should NEVER exceed opening

   i.e. close <= open (remaining logic inverse form)

2) We can add '(' if open > 0

3) We can add ')' only if close > open

------------------------------------------------------

FUNCTION PARAMETERS

solve(open, close, op, v)

open  → number of '(' remaining
close → number of ')' remaining
op    → current string
v     → result vector

------------------------------------------------------

BASE CASE

if(open == 0 && close == 0)

Means:
All brackets used

→ valid string formed

Store it:
v.push_back(op)

------------------------------------------------------

RECURSION LOGIC

CHOICE 1: ADD '('

Condition:
if(open != 0)

→ we still have opening brackets left

--------------------------------

CHOICE 2: ADD ')'

Condition:
if(close > open)

IMPORTANT CONDITION:

Why?

Because we should not close more brackets
than we have opened.

Example INVALID:
")(" ❌

So we only allow ')' when:

close > open

------------------------------------------------------

DRY RUN (n = 3)

Initial:
open = 3, close = 3

                ""
             /
           "("
         /     \
      "(("      "()"
     /   \      /   \
  "((("  "(()" "()("  "()()"
   ...     ...   ...     ...

------------------------------------------------------

FULL TREE (SIMPLIFIED)

                    ""
                   /
                 "("
               /     \
            "(("     "()"
           /   \      /   \
        "((("  "(()" "()("  "()()"
         |      |      |      |
      "((()"  "(())"  "()(("  "()()("
         |      |      |      |
     "((())" "(())(" "()(()" "()()()"
         |      |      |      |
    "((()))" "(())()" "()(())" "()()()"

------------------------------------------------------

VALID OUTPUTS

((()))
(()())
(())()
()(())
()()()

------------------------------------------------------

IMPORTANT CONDITIONS SUMMARY

if(open != 0)
→ add '('

if(close > open)
→ add ')'

------------------------------------------------------

WHY close > open ?

Example:

op = "(("

open = 1
close = 3

We can add ')'

But if:

op = ")(" ❌ (invalid)

So we ensure:

closing only when safe

------------------------------------------------------

TIME COMPLEXITY

O(2^n) approx (actually Catalan number)

Exact count:
Catalan(n) = (2n)! / (n! * (n+1)!)

------------------------------------------------------

SPACE COMPLEXITY

O(n)

Recursion stack

------------------------------------------------------

INTERVIEW ONE LINE

We generate valid parentheses using recursion
by adding '(' when available and ')' only when
it does not violate balance (close > open).
*/