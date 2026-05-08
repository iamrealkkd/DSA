#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(vector<int> &coins, int sum)
    {

        int n = coins.size();

        vector<vector<int>> t(n + 1, vector<int>(sum + 1));

        // Initialization
        for (int i = 0; i <= n; i++)
            t[i][0] = 1;

        for (int j = 1; j <= sum; j++)
            t[0][j] = 0;

        // DP
        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][sum];
    }
};

int main()
{
    Solution obj;

    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << obj.count(coins, sum) << endl;

    return 0;
}