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