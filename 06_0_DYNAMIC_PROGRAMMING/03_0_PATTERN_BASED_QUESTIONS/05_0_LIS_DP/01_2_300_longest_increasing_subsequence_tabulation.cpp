
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);
        int mx = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[i], 1 + t[j]);
                    mx = max(mx, t[i]);
                }
            }
        }

        return mx;
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
