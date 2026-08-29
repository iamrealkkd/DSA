#include <bits/stdc++.h>
using namespace std;

class TopDown {
    int n;

    int solveWithoutMemo(const vector<int>& nums, int i, bool prevPick) {
        if (i == n) {
            return (prevPick == true) ? 1 : 0;
        }

        if (prevPick) {
            int pickInSubarr = solveWithoutMemo(nums, i + 1, true);
            int stopHere = 1;

            return pickInSubarr + stopHere;
        }
        else {
            int startNewFromCurr =
                solveWithoutMemo(nums, i + 1, true);

            int startNewFromNext =
                solveWithoutMemo(nums, i + 1, false);

            return startNewFromCurr + startNewFromNext;
        }
    }

public:
    int countSubarrays(vector<int>& nums) {
        n = nums.size();

        return solveWithoutMemo(nums, 0, false);
    }
};

int main() {
    
    vector<int> nums= {1,3,6,8};

    TopDown obj;

    cout << obj.countSubarrays(nums) << endl;
    cout << obj.countSubarrays(nums) << endl;

    return 0;
}