#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subsetSum(vector<int> &arr, int sum, int n)
    {
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1));

        // Initialization
        for (int i = 0; i <= n; i++)
            t[i][0] = true;

        for (int j = 1; j <= sum; j++)
            t[0][j] = false;

        // DP
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][sum];
    }
};

int main()
{
    vector<int> arr = {2, 3, 7, 8, 10};

    int sum = 11;
    int n = arr.size();

    Solution obj;

    if (obj.subsetSum(arr, sum, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}