
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums, int i, int p) {
        int n = nums.size();

        if (i >= n) {
            return 0;
        }

        int take = 0;

        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + findLength(nums, i + 1, i);
        }

        int skip = findLength(nums, i + 1, p);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        return findLength(nums, 0, -1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution obj;
    cout << obj.lengthOfLIS(nums) << '\n';

    return 0;
}
