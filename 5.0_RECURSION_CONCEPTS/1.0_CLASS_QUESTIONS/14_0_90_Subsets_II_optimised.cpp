#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {

        if(i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // include current element
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);
        ans.pop_back();

        // skip duplicates while excluding
        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // exclude current element
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // important step!

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = s.subsetsWithDup(nums);

    cout << "Unique subsets:\n";
    for (auto subset : result) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
