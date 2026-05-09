#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int sum)
    {
        int n = coins.size();

        vector<vector<int>> t(n + 1, vector<int>(sum + 1));

        // Initialization
        for (int i = 0; i <= n; i++)
            t[i][0] = 0;

        for (int j = 1; j <= sum; j++)
            t[0][j] = INT_MAX - 1;

        // Second row initialization
        for (int j = 1; j <= sum; j++)
        {
            if (j % coins[0] == 0)
                t[1][j] = j / coins[0];
            else
                t[1][j] = INT_MAX - 1;
        }

        // DP
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                {
                    t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        if (t[n][sum] == INT_MAX - 1)
            return -1;

        return t[n][sum];
    }
};

int main()
{
    Solution obj;

    vector<int> coins = {1, 2, 5};
    int sum = 11;

    cout << obj.coinChange(coins, sum);
    return 0;
}