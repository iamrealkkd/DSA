#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op)
{
    // base condition
    if(ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    // case 1: uppercase
    string op1 = op;
    // case 2: lowercase
    string op2 = op;
    op1.push_back(tolower(ip[0]));
    op2.push_back(toupper(ip[0]));
    

    // input ka first character remove
    ip.erase(ip.begin() + 0);

    // recursive calls
    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string ip = "AB";
    string op = "";

    solve(ip, op);

    return 0;
}
/*
PROBLEM: PRINT ALL CASE PERMUTATIONS OF A STRING

Given a string, generate all possible combinations by
changing each character to lowercase or uppercase.

Example:
Input:  "AB"

Output:
ab
aB
Ab
AB

------------------------------------------------------

CORE IDEA

Har character ke liye 2 choices hoti hain:

1) Lowercase
2) Uppercase

Total combinations = 2^n

------------------------------------------------------

FUNCTION PARAMETERS

solve(ip, op)

ip → remaining input string
op → output string built so far

------------------------------------------------------

BASE CASE

if(ip.length() == 0)

Matlab saare characters process ho gaye
→ op print karo

------------------------------------------------------

STEP-BY-STEP DRY RUN (ip = "AB")

Initial Call:

solve("AB", "")

------------------------------------------------------

LEVEL 1 (character = 'A')

2 choices:

1) lowercase → 'a'
2) uppercase → 'A'

Tree:

           ""
         /    \
       "a"     "A"

------------------------------------------------------

LEVEL 2 (character = 'B')

From "a":

→ lowercase → "ab"
→ uppercase → "aB"

From "A":

→ lowercase → "Ab"
→ uppercase → "AB"

------------------------------------------------------

FINAL TREE

            ""
          /     \
        "a"     "A"
       /   \   /   \
    "ab" "aB" "Ab" "AB"

------------------------------------------------------

PRINT ORDER (DFS)

ab
aB
Ab
AB

------------------------------------------------------

CODE FLOW EXPLANATION

string op1 = op;
string op2 = op;

→ do copies banayi output ki

--------------------------------

op1.push_back(tolower(ip[0]));

→ lowercase version add kiya

--------------------------------

op2.push_back(toupper(ip[0]));

→ uppercase version add kiya

--------------------------------

ip.erase(ip.begin());

→ current character remove
→ next recursion me next character process hoga

--------------------------------

solve(ip, op1); // lowercase branch
solve(ip, op2); // uppercase branch

------------------------------------------------------

TIME COMPLEXITY

O(2^n)

Reason:
Har character ke liye 2 recursive calls

------------------------------------------------------

SPACE COMPLEXITY

O(n)

Reason:
Recursion stack depth n tak ja sakta hai

------------------------------------------------------

IMPORTANT NOTE

toupper() aur tolower() C++ functions hain
jo character ka case convert karte hain

Example:

toupper('a') → 'A'
tolower('A') → 'a'

------------------------------------------------------

INTERVIEW ONE LINE

This recursion generates all case permutations by
choosing lowercase or uppercase for each character.
*/