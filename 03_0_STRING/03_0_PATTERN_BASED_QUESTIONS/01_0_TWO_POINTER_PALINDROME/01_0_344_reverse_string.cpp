
#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s) {
  int n = s.size();
  int l = 0;
  int r = n - 1;

  while (l < r) {
    swap(s[l], s[r]);
    l++;
    r--;
  }
}

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};

  reverseString(s);

  for (char ch : s) {
    cout << ch;
  }

  cout << endl;

  return 0;
}
