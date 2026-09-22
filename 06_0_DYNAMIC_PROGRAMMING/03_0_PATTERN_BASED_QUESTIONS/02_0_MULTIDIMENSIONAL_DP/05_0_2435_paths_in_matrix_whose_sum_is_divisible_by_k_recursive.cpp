#include <iostream>
#include <vector>
    using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;

  int solve(int i, int j, int m, int n, int k, vector<vector<int>> &grid,
            int sum) {

    if (i >= m || j >= n)
      return 0;

    sum += grid[i][j];

    if ((i == m - 1 && j == n - 1) && sum % k == 0)
      return 1;

    return (solve(i + 1, j, m, n, k, grid, sum) +
            solve(i, j + 1, m, n, k, grid, sum)) %
           MOD;
  }

  int numberOfPaths(vector<vector<int>> &grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int sum = 0;

    return solve(0, 0, m, n, k, grid, sum);
  }
};

int main() {

  vector<vector<int>> grid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};

  int k = 3;

  Solution obj;

  cout << obj.numberOfPaths(grid, k) << endl;

  return 0;
}
