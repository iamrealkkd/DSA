#include <iostream>
#include <vector>
using namespace std;

int rec(int n, int prev, vector<vector<int>> &dp) {
  if (n == 0)
    return 1;

  if (dp[n][prev] != -1)
    return dp[n][prev];

  int put0 = rec(n - 1, 0, dp);

  int put1 = 0;

  if (prev != 1) {
    put1 = rec(n - 1, 1, dp);
  }

  return dp[n][prev] = put0 + put1;
}

int main() {
  int n = 3;

  vector<vector<int>> dp(n + 1, vector<int>(2, -1));

  cout << rec(n, 0, dp) << endl;

  return 0;
}