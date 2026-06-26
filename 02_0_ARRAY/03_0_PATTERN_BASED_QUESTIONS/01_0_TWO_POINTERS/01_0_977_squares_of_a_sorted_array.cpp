#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int l = 0;
        int r = n - 1;
        int i = n - 1;

        while (l <= r) {

            if (abs(nums[l]) > abs(nums[r])) {
                ans[i] = nums[l] * nums[l];
                l++;
            }
            else {
                ans[i] = nums[r] * nums[r];
                r--;
            }

            i--;
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {-7, -3, 2, 3, 11};

    Solution obj;

    vector<int> ans = obj.sortedSquares(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
------------------------------------
Input:
nums = {-7, -3, 2, 3, 11}

Output:
4 9 9 49 121
------------------------------------

Time Complexity:
O(n)

Space Complexity:
O(n)
*/