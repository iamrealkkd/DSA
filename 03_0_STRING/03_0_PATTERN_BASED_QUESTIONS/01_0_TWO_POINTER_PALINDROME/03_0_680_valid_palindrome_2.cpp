#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
      if (s[l] != s[r]) {
        return check(s, l + 1, r) || check(s, l, r - 1);
      }

      l++;
      r--;
    }

    return true;
  }

  bool check(string &s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r])
        return false;

      l++;
      r--;
    }

    return true;
  }
};

int main() {
  string s = "abca";

  Solution obj;
  cout << boolalpha << obj.validPalindrome(s) << '\n';

  return 0;
}