#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string input, string output, vector<string>& v){
        if(input.size() == 0){      
            v.push_back(output);    
            return;
        }

        if(isalpha(input[0])){
            string op1 = output;
            string op2 = output;
            op1.push_back(tolower(input[0]));
            op2.push_back(toupper(input[0])); 
            input.erase(input.begin());       
            solve(input, op1, v);
            solve(input, op2, v);
        } else {
            string op1 = output;
            op1.push_back(input[0]);
            input.erase(input.begin());       
            solve(input, op1, v);
        }
    }

    vector<string> letterCasePermutation(string s) {
        string ip = s;
        string op = "";
        vector<string> v;
        solve(ip, op, v);
        return v;   // return the result vector
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result = sol.letterCasePermutation(s);

    cout << "Letter case permutations:" << endl;
    for(auto str : result)
        cout << str << endl;

    return 0;
}
/*
PROBLEM: LETTER CASE PERMUTATION (WITH DIGITS HANDLED)

Given a string containing letters and digits,
generate all possible strings by changing
letter cases (lowercase / uppercase).

Digits remain unchanged.

------------------------------------------------------

EXAMPLE

Input:
a1b2

Output:
a1b2
a1B2
A1b2
A1B2

------------------------------------------------------

CORE IDEA

For each character:

If it is a LETTER:
→ 2 choices
   1) lowercase
   2) uppercase

If it is a DIGIT:
→ only 1 choice (as it is)

------------------------------------------------------

FUNCTION PARAMETERS

solve(input, output, vector)

input  → remaining characters
output → string built so far
v      → result vector (stores answers)

------------------------------------------------------

BASE CASE

if(input.size() == 0)

Means:
All characters processed

→ store output in vector

v.push_back(output)

------------------------------------------------------

RECURSION LOGIC

STEP 1:
Check first character

if(isalpha(input[0]))

--------------------------------

CASE 1: CHARACTER IS LETTER

Example:
input = "a1b2"

Take 'a'

Two choices:

op1 = "a"
op2 = "A"

Then remove 'a' from input

input = "1b2"

Call:

solve("1b2", "a")
solve("1b2", "A")

--------------------------------

CASE 2: CHARACTER IS DIGIT

Example:
input = "1b2"

Only one choice:

op = "1"

Call:

solve("b2", "1")

------------------------------------------------------

DRY RUN (INPUT = "a1b")

Initial:

solve("a1b", "")

--------------------------------

LEVEL 1 ('a')

         ""
       /    \
     "a"    "A"

--------------------------------

LEVEL 2 ('1')

         "a"        "A"
          |          |
        "a1"       "A1"

(digit → no branching)

--------------------------------

LEVEL 3 ('b')

From "a1":

→ "a1b"
→ "a1B"

From "A1":

→ "A1b"
→ "A1B"

--------------------------------

FINAL TREE

            ""
          /     \
        "a"     "A"
         |       |
       "a1"    "A1"
       /  \    /  \
   "a1b" "a1B" "A1b" "A1B"

------------------------------------------------------

FINAL OUTPUT

a1b
a1B
A1b
A1B

------------------------------------------------------

IMPORTANT CODE PARTS

if(isalpha(input[0]))

→ checks if character is letter

--------------------------------

tolower(ch)
toupper(ch)

→ convert character case

--------------------------------

input.erase(input.begin())

→ remove processed character

--------------------------------

vector<string>& v

→ pass by reference
→ taaki results store ho sake efficiently

------------------------------------------------------

TIME COMPLEXITY

O(2^L)

Where L = number of letters

Digits branching nahi karte

------------------------------------------------------

SPACE COMPLEXITY

O(n)

Recursion stack depth

------------------------------------------------------

INTERVIEW ONE LINE

This recursive solution generates all permutations by
branching on letters (lowercase/uppercase) and keeping
digits unchanged.
*/