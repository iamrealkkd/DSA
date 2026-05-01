#include <bits/stdc++.h>
using namespace std;

set<string> st;

void solve(string ip, string op) {

  // Base case
  if (ip.length() == 0) {
    st.insert(op); // store unique subsequence
    return;
  }

  // Include
  string op1 = op;
  op1.push_back(ip[0]);

  // Exclude
  string op2 = op;

  // Reduce input
  ip.erase(ip.begin());

  // Recursive calls
  solve(ip, op1);
  solve(ip, op2);
}

int main() {

  string ip = "aab";
  string op = "";

  solve(ip, op);

  // Print unique subsequences
  for (auto it : st) {
    cout << it << endl;
  }

  return 0;
}
/*
UNIQUE SUBSEQUENCES (NO DUPLICATES)

Goal:
Given a string (possibly with duplicate characters),
print ONLY UNIQUE subsequences.

Example:
Input:  "aab"

Normal subsequences (with duplicates):
aab
aa
ab
a
ab
a
b
""

Unique subsequences:
aab
aa
ab
a
b
""

------------------------------------------------------

APPROACH

We use a SET to automatically remove duplicates.

Why needed?
Because when input has duplicate characters (like "aab"),
same subsequence can be generated multiple times.

------------------------------------------------------

LOGIC

Same recursion as before:

At every step:
1) Include character
2) Exclude character

But instead of directly printing,
we insert results into a set.

Set ensures:
• No duplicate subsequences
• Automatically sorted (optional benefit)

------------------------------------------------------

TIME COMPLEXITY

O(2^n)

SPACE COMPLEXITY

O(2^n) (due to set storage)

------------------------------------------------------

CODE
*/