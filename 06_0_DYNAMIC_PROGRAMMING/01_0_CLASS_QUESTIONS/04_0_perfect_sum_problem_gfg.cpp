#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));

        // Initialization
        for (int i = 0; i <= n; i++)
            t[i][0] = 1;

        for (int j = 1; j <= target; j++)
            t[0][j] = 0;

        // DP
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][target];
    }
};

int main()
{
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int target = 10;

    Solution obj;
    cout << obj.perfectSum(arr, target);

    return 0;
}