#include <bits/stdc++.h>
using namespace std;

int findMinPathSum(vector<vector<int>> &grid, int i, int j, int m, int n) {

  if (i == m - 1 && j == n - 1)
    return grid[i][j];

  if (i == m - 1) {
    return grid[i][j] + findMinPathSum(grid, i, j + 1, m, n);
  } else if (j == n - 1) {
    return grid[i][j] + findMinPathSum(grid, i + 1, j, m, n);
  } else {
    return grid[i][j] + min(findMinPathSum(grid, i + 1, j, m, n),
                            findMinPathSum(grid, i, j + 1, m, n));
  }
}

int main() {

  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  int m = grid.size();
  int n = grid[0].size();

  cout << findMinPathSum(grid, 0, 0, m, n);

  return 0;
}