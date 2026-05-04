#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
  int t[n + 1][W + 1];

  // initialize
  // n, W ki jgh i and j
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      t[i][j] = 0;
    }
  }

  // DP
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (wt[i - 1] <= j)
      {
        t[i][j] = max(
            val[i - 1] + t[i - 1][j - wt[i - 1]],
            t[i - 1][j]);
      }
      else
      {
        t[i][j] = t[i - 1][j];
      }
    }
  }

  return t[n][W];
}

int main()
{
  int wt[] = {1, 3, 4, 5};
  int val[] = {1, 4, 5, 7};
  int W = 7;
  int n = 4;

  cout << knapsack(wt, val, W, n);
}