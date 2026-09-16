#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 3;

  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  dp[0][0] = 1;
  dp[0][1] = 1;

  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }

  cout << dp[n][0] << endl;

  return 0;
}