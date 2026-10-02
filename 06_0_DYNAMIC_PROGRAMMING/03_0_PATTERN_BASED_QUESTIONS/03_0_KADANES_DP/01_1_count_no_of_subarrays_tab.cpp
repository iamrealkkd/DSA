#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {2, 2, 3, 6, 5};

  int n = nums.size();

  // dp[i][0] -> i index par, prevPick = false
  // dp[i][1] -> i index par, prevPick = true
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  // Base Case
  dp[n][0] = 0;
  dp[n][1] = 1;

  // Bottom-up
  for (int i = n - 1; i >= 0; i--) {

    // prevPick = true
    int pickInSubarr = dp[i + 1][1];
    int stopHere = 1;

    dp[i][1] = pickInSubarr + stopHere;

    // prevPick = false
    int startNewFromNext = dp[i + 1][0];
    int startNewFromCurr = dp[i + 1][1];

    dp[i][0] = startNewFromNext + startNewFromCurr;
  }

  cout << dp[0][0] << endl;

  return 0;
}