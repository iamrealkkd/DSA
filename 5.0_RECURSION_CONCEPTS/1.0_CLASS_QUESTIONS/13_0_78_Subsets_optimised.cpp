#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void allSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& mySubsets) {

        if(i == nums.size()) {
            mySubsets.push_back(ans); // store current subset
            return;
        }

        // include current element
        ans.push_back(nums[i]);
        allSubsets(nums, ans, i + 1, mySubsets);

        // exclude current element
        ans.pop_back();
        allSubsets(nums, ans, i + 1, mySubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> mySubsets;
        vector<int> ans;
        allSubsets(nums, ans, 0, mySubsets);

        return mySubsets;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.subsets(nums);

    cout << "All subsets:\n";
    for (auto subset : result) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
