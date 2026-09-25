#include <bits/stdc++.h>
using namespace std;

int find(vector<vector<int>> &grid, int m, int n) {

  vector<vector<int>> t(m, vector<int>(n));

  t[0][0] = grid[0][0];

  for (int i = 1; i < m; i++)
    t[i][0] = t[i - 1][0] + grid[i][0];

  for (int j = 1; j < n; j++)
    t[0][j] = t[0][j - 1] + grid[0][j];

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      t[i][j] = grid[i][j] + min(t[i - 1][j], t[i][j - 1]);
    }
  }

  return t[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &grid) {

  int m = grid.size();
  int n = grid[0].size();

  return find(grid, m, n);
}

int main() {

  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  cout << minPathSum(grid) << endl;

  return 0;
}