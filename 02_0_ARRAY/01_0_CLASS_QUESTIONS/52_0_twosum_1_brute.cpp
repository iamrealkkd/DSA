#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Brute Force: check all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // return indices
                }
            }
        }

        return {}; // no pair found
    }
};

int main() {
    // Example Input
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    // Create object
    Solution s;
    vector<int> result = s.twoSum(nums, target);

    // Output
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
        cout << "Numbers: " << nums[result[0]] << " + " << nums[result[1]] 
             << " = " << target << endl;
    } else {
        cout << "No pair found!" << endl;
    }

    return 0;
}
