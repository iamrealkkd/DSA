#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> nums, int part)
    {
        int n = nums.size();

        vector<vector<bool>> t(n + 1, vector<bool>(part + 1));

        for (int i = 0; i <= n; i++)
            t[i][0] = true;

        for (int j = 1; j <= part; j++)
            t[0][j] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= part; j++)
            {
                if (nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][part];
    }

    bool canPartition(vector<int> &nums)
    {
        long long sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int part = sum / 2;

        return isSubsetSum(nums, part);
    }
};

int main()
{
    vector<int> nums = {1, 5, 5, 11};

    Solution obj;

    cout << (obj.canPartition(nums) ? "true" : "false");

    return 0;
}