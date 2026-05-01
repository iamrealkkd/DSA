#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, -1, 2};
    int k = 3;

    Solution obj;
    int result = obj.subarraySum(nums, k);

    cout << "Total subarrays with sum " << k << " are: " << result << endl;

    return 0;
}
