#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int expand(string s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      count++;
      left--;
      right++;
    }
    return count;
  }

  int countSubstrings(string s) {
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += expand(s, i, i);
      count += expand(s, i, i + 1);
    }
    return count;
  }
};

int main() {
  Solution sol;
  string s = "abc";
  cout << sol.countSubstrings(s) << endl;
  return 0;
}