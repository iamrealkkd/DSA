#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];           // moves 1 step
            fast = nums[nums[fast]];     // moves 2 steps
        } while (slow != fast);

        // Phase 2: Find the entry point (duplicate number)
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution obj;
    int ans = obj.findDuplicate(nums);

    cout << "Duplicate Number: " << ans << endl;

    return 0;
}
