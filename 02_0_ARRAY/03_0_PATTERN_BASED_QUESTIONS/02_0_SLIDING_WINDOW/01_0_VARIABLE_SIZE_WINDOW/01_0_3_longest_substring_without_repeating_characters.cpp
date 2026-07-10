#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// Definition exactly like LeetCode
class Solution {
public:
  int lengthOfLongestSubstring(string s) {

    unordered_set<char> window;

    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {

      // Shrink the window until s[right] becomes unique
      while (window.count(s[right])) {
        window.erase(s[left]);
        left++;
      }

      // Add current character
      window.insert(s[right]);

      // Update answer
      ans = max(ans, right - left + 1);
    }

    return ans;
  }
};

int main() {
  Solution obj;

  // LeetCode default test cases
  string s1 = "abcabcbb";

  cout << obj.lengthOfLongestSubstring(s1) << endl << endl;

  return 0;
}