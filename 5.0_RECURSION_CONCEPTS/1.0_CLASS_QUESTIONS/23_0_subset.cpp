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