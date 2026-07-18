#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {

    int n = nums.size();

    // n aur n+1 indexes ko base case ke liye 0 rakha
    vector<int> dp(n + 2, 0);

    // Last house se first house tak DP fill karenge
    for (int i = n - 1; i >= 0; i--) {

      // Current house rob karna
      int robCurrent = nums[i] + dp[i + 2];

      // Current house skip karna
      int skipCurrent = dp[i + 1];

      // Dono choices mein se maximum store karenge
      dp[i] = max(robCurrent, skipCurrent);
    }

    // House 0 se maximum robbery amount
    return dp[0];
  }
};

int main() {

  vector<int> nums = {2, 7, 9, 3, 1};

  Solution obj;

  int answer = obj.rob(nums);

  cout << answer << endl;

  return 0;
}