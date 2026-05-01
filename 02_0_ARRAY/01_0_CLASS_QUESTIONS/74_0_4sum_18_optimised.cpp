#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int p = j+1, q = n-1;

                while(p < q){
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if(sum < tar) p++;
                    else if(sum > tar) q--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;

                        while(p < q && nums[p] == nums[p-1]) p++;
                        while(p < q && nums[q] == nums[q+1]) q--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    int n, target;
    cin >> n >> target;               // Input size & target

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> result = obj.fourSum(nums, target);

    for(auto &quad : result){
        cout << "[ ";
        for(int x : quad){
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
