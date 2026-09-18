#include <iostream>
#include <vector>

using namespace std;

int solve(int i, int j, int m, int n, vector<vector<int>> &obstacleGrid) {

  if (i >= m || j >= n)
    return 0;

  if (obstacleGrid[i][j] == 1)
    return 0;

  if (i == m - 1 && j == n - 1)
    return 1;

  return solve(i + 1, j, m, n, obstacleGrid) +
         solve(i, j + 1, m, n, obstacleGrid);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  return solve(0, 0, m, n, obstacleGrid);
}

int main() {

  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  cout << uniquePathsWithObstacles(obstacleGrid);

  return 0;
}