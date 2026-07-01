#include <cctype>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
  int l = 0;
  int r = s.size() - 1;

  while (l < r) {

    // Skip non-alphanumeric from left
    while (l < r && !isalnum(s[l])) {
      l++;
    }

    // Skip non-alphanumeric from right
    while (l < r && !isalnum(s[r])) {
      r--;
    }

    // Compare (case-insensitive)
    if (tolower(s[l]) != tolower(s[r])) {
      return false;
    }

    l++;
    r--;
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