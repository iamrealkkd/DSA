#include <bits/stdc++.h>
using namespace std;

class BottomUp {
    int n;

    // O(N) time, O(1) space
    int solveWithTabulation(const vector<int>& nums) {

        // Base case:
        // i == n
        int nextRow_true = 1;
        int nextRow_false = 0;

        for (int i = n - 1; i >= 0; --i) {

            int currRow_true = -1;
            int currRow_false = -1;

            // prevPick = 1
            if (true) {
                int pickInSubarr = nextRow_true;
                int stopHere = 1;

                currRow_true = pickInSubarr + stopHere;
            }

            // prevPick = 0
            {
                int startNewFromCurr = nextRow_true;
                int startNewFromNext = nextRow_false;

                currRow_false =
                    startNewFromCurr + startNewFromNext;
            }

            // Current row becomes next row
            nextRow_true = currRow_true;
            nextRow_false = currRow_false;
        }

        return nextRow_false;
    }

public:
    int countSubarrays(vector<int>& nums) {
        n = nums.size();

        return solveWithTabulation(nums);
    }
};

int main() {

    vector<int> nums = {1, 3, 5, 6};

    BottomUp obj;

    cout << obj.countSubarrays(nums) << endl;

    return 0;
}