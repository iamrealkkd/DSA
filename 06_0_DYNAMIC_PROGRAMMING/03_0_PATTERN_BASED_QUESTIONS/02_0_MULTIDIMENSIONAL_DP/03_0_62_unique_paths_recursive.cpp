#include <iostream>
using namespace std;

int solve(int i, int j, int m, int n) {
  if (i == m - 1 && j == n - 1)
    return 1;

  if (i >= m || j >= n)
    return 0;

  return solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
}

int uniquePaths(int m, int n) { return solve(0, 0, m, n); }

int main() {
  int m = 3;
  int n = 7;

  cout << uniquePaths(m, n);

  return 0;
}