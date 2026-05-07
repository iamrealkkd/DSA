#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int knapsack(vector<int> &wt, vector<int> &val, int W, int n)
  {
    vector<vector<int>> t(n + 1, vector<int>(W + 1));

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
};

int main()
{
  vector<int> wt = {1, 3, 4, 5};
  vector<int> val = {1, 4, 5, 7};

  int W = 7;
  int n = wt.size();

  Solution obj;

  cout << obj.knapsack(wt, val, W, n);

  return 0;
}