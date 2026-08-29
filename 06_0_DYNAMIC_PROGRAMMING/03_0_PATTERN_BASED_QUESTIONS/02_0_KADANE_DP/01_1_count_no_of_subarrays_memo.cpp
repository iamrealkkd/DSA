#include <bits/stdc++.h>
using namespace std;

class TopDown {
    int n;

    int solveWithMemo(vector<vector<int>>& dp,
                      const vector<int>& nums,
                      int i,
                      bool prevPick) {

        // Base case
        if (i == n) {
            return (prevPick == true) ? 1 : 0;
        }

        // Already calculated
        if (dp[i][prevPick] != -1) {
            return dp[i][prevPick];
        }

        if (prevPick) {

            int pickInSubarr =
                solveWithMemo(dp, nums, i + 1, true);

            int stopHere = 1;

            return dp[i][prevPick] =
                pickInSubarr + stopHere;
        }
        else {

            int startNewFromCurr =
                solveWithMemo(dp, nums, i + 1, true);

            int startNewFromNext =
                solveWithMemo(dp, nums, i + 1, false);

            return dp[i][prevPick] =
                startNewFromCurr + startNewFromNext;
        }
    }

public:
    int countSubarrays(vector<int>& nums) {

        n = nums.size();

        // prevPick = false -> 0
        // prevPick = true  -> 1
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solveWithMemo(dp, nums, 0, false);
    }
};

int main() {

    vector<int> nums = {1, 3 , 5, 6};

    TopDown obj;

    cout << obj.countSubarrays(nums) << endl;

    return 0;
}