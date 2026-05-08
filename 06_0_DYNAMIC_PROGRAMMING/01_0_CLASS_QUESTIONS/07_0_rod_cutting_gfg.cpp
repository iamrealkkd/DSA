#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();

        vector<int> length;

        // Creating rod lengths: 1,2,3...n
        for (int i = 1; i <= n; i++)
        {
            length.push_back(i);
        }

        int W = n;

        // DP table
        vector<vector<int>> t(n + 1, vector<int>(W + 1));

        // Initialization
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                t[i][j] = 0;
            }
        }

        // Unbounded Knapsack Logic
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {

                if (length[i - 1] <= j)
                {

                    t[i][j] = max(
                        price[i - 1] + t[i][j - length[i - 1]],
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

    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    Solution obj;

    cout << obj.cutRod(price);

    return 0;
}