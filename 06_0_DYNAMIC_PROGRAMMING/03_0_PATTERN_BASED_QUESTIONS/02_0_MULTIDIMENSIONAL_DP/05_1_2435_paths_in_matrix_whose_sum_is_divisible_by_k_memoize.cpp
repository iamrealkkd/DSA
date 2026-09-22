#include <iostream>
#include <vector>
    using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;

  int solve(int i, int j, int m, int n, int k, vector<vector<int>> &grid,
            int sum, vector<vector<vector<int>>> &dp) {

    if (i >= m || j >= n)
      return 0;

    sum += grid[i][j];
    sum %= k;

    if (i == m - 1 && j == n - 1) {
      if (sum == 0)
        return 1;
      return 0;
    }

    if (dp[i][j][sum] != -1)
      return dp[i][j][sum];

    return dp[i][j][sum] = (solve(i + 1, j, m, n, k, grid, sum, dp) +
                            solve(i, j + 1, m, n, k, grid, sum, dp)) %
                           MOD;
  }

  int numberOfPaths(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<vector<int>>> dp(m,
                                   vector<vector<int>>(n, vector<int>(k, -1)));

    return solve(0, 0, m, n, k, grid, 0, dp);
  }
};

int main() {

  vector<vector<int>> grid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};

  int k = 3;

  Solution obj;

  cout << obj.numberOfPaths(grid, k) << endl;

  return 0;
}
