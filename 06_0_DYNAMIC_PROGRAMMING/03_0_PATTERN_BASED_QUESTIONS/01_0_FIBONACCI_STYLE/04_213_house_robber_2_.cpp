#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {

    int n = nums.size();

    if (n == 1)
      return nums[0];

    // Case 1: exclude last house
    vector<int> dp1(n + 2, 0);

    for (int i = n - 2; i >= 0; i--) {
      dp1[i] = max(nums[i] + dp1[i + 2], dp1[i + 1]);
    }

    // Case 2: exclude first house
    vector<int> dp2(n + 2, 0);

    for (int i = n - 1; i >= 1; i--) {
      dp2[i] = max(nums[i] + dp2[i + 2], dp2[i + 1]);
    }

    return max(dp1[0], dp2[1]);
  }
};

int main() {

  // LeetCode Input:
  // nums = [1,2,3]

  vector<int> nums = {1, 2, 3};

  Solution obj;

  int ans = obj.rob(nums);

  cout << ans << endl;

  return 0;
}