#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &nums, int i, bool prevPick, int n) {
  if (i == n)
    return prevPick;

  if (prevPick) {
    int pick = recursion(nums, i + 1, true, n);
    int stop = 1;
    return pick + stop;
  }

  int skip = recursion(nums, i + 1, false, n);
  int start = recursion(nums, i + 1, true, n);

  return skip + start;
}

int memoization(vector<vector<int>> &dp, int i, bool prevPick, int n) {
  if (i == n)
    return prevPick;

  if (dp[i][prevPick] != -1)
    return dp[i][prevPick];

  if (prevPick) {
    int pick = memoization(dp, i + 1, true, n);
    int stop = 1;

    return dp[i][prevPick] = pick + stop;
  }

  int skip = memoization(dp, i + 1, false, n);
  int start = memoization(dp, i + 1, true, n);

  return dp[i][prevPick] = skip + start;
}

int tabulation(vector<int> &nums) {
  int n = nums.size();

  vector<vector<int>> dp(n + 1, vector<int>(2));

  dp[n][1] = 1;
  dp[n][0] = 0;

  for (int i = n - 1; i >= 0; i--) {
    dp[i][1] = dp[i + 1][1] + 1;
    dp[i][0] = dp[i + 1][0] + dp[i + 1][1];
  }

  return dp[0][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int n = nums.size();

  cout << "Recursion: " << recursion(nums, 0, false, n) << '\n';

  vector<vector<int>> dp(n, vector<int>(2, -1));

  cout << "Memoization: " << memoization(dp, 0, false, n) << '\n';

  cout << "Tabulation: " << tabulation(nums) << '\n';

  return 0;
}