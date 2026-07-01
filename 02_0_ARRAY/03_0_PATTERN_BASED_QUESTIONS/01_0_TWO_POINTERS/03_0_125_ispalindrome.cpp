#include <cctype> // isalnum(s[i]) tolower(s[l]) tolower(s[r]) using namespace std;
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ' || !isalnum(s[i])) {
      s.erase(i, 1);
      i--;
    }
  }

  int l = 0;
  int r = s.size() - 1;

  while (l < r) {
    if (tolower(s[l]) == tolower(s[r])) {
      l++;
      r--;
    } else if (s[l] != s[r]) {
      return false;
    }
  }

  return true;
}

int main() {
  string s = "A man, a plan, a canal: Panama";

  if (isPalindrome(s))
    cout << "true";
  else
    cout << "false";

  return 0;
}