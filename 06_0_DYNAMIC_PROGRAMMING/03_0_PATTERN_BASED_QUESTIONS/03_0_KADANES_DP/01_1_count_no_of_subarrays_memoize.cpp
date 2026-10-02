#include <iostream>
#include <vector>
using namespace std;

int recursion(const vector<int> &nums, int i, bool prevPick,
              vector<vector<int>> &dp) {

  int n = nums.size();

  // Base Case
  if (i == n) {
    return (prevPick == true) ? 1 : 0;
  }

  // Already calculated
  if (dp[i][prevPick] != -1) {
    return dp[i][prevPick];
  }

  // Case 1: Previous element was picked
  if (prevPick) {

    int pickInSubarr = recursion(nums, i + 1, true, dp);

    int stopHere = 1;

    return dp[i][prevPick] = pickInSubarr + stopHere;
  }

  // Case 2: No element has been picked yet
  else {

    int startNewFromNext = recursion(nums, i + 1, false, dp);

    int startNewFromCurr = recursion(nums, i + 1, true, dp);

    return dp[i][prevPick] = startNewFromNext + startNewFromCurr;
  }
}

int main() {

  vector<int> nums = {2, 2, 3, 6, 5};

  int n = nums.size();

  // n positions × 2 possible states
  vector<vector<int>> dp(n, vector<int>(2, -1));

  int totalSubarrays = recursion(nums, 0, false, dp);

  cout << totalSubarrays << endl;

  return 0;
}