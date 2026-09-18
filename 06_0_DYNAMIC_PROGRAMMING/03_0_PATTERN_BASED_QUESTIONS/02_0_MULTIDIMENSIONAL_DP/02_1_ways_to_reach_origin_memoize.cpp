#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int solve(int x, int y, vector<vector<int>> &dp) {
  if (x == 0 && y == 0)
    return 1;

  if (x < 0 || y < 0)
    return 0;

  if (dp[x][y] != -1)
    return dp[x][y];

  long long cnt = (1LL * solve(x - 1, y, dp) + solve(x, y - 1, dp)) % MOD;

  return dp[x][y] = cnt;
}

int ways(int x, int y) {
  vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

  return solve(x, y, dp);
}

int main() {
  int x = 3;
  int y = 0;

  cout << ways(x, y);

  return 0;
}