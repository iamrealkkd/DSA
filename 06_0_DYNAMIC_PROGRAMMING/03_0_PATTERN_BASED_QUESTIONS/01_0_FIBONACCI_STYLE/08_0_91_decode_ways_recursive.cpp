#include <bits/stdc++.h>
using namespace std;

int solve(int i, string &s, int &n) {
  if (i == n)
    return 1;
  if (s[i] == '0')
    return 0;

  int result = solve(i + 1, s, n);

  if (i + 1 < n) {
    if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
      result += solve(i + 2, s, n);
  }

  return result;
}

int numDecodings(string s) {
  int n = s.size();
  return solve(0, s, n);
}

int main() {
  string s = "226";

  cout << numDecodings(s) << endl;

  return 0;
}