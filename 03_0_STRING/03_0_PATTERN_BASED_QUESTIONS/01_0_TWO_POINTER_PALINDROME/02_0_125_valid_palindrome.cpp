#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int n = s.size();
    int l = 0;
    int r = n - 1;

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
  string s = "madam"; // Default value

  Solution obj;
  cout << boolalpha << obj.isPalindrome(s) << '\n';

  return 0;
}