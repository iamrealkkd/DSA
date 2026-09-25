#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int goWithPath(int i, int j, int m, int n, vector<vector<int>> &grid,
                 vector<vector<int>> &dp) {

    if (i < 0 || i >= m || j < 0 || j >= n)
      return INT_MAX;

    if (i == m - 1)
      return grid[i][j];

    if (dp[i][j] != INT_MAX)
      return dp[i][j];

    int path1 = goWithPath(i + 1, j - 1, m, n, grid, dp);
    int path2 = goWithPath(i + 1, j, m, n, grid, dp);
    int path3 = goWithPath(i + 1, j + 1, m, n, grid, dp);

    return dp[i][j] = grid[i][j] + min({path1, path2, path3});
  }

  int minFallingPathSum(vector<vector<int>> &grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    int ans = INT_MAX;

    for (int j = 0; j < n; j++) {

      ans = min(ans, goWithPath(0, j, m, n, grid, dp));
    }

    return ans;
  }
};

int main() {

  vector<vector<int>> grid = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

  Solution obj;

  cout << obj.minFallingPathSum(grid);

  return 0;
}