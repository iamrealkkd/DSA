#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    st.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);

    cout << "\nTriplets whose sum is 0:\n";

    if (ans.empty()) {
        cout << "No triplets found.\n";
    } else {
        for (auto &triplet : ans) {
            cout << "[ ";
            for (int x : triplet) {
                cout << x << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}