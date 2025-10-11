#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Calculate suffix products
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // The final answer is the product of prefix and suffix arrays
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution obj;

    vector<int> result = obj.productExceptSelf(nums);

    cout << "Input array:  {";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl;

    cout << "Output array: {";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "}" << endl;

    return 0;
}
