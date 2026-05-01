#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output){

    // base condition
    if(input.length() == 0){
        cout << output << " ";
        return;
    }

    // case 1: without dash
    string output_1 = output;
    output_1.push_back(input[0]);

    // case 2: with dash
    string output_2 = output;
    output_2.push_back('-');
    output_2.push_back(input[0]);

    // remove first character
    input.erase(input.begin());

    // recursive calls
    solve(input, output_1);
    solve(input, output_2);
}

int main(){
    string input;
    cin >> input;

    string output = "";
    output.push_back(input[0]);

    input.erase(input.begin());

    solve(input, output);
}
/*
PROBLEM: Insert '-' (dash) between characters of a string in all possible ways.

Example
Input: ABC

Possible Outputs:
ABC
AB-C
A-BC
A-B-C

----------------------------------------------------

CORE IDEA

Between every two characters we have two choices:

1) Do NOT insert dash
2) Insert dash '-'

So recursion tries both possibilities.

If string length = n
possible outputs = 2^(n-1)

----------------------------------------------------

FUNCTION PARAMETERS

solve(input, output)

input  → remaining characters that are not processed yet
output → string built so far

----------------------------------------------------

BASE CASE

if(input.length() == 0)

Meaning:
All characters processed.

So print the current output string.

----------------------------------------------------

RECURSION WORKING

At each step we take the first character of input
and create two new possibilities.

Case 1:
Add the character normally

Example:
output = "A"
character = B

output_1 = "AB"

Case 2:
Add '-' then the character

output_2 = "A-B"

----------------------------------------------------

WHY input.erase(input.begin()) ?

Because we already processed the first character.

So we remove it and move recursion to the
remaining characters.

Example:

Input = "BC"

After erase

Input = "C"

----------------------------------------------------

RECURSION TREE (Example ABC)

Initial:

output = A
input  = BC

Choices for B:

          A
        /   \
      AB     A-B
     /  \    /  \
   ABC AB-C A-BC A-B-C

----------------------------------------------------

WHY FIRST CHARACTER DIRECTLY ADD IN MAIN ?

Because dash is inserted only BETWEEN characters.

We never start a string with '-'.

So first character goes directly into output.

Example:

input = ABC

output = A
input becomes = BC

----------------------------------------------------

TIME COMPLEXITY

O(2^(n-1))

Because each character creates two recursive branches.

----------------------------------------------------

SPACE COMPLEXITY

O(n)

Because recursion stack depth can go up to n.

----------------------------------------------------

INTERVIEW ONE LINE EXPLANATION

The algorithm generates all possible strings by recursively
choosing whether to insert a dash between characters or not.
*/
/*
PROBLEM
-------
Given a string, print all possible strings by inserting '-' (dash) between characters.

Example
Input:
ABC

Output:
ABC
AB-C
A-BC
A-B-C


MAIN IDEA
---------
Between every two characters we have 2 choices:

1) Do NOT insert dash
2) Insert dash '-'

So recursion tries both possibilities.

If string length = n

Total outputs = 2^(n-1)

Example:
ABC

Positions where dash can appear:

A _ B _ C

Two positions → each has 2 choices → total = 4 outputs


WHY FIRST CHARACTER DIRECTLY ADDED IN MAIN
------------------------------------------
Dash is only inserted BETWEEN characters.

So string cannot start with '-'.

Therefore we first put first character into output.

Example:

input = ABC

output = A
remaining input = BC


FUNCTION PARAMETERS
-------------------
solve(input, output)

input  → characters left to process
output → string built so far


BASE CASE
---------
if(input.length() == 0)

Means all characters processed.

So we print the current output.


RECURSION LOGIC
---------------
At each step we take the first character of input
and create two new possibilities.

Case 1 → without dash

Example:
output = A
next character = B

output_1 = AB


Case 2 → with dash

output_2 = A-B


After processing the character we remove it
from input using:

input.erase(input.begin())

Now recursion continues for remaining characters.


DRY RUN
-------
Input:
ABC


STEP 1 (main function)

input = "ABC"

output = ""
output.push_back(input[0])

output = "A"

remove first character

input = "BC"

call:

solve("BC", "A")


STEP 2

solve("BC", "A")

input not empty → continue

Two possibilities:

output_1 = "AB"
output_2 = "A-B"

remove first character

input = "C"

recursive calls:

solve("C", "AB")
solve("C", "A-B")


STEP 3

solve("C", "AB")

Two possibilities:

output_1 = "ABC"
output_2 = "AB-C"

remove character

input = ""

calls:

solve("", "ABC")
solve("", "AB-C")


STEP 4 (BASE CASE)

solve("", "ABC")

input empty

print:

ABC


Next

solve("", "AB-C")

print:

AB-C


STEP 5

Now return to second branch

solve("C", "A-B")

Two possibilities:

output_1 = "A-BC"
output_2 = "A-B-C"

remove character

input = ""

calls:

solve("", "A-BC")
solve("", "A-B-C")


STEP 6 (BASE CASE)

print:

A-BC
A-B-C


FINAL OUTPUT
------------
ABC
AB-C
A-BC
A-B-C


RECURSION TREE
--------------

            A
          /   \
        AB     A-B
       /  \    /  \
     ABC AB-C A-BC A-B-C


TIME COMPLEXITY
---------------
O(2^(n-1))

Because between every character we create
two recursive branches.


SPACE COMPLEXITY
----------------
O(n)

Due to recursion stack depth.


INTERVIEW ONE LINE ANSWER
-------------------------
This recursive solution generates all possible strings
by choosing whether to insert a dash between characters
or not at every step.
*/