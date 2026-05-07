#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubsetSumDiff(vector<int> &arr, int n)
    {
        int range = 0;

        for (int i = 0; i < n; i++)
            range += arr[i];

        vector<vector<bool>> t(n + 1, vector<bool>(range + 1));

        for (int i = 0; i <= n; i++)
            t[i][0] = true;

        for (int j = 1; j <= range; j++)
            t[0][j] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= range; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        int mn = INT_MAX;

        for (int i = 0; i <= range / 2; i++)
        {
            if (t[n][i])
                mn = min(mn, range - 2 * i);
        }

        return mn;
    }
};

int main()
{
    vector<int> arr = {1, 2, 7};

    int n = arr.size();

    Solution obj;

    cout << obj.minSubsetSumDiff(arr, n);

    return 0;
}